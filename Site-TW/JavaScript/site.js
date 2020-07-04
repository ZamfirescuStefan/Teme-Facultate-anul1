
window.onload = function (){
  this.megachestie();
  // this.Schimbare_Bground();
}

function myFunction(imgs) {
    var expandImg = document.getElementById("expandedImg");
    expandImg.src = imgs.src;
    expandImg.parentElement.style.display = "block";
  }

function Change_Background(){
  var Lista_Bground = [ 'Bground.jpg', '../Photos/Bground1.jpg', '../Photos/Bground2.jpg'];
  
  var random_number = Math.floor((Math.random() * 1000)) % Lista_Bground.length;
  var item = document.getElementById("bd");
  item.style.backgroundImage = 'url(' + Lista_Bground[random_number] + ')';
  alert("hello");

  
  
}
function SchimbaculoareR(){
   var list = document.getElementById("content");
  localStorage.setItem("culoare","red");
  megachestie();
}

function SchimbaculoareB(){
  var list = document.getElementById("content");
  localStorage.setItem("culoare","blue");
  megachestie();
}

function SchimbaculoareG(){
  var list = document.getElementById("content");
  localStorage.setItem("culoare","green");
  megachestie();
}

addEventListener("click",function SchimbaculoareBlack(){
  var list = document.getElementById("content");
  localStorage.setItem("culoare","black");
  megachestie();
},true);

function megachestie(){
  var list = document.getElementById("content");
  list.style.color = localStorage.getItem("culoare");
}



function Changecursor(){
  document.getElementById("1").style.cursor = "pointer";
  document.getElementById("2").style.cursor = "pointer";
  document.getElementById("3").style.cursor = "pointer";
  document.getElementById("4").style.cursor = "pointer";
  document.getElementsByClassName("dropdown-content").style.cursor = "pointer";
  
}

// QUIZ QUIZ QUIZ QUIZ QUIZ QUIZ QUIZ QUIZ QUIZ QUIZ 


function Quiz(questions) {
  this.score = 0;
  this.questions = questions;
  this.questionIndex = 0;
}

function Question(text, choices, answer) {
  this.text = text;
  this.choices = choices;
  this.answer = answer;
}

Quiz.prototype.getQuestionIndex = function() {
  return this.questions[this.questionIndex];
}

Quiz.prototype.guess = function(answer) {
  if(this.getQuestionIndex().isCorrectAnswer(answer)) {
      this.score++;
  }

  this.questionIndex++;
}

Quiz.prototype.isEnded = function() {
  return this.questionIndex === this.questions.length;
}

Question.prototype.isCorrectAnswer = function(choice) {
  return this.answer === choice;
}

function populate() {
  if(quiz.isEnded()) {
      showScores();
  }
  else {
     
     document.getElementById("question").innerHTML = quiz.getQuestionIndex().text;

      var choices = quiz.getQuestionIndex().choices;
      for(var i = 0; i < choices.length; i++) {
          var element = document.getElementById("choice" + i);
          element.innerHTML = choices[i];
          guess("btn" + i, choices[i]);
      }

      showProgress();
  }
};


function guess(id, guess) {
  var button = document.getElementById(id);
  button.onclick = function() {
      quiz.guess(guess);
      populate();
  }
};


function showProgress() {
  var currentQuestionNumber = quiz.questionIndex + 1;
  var element = document.getElementById("progress");
  element.innerHTML = "Intrebarea " + currentQuestionNumber + " din " + quiz.questions.length;
};

function showScores() {
  var gameOverHTML = "<h1>Rezultat:</h1>";
  gameOverHTML += "<h2 id='score'> Scorul tau: " + quiz.score + "</h2>";
  var element = document.getElementById("quiz");
  element.innerHTML = gameOverHTML;
};


var questions = [
  new Question("In ce an a fost fondata compania Apple?", ["1976", "1986","1996", "1998"], "1976"),
  new Question("Sloganul carui iPhone este: Bigger than bigger ?", ["iPhone X", "iPhone XS MAX", "iPhone 6S", "iPhone 11"], "iPhone 6S"),
  new Question("In ce an a aparut pe piata primul iPad?", ["2005", "2008","2009", "2010"], "2010"),
  new Question("Ce a afirmat compania Apple la lansarea MacBook Air?", ["Este cel mai subtire laptop din lume.", "Este cel mai puternic device creat de Apple pana la acest moment.", "Va fi produsul cu cea mai mare cifra de vanzari.", "Este dispozitivul ce revolutioneaza tehnologia."], "Este cel mai subtire laptop din lume."),
  new Question("Fondatorul/Fondatorii Apple...", ["Steve Jobs și Steve Wozniack", "Steve Jobs", "Steve Jobs, Steve Wozniack și Ronald Wayne", "Steve Jobs, Steve Wozniack și Martin Eberhard"], "Steve Jobs, Steve Wozniack și Ronald Wayne")
];


var quiz = new Quiz(questions);


populate(); 

 
function ages()
{
    var x=document.getElementById("date").value;
    var y=x.split("#")
    var d1=new Date();
    var d2=new Date(y[1]+"/"+y[0]+"/"+y[2]);
    var diff = d1.getTime() - d2.getTime();
    var years=Math.floor(diff / (1000 * 60 * 60 * 24 * 365.25));
    var months=Math.floor(diff%(1000*60*60*24*365.25)/(1000 * 60 * 60 * 24*30));
    var days = Math.floor(diff %(1000 * 60 * 60 * 24)/(1000*60*60));
    var hours = Math.floor((diff % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    var minutes = Math.floor((diff % (1000 * 60 * 60)) / (1000 * 60));
    var seconds = Math.floor((diff % (1000 * 60)) / 1000);
    document.getElementById("age").innerHTML="Vârsta dumneavoastră este: "+years+" ani "+months+" luni si "+days+" zile, "+hours +" ore "+minutes+" minute "+seconds+" secunde!";
    setTimeout(ages, 1000);
}

function InversareLista(){
  let multime = document.getElementById("lista");
  let element = multime.getElementsByTagName("li");
  for(var i = element.length-1; i >= 0; --i) 
    multime.appendChild(element[i]);
}