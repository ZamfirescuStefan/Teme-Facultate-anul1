#include <iostream>
#include <random>
#include <fstream>
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
long long nr_max;
int v[10000002], v1[10000002];
int freq[1000000];
void stergere_element ( int v[], int &n, int poz_element )
{
    for ( int i = poz_element; i < n; i ++ )
        v[i] = v[i + 1];
    n--;
}
void inserare_element (int v[], int &n, int element, int poz)
{
    for (int i = n; i >= poz; i-- )
        v[i + 1] = v[i];
    v[poz] = element;
    n++;
}

void InsertionSort(int v[], int &n){
    for ( int i = 1; i < n; i ++ ){
        int j = 0;
        for ( j = 0; j < i; j++ )
            if ( v[i] < v[j])
                break;
        if (j != i ){
            int aux = v[i];
            stergere_element(v,n,i);
            inserare_element(v,n,aux,j);
        }
    }
}
void RadixSort(int v[],int nr)
{
    int pas=0;
    vector <int> bucket[256];
    int max1=0,nr_cifre=0;
    for(int i=0;i<nr;i++)
    {
        if(v[i]>max1)
            max1=v[i];
    }
    while(max1!=0)
    {
        nr_cifre++;
        max1 = max1 / 256;
    }
    for(int k=0;k<nr_cifre;k++)
    {
        for(int i=0;i<nr;i++)
            bucket[(v[i]>>pas) & 255].push_back(v[i]);
        nr=0;
        for(int i=0;i<256;i++)
        {
            for(size_t j=0;j<bucket[i].size();j++)
                v[nr++]=bucket[i][j];
            bucket[i].clear();
        }
        pas= pas + 8 ;
    }
}
void CountSort( int v[], int n){
    for (int i = 0; i < n; i++)
        freq[v[i]]++;
    int index = -1;
    for (int i = 0; i <= nr_max; i++)
        for (int j = 1; j <= freq[i]; j++)
            v[++index] = i;
}
void bubble_sort ( int v[], int n){
    int ok = 1;
    while (ok != 0 ){
        ok = 0;
        for ( int i = 0; i < n - 1; i ++ ){
            if( v[i] > v[i + 1]){
                swap(v[i],v[i + 1]);
                ok = 1;
            }
        }
    }
}
void SelectionSort( int v[], int p ) {
    int aux;
    for (int i = 0; i < p; i++)
        for (int j = i + 1; j < p; j++)
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}
int partitie ( int a[], int start, int end ){
    int poz_pivot = start + rand() % (end - start); // luam pivot random si il mutam pe ultima pozitie
    swap(a[poz_pivot],a[end]);          // in practica merge mai bine cu pivot random decat cu mediana din 3 sau 5
    int pivot = a[end];
    int index = start;
    int t;
    for (int i = start; i < end; i++ ){
        if( a[i] <= pivot ){
            t = a[i];
            a[i] = a[index];
            a[index] = t;
            index ++;
        }
    }
    t = a[end];
    a[end] = a[index];
    a[index] = t;
    return index;
}
void QuickSort(int v[],int start, int end ){
    if ( start < end )
    {
        int mij = partitie(v,start,end);
        QuickSort(v,start,mij - 1);
        QuickSort(v, mij+ 1, end);
    }
}
void interclasare(int v[], int left, int m, int right) {
    int i, j, k, nl, nr;
    nl = m-left+1; nr = right-m;
    int leftv[nl], right_v[nr];
    for(i = 0; i<nl; i++)
        leftv[i] = v[left+i];
    for(j = 0; j<nr; j++)
        right_v[j] = v[m+1+j];
    i = 0; j = 0; k = left;
    while(i < nl && j<nr) {
        if(leftv[i] <= right_v[j]) {
            v[k] = leftv[i];
            i++;
        }else{
            v[k] = right_v[j];
            j++;
        }
        k++;
    }
    while(i<nl) {
        v[k] = leftv[i];
        i++; k++;
    }
    while(j<nr) {
        v[k] = right_v[j];
        j++; k++;
    }
}
void MergeSort(int v[], int left, int right) {
    if(left < right) {
        int m = left+(right-left )/2;
        MergeSort(v, left, m);
        MergeSort(v, m+1, right);
        interclasare(v, left, m, right);
    }
}
void is_sorted ( int v[], int n){
    for ( int i = 0; i < n - 1; i ++ )
        if ( v[i] > v[i + 1])
        {
            g << "Vectorul nu e sortat" << "\n";
            return;
        }
    g << "Vectorul e sortat " <<"\n";
}
void generate_num ( int n, long long nr_max, int v[], int &len)
{
    for ( int i = 0; i < n; i++ )
        v[i] = rand()%nr_max;
    len = n;
}
void MergeS(int v[], int len){
    MergeSort(v,0,len);
}
void QuickS( int v[], int len){
    QuickSort(v,0,len);
}
void InsertionS ( int v[], int n){
    InsertionSort(v,n);
}
void Sortare_c( int v[], int n){
    sort(v,v + n);
}
void tester(void(*f)(int v[], int len), int vct[], int n){
    clock_t start, end;
    start = clock();
    f(vct,n);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    g << "Sortarea s-a facut in : " << fixed << time_taken << setprecision(5) << " sec " << "\n";
    is_sorted(vct,n);
    g << "\n";
}
void copiere(int v1[],int v[], int n)
{
    for ( int i = 0; i < n; i++ )
        v1[i] = v[i];
}
void afisare_vct ( int v[], int n){
    for ( int i = 1; i < n; i ++)
        g << v[i] << " ";
    g << "\n";
}
int main() {
    int n;
    int nr_teste;
    f >> nr_teste;
    for ( int i = 0; i < nr_teste; i ++) {
        int len;
        f >> n >> nr_max;
        g << "      --Testul " << i + 1<<"--" << "\n" << "\n";
        generate_num(n, nr_max, v, len);
        g << "Metoda de sortare este Radix Sort " << "\n";
        copiere(v1,v,len);
        tester(RadixSort, v1, len);

        g << "Metoda de sortare este Quick Sort " << "\n";
        copiere(v1,v,len);
        tester(QuickS,v1,len);

        g << "Metoda de sortare este Merge Sort" << "\n";
        copiere(v1,v,len);
        tester(MergeS,v1,len);

        if( nr_max <= 1000000){
            g << "Metoda de sortare este Count Sort " << "\n";
            copiere(v1,v,len);
            tester(CountSort,v1,len);
        } else{
            g << "Prea mari numerele ca sa le sortam cu Count Sort" << "\n" << "\n";
        }

        if (n <= 30000){
            g << "Metoda de sortare este Bubble Sort " << "\n";
            copiere(v1,v,len);
            tester(bubble_sort,v1,len);
        } else
            g << "Sunt prea multe numere pt a fi sortate cu Bubble Sort" << "\n" << "\n";

        if ( n <= 30000 ){
            g << "Metoda de sortare este Insertions Sort" << "\n";
            copiere(v1,v,len);
            tester(InsertionS,v1,len);
        }
        else
            g << "Prea multe numere ca sa le sortam cu Insertion Sort" << "\n" << "\n";

        if ( n <= 30000 ){
            g << "Metoda de sortare este SelectionSort" << "\n";
            copiere(v1,v,len);
            tester(SelectionSort,v1,len);
        }
        else
            g << "Prea multe numere ca sa le sortam cu Selection Sort" << "\n" << "\n";

        g << "Sortarea implicita din C++ " << "\n";
        copiere(v1,v,len);
        tester(Sortare_c,v1,len);
    }
    g.close();
    f.close();
    return 0;
}
