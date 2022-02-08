var p1 = document.querySelector('.sectionA');
var p2 = document.querySelector('.sectionB');
var p3 = document.querySelector('.sectionC');
function secA(){
    p1.style.display = 'inline-block';
    p2.style.display = 'none';
    p3.style.display = 'none';
}
function secB(){
    p1.style.display = 'none';
    p2.style.display = 'inline-block';
    p3.style.display = 'none';
}
function secC(){
    p1.style.display = 'none';
    p2.style.display = 'none';
    p3.style.display = 'inline-block';
}
function allshow(){
    p1.style.display = 'inline-block';
    p2.style.display = 'inline-block';
    p3.style.display = 'inline-block';
}