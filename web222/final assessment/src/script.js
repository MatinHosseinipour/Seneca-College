/* Add any JavaScript you need to this file. */

window.onload = document.getElementById(document).ready(function() {
  document.getElementById(window).scroll(function() {
    var scroll = document.getElementById(window).scrollTop();
    if (scroll > 15) {
      document.getElementById('.navbb').css('background', 'rgba(52, 58, 64, 1)');
    } else {
      document.getElementById('.navbb').css('background', 'rgba(52, 58, 64, 0.5)');
    }
  });
});

window.onload = document.getElementById(document).ready(function() {
  document.getElementById('.img-bx img').mousedown(function(e) {
    e.preventDefault();
    document
      .getElementById('.img_bx-main img')
      .attr('src', document.getElementById(this).attr('src'));
  });
});

function Changepic() {
  var main = document.getElementById('#productImg');
  main.style.url = $(this).style.url;
}

function popup() {
  var x = document.querySelector('.popup');
  x.style.display = 'none';
}
function ValidateEmail(inputText) {
  var valid = false;
  var mailformat = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;
  if (inputText.value.match(mailformat)) {
    alert('Valid email address!');
    valid = true;
  } else {
    alert('You have entered an invalid email address!');
    valid = false;
  }
  return valid;
}
function hideord() {
  var ordernum = document.getElementById('orderNum');
  ordernum.style.visibility = 'hidden';
}
function showord() {
  var ordernum = document.getElementById('orderNum');
  ordernum.style.visibility = 'visible';
}
function setCity(city) {
  var City = document.getElementById('City');
  City.value = city;
}

/*
  var p1 = ["document.querySelector('.devices1')",
"document.querySelector('.devices2')",
document.querySelector('.devices3'),
document.querySelector('.devices4'),
document.querySelector('.devices5'),
document.querySelector('.devices6'),
document.querySelector('.devices7')];
var p2 = ["document.querySelector('.accessories1')",
"document.querySelector('.accessories2')",
document.querySelector('.accessories3'),
document.querySelector('.accessories4')];
var p3 = ["document.querySelector('.other1')"];
*/

function secA(){
  var d1 = document.querySelector('.devices1');
var d2 = document.querySelector('.devices2');
var d3 = document.querySelector('.devices3');
var d4 = document.querySelector('.devices4');
var d5 = document.querySelector('.devices5');
var d6 = document.querySelector('.devices6');
var d7 = document.querySelector('.devices7');
var a1 = document.querySelector('.accessories1');
var a2 = document.querySelector('.accessories2');
var a3 = document.querySelector('.accessories3');
var a4 = document.querySelector('.accessories4');
var o1 = document.querySelector('.other1');
  d1.style.display = 'inline-block';
  d2.style.display = 'inline-block';
  d3.style.display = 'inline-block';
  d4.style.display = 'inline-block';
  d5.style.display = 'inline-block';
  d6.style.display = 'inline-block';
  d7.style.display = 'inline-block';
  a1.style.display = 'none';
  a2.style.display = 'none';
  a3.style.display = 'none';
  a4.style.display = 'none';
  o1.style.display = 'none';
}
function secB(){
  var d1 = document.querySelector('.devices1');
var d2 = document.querySelector('.devices2');
var d3 = document.querySelector('.devices3');
var d4 = document.querySelector('.devices4');
var d5 = document.querySelector('.devices5');
var d6 = document.querySelector('.devices6');
var d7 = document.querySelector('.devices7');
var a1 = document.querySelector('.accessories1');
var a2 = document.querySelector('.accessories2');
var a3 = document.querySelector('.accessories3');
var a4 = document.querySelector('.accessories4');
var o1 = document.querySelector('.other1');
  d1.style.display = 'none';
  d2.style.display = 'none';
  d3.style.display = 'none';
  d4.style.display = 'none';
  d5.style.display = 'none';
  d6.style.display = 'none';
  d7.style.display = 'none';
  a1.style.display = 'inline-block';
  a2.style.display = 'inline-block';
  a3.style.display = 'inline-block';
  a4.style.display = 'inline-block';
  o1.style.display = 'none';
}
function secC(){
  var d1 = document.querySelector('.devices1');
var d2 = document.querySelector('.devices2');
var d3 = document.querySelector('.devices3');
var d4 = document.querySelector('.devices4');
var d5 = document.querySelector('.devices5');
var d6 = document.querySelector('.devices6');
var d7 = document.querySelector('.devices7');
var a1 = document.querySelector('.accessories1');
var a2 = document.querySelector('.accessories2');
var a3 = document.querySelector('.accessories3');
var a4 = document.querySelector('.accessories4');
var o1 = document.querySelector('.other1');
  d1.style.display = 'none';
  d2.style.display = 'none';
  d3.style.display = 'none';
  d4.style.display = 'none';
  d5.style.display = 'none';
  d6.style.display = 'none';
  d7.style.display = 'none';
  a1.style.display = 'none';
  a2.style.display = 'none';
  a3.style.display = 'none';
  a4.style.display = 'none';
  o1.style.display = 'inline-block';
}
function allshow(){
  var d1 = document.querySelector('.devices1');
var d2 = document.querySelector('.devices2');
var d3 = document.querySelector('.devices3');
var d4 = document.querySelector('.devices4');
var d5 = document.querySelector('.devices5');
var d6 = document.querySelector('.devices6');
var d7 = document.querySelector('.devices7');
var a1 = document.querySelector('.accessories1');
var a2 = document.querySelector('.accessories2');
var a3 = document.querySelector('.accessories3');
var a4 = document.querySelector('.accessories4');
var o1 = document.querySelector('.other1');
  d1.style.display = 'inline-block';
  d2.style.display = 'inline-block';
  d3.style.display = 'inline-block';
  d4.style.display = 'inline-block';
  d5.style.display = 'inline-block';
  d6.style.display = 'inline-block';
  d7.style.display = 'inline-block';
  a1.style.display = 'inline-block';
  a2.style.display = 'inline-block';
  a3.style.display = 'inline-block';
  a4.style.display = 'inline-block';
  o1.style.display = 'inline-block';
}
function allhide(){
  var d1 = document.querySelector('.devices1');
var d2 = document.querySelector('.devices2');
var d3 = document.querySelector('.devices3');
var d4 = document.querySelector('.devices4');
var d5 = document.querySelector('.devices5');
var d6 = document.querySelector('.devices6');
var d7 = document.querySelector('.devices7');
var a1 = document.querySelector('.accessories1');
var a2 = document.querySelector('.accessories2');
var a3 = document.querySelector('.accessories3');
var a4 = document.querySelector('.accessories4');
var o1 = document.querySelector('.other1');
  d1.style.display = 'none';
  d2.style.display = 'none';
  d3.style.display = 'none';
  d4.style.display = 'none';
  d5.style.display = 'none';
  d6.style.display = 'none';
  d7.style.display = 'none';
  a1.style.display = 'none';
  a2.style.display = 'none';
  a3.style.display = 'none';
  a4.style.display = 'none';
  o1.style.display = 'none';
}
/*
function hideornot(arr, what){
  for (var i = 0; i < arr.length; i++)
    arr[i].style.display = what;
}
*/
