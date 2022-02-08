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
/*
function changepic() {
  var main = document.getElementById('#productImg');
  main.src = $(this).src;
}
*/
