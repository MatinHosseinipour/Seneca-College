/* global countriesData, ui, util */

window.onload = function () {
  /**
   * Register click handlers for every menu item in the page.  Use the objects
   * and functions defined in the other JavaScript files to update/populate
   * the #table-rows table body with the appropriate set of countries, based on the
   * menu item clicked, specifically:
   *
   *  - countriesData array of country data Objects
   *  - util methods for working with the country data
   *  - ui methods for working with the DOM
   *
   * Make sure you also update the #subtitle heading to properly reflect what
   * is in the table after you populate it.
   *
   * For example: "List of Countries and Dependencies - Population between 1 and 2 million"
   * or "List of Countries and Dependencies - All countries in Asia" etc.
   */
  let element = document.getElementById('menu_english');
  element.addEventListener('click', function () {
    let countries = util.countriesByLanguage('English');
    ui.countriesToTable(countries, 'English');
  });
  element = document.getElementById('menu_arabic');
  element.addEventListener('click', function () {
    let countries = util.countriesByLanguage('Arabic');
    ui.countriesToTable(countries, 'Arabic');
  });
  element = document.getElementById('menu_chinese');
  element.addEventListener('click', function () {
    let countries = util.countriesByLanguage('Chinese');
    ui.countriesToTable(countries, 'Chinese');
  });
  element = document.getElementById('menu_french');
  element.addEventListener('click', function () {
    let countries = util.countriesByLanguage('French');
    ui.countriesToTable(countries, 'French');
  });
  element = document.getElementById('menu_hindi');
  element.addEventListener('click', function () {
    let countries = util.countriesByLanguage('Hindi');
    ui.countriesToTable(countries, 'Hindi');
  });
  element = document.getElementById('menu_korean');
  element.addEventListener('click', function () {
    let countries = util.countriesByLanguage('Korean');
    ui.countriesToTable(countries, 'Korean');
  });
  element = document.getElementById('menu_japanese');

  element.addEventListener('click', function () {
    let countries = util.countriesByLanguage('Japanese');
    ui.countriesToTable(countries, 'Japanese');
  });
  element = document.getElementById('menu_russian');
  element.addEventListener('click', function () {
    let countries = util.countriesByLanguage('Russian');
    ui.countriesToTable(countries, 'Russian');
  });

  element = document.getElementById('menu_population_100_000_000m');
  element.addEventListener('click', function () {
    let countries = util.countriesByPopulation(100000000);
    ui.countriesToTable(countries, 'English');
  });

  element = document.getElementById('menu_population_1m_2m');
  element.addEventListener('click', function () {
    let countries = util.countriesByPopulation(1000000, 2000000);
    ui.countriesToTable(countries, 'English');
  });

  element = document.getElementById('menu_americas_1mkm');
  element.addEventListener('click', function () {
    let countries = util.countriesByAreaAndContinent('Americas', 1000000);
    ui.countriesToTable(countries, 'English');
  });

  element = document.getElementById('menu_asia_all');
  element.addEventListener('click', function () {
    let countries = util.countriesByAreaAndContinent('Asia');
    ui.countriesToTable(countries, 'English');
  });
};
