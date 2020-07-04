window.onload = function(){
  Show_Hidden_Title();
  Timer();
  functieDeIdle();
}


function Display_Txt_File() {
    var request = new XMLHttpRequest();
    request.onreadystatechange = function() {
      if (this.status == 200  && this.readyState == 4) {
        if(typeof Display_Txt_File.status== 'undefined'){
        var x = this.responseText;
        var elem = document.createElement("p");
        elem.innerHTML = x;
        document.getElementById("continut").appendChild(elem);
        Display_Txt_File.status = 1;
      }

    }
    };
    request.open("GET", "Paragraf_text.txt", true);
    request.send();
}

function myFunction(imgs) {
    var expandImg = document.getElementById("expandedImg");
    expandImg.src = imgs.src;
    expandImg.parentElement.style.display = "block";
  }

function Change_Background(){
  var Lista_Bground = [ './Photos/Bground.jpg', './Photos/Bground1.jpg', './Photos/Bground2.jpg'];
    var random_number = Math.floor((Math.random() * 10000)) % Lista_Bground.length;
  var item = document.getElementById("bd");
  item.style.backgroundImage = 'url(' + Lista_Bground[random_number] + ')';
  // item.style.backgroundImage = 'url(Bground1.jpg)';

}

/// Trenzitie titlu 
function Show_Hidden_Title(){
  var i = 0;
  var j = 0;
  var element = document.getElementById("title");
  var text = "Tech News";
  var leng_text = text.length;
  var leng_div_2= element.innerHTML.length/2;
  var interval = setInterval(function(){   
      element.innerHTML = element.innerHTML.slice(0,leng_div_2) + text[i]+text[leng_text-1-i]+element.innerHTML.slice(leng_div_2);
      leng_div_2= element.innerHTML.length/2;
      i++;

      if (text.length%2==1 && i == Math.floor(text.length/2)){
        element.innerHTML = element.innerHTML.slice(0, leng_div_2) + text[Math.floor(text.length/2)] + element.innerHTML.slice(leng_div_2);
      }

      if (i+1 > text.length/2){
          clearInterval(interval);
      }
  
  }, 500);
}
var nr=5;
let timer = setInterval(function() 
{
    nr++;
    document.getElementById("Text_alert").innerHTML="Esti inactiv de "+nr+" secunde";
}, 1000);

function functieDeIdle() {
var timp = 5000;
function toggleLaClasa() {
document.getElementById("OverLay").classList.toggle("overlay");
document.getElementById("OverWord").classList.toggle("overlayOnText");
document.getElementById("Text_alert").innerHTML="Esti inactiv de "+nr+" secunde";
}; 
var timeout = -1; 
cronometru(); // cronometru

function cronometru() {
    document.addEventListener("mousemove", stareActiva); // on activity reseteaza time-out-ul
    document.addEventListener("keypress", stareActiva);
    timeout = setTimeout(stareInactiva, timp); // daca timpul expira
}
function stareActiva() {
    nr=5;
    document.removeEventListener("mousemove", stareActiva); 
    document.removeEventListener("keypress", stareActiva);
    //scoatem evenimentele, altfel am face recursie infinita
    // pe functie onActivity si scoate din performanta ( putem vedea pe consola)
    if (timeout==-1) toggleLaClasa(); //, aici intra daca functia a pus deja overlay-ul si il scoate
    else clearTimeout(timeout); //, daca nu s-a pus overlay doar reseteaza timpul, ca se poata
    // puna overlay daca in viitor nu se fac miscari. Daca nu ar fi else-ul, o sa intre chiar daca
    // nu e inactivitate pe onExpires;
    cronometru();
}
function stareInactiva() {
nr=5;
toggleLaClasa();
timeout = -1;
}
};
let counter = localStorage.getItem('counter');
function Timer() 
{
    let timer = setInterval(function() 
    {
        counter++;
        localStorage.setItem('counter',counter);
        var text = document.getElementById('timer').innerHTML = 'Timp petrecut pe aceasta pagina : ' + counter+'s';
        

    }, 1000);
}
