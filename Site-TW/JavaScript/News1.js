window.onload = function(){
    WelcomeUser();
    Timer();
    NumaratoareInversa();
}
var num_clicks = 0;
function modificareContinut(){
    num_clicks++;
    if(num_clicks % 2 != 0){
        var x = document.createElement("p");
       x.innerHTML = "<br>Allview Soul X7 PRO a fost lansat astazi si este primul telefon din portofliul companiei prevazut cu un sistem quad-camera. Impreuna cu proceosorul Qualcomm Snapdragon, poate sustine linistit tehnologia din spatele acestor camere. Ecranul de 6.54″ cu tehnologie LTPS asigura un consum redus de energie, astfel telefonul ofera un echilibru bun intre performanta, calitate si durata de viata a bateriei. ";
        x.setAttribute('id', 'p_adaugat');
        document.getElementById("continut").appendChild(x);
        document.getElementById("citesteMM").innerHTML = "Ascunde paragraf";
    }
    else{
        var x =  document.getElementById("p_adaugat")
        x.parentNode.removeChild(x);
        document.getElementById("citesteMM").innerHTML = "Citeste mai mult";

    }
}

function WelcomeUser(){
    var nume = prompt("Cum te numesti?","Introdu-ti numele");
    if(nume!=null)
    {
        document.title = "Salut, " + nume +"!";
        setTimeout(()=>{document.title = NumeOriginal;},2000);
    }
}

let counter = localStorage.getItem('counter1');
function Timer() 
{
    let timer = setInterval(function() 
    {
        counter++;
        localStorage.setItem('counter1',counter);
        document.getElementById('timer').innerHTML = 'Timp petrecut pe aceasta pagina : ' + counter+'s';
    }, 1000);
}

function NumaratoareInversa(){
// Set the date we're counting down to
var countDownDate = new Date("Jul 18, 2020 00:00:00").getTime();
                
// Update the count down every 1 second
var x = setInterval(function() {

  // Get today's date and time
  var now = new Date().getTime();
    
  // Find the distance between now and the count down date
  var distance = countDownDate - now;
    
  // Time calculations for days, hours, minutes and seconds
  var days = Math.floor(distance / (1000 * 60 * 60 * 24));
  var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
  var seconds = Math.floor((distance % (1000 * 60)) / 1000);
    
  // Output the result in an element with id="demo"
  document.getElementById("demo").innerHTML = days + " zile " + hours + " ore "
  + minutes + " minute " + seconds + " secunde ";
    
  // If the count down is over, write some text 
  if (distance < 0) {
    clearInterval(x);
    document.getElementById("demo").innerHTML = "La Multi Ani 2020!";
  }
}, 1000);}