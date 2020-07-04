
window.onload = function (){
    document.body.style.backgroundImage =  'url(./Photos/Bground.jpg)';
    this.Schimbare_Bground();

}
function Schimbare_Bground(){
    setInterval(function(){
    var Lista_Bground = [ './Photos/Bground.jpg', './Photos/Bground1.jpg', './Photos/Bground2.jpg',];
    var random_number = Math.floor((Math.random() * 10)) % Lista_Bground.length;
    document.body.style.backgroundImage =  'url(' + Lista_Bground[random_number] + ')';
    },5000);
  }
  
function Open_Pagina(){
    var w = window.open();
    var scris = document.createElement("p");
    w.document.write("<p>Eu :))</p>");
    setTimeout(function(){w.close()},2000);
}