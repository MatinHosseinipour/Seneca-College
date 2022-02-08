/**
 * WEB222 – Assignment 02
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name: Matin Hosseini Pour
 *      Student ID: smmhosseini-pour
 *      Date: 19th oct 2020
 *
 * Please finish working on cases.js BEFORE you start this problem.
 */

/*******************************************************************************
 * Part 2: using our cases functions to write an analysis program.
 *
 * Welcome to Assignment 2 Part II! In this second part of the assignment, you're
 * going to be using the functions you wrote in cases.js to create a simple
 * command line program that can do analysis on COVID cases in Toronto.
 *
 * This time, we won't use unit tests.  Instead, you will be asked to use
 * the functions you already wrote (and know are working thanks to the tests)
 * to complete the following program.
 *
 * This program allows the user to do an analysis of case data for FSA,
 * Neighbourhood, or all data.  The user decides how much data to analyze by
 * including command line arguments
 *
 * To see an analysis of all data, you would do:
 *
 *    npm run analyze
 *
 * To see an analysis of the MJ6 forward sortation area (FSA), you would do:
 *
 *    npm run analyze -- --fsa="MJ6"
 *
 * To see an analysis of the data with 'park' in the Neighbourhood Name, you would do:
 *
 *    npm run analyze -- --neighbourhood="park"
 *
 * Most of the program is written below, but it needs you to fix the parts that
 * are indicated with TODO in the comments.
 *
 *  - getCasesByFSA()
 *  - getCasesByNeighbourhood()
 *  - getAgeGroupSummary()
 *
 * They have been included below from `cases.js`, so you don't need to rewrite them.
 ******************************************************************************/

// We include the functions we wrote in cases.js so we can use them here
const { getCasesByFSA, getCasesByNeighbourhood, getAgeGroupSummary } = require('./cases');

// We'll use the https://yargs.js.org/ package to deal with command line arguments
const { argv } = require('yargs');
const { format } = require('prettier');

/**
 * TODO: given a number like 0.07335496866606983 return a formatted string with
 * percent: 7.34%.  Use https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Number/toFixed
 * If number is null/undefined, return '0' instead.
 */
function formatAsPercentage(number) {
  number = Number.parseFloat(number).toFixed(2);
  return number;
}

/**
 * TODO: given a number like 1311, return a formatted string with commas: 1,311
 * Use https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Intl/NumberFormat
 * and the en-CA locale.
 */
function formatNumber(number) {
  number = new Intl.NumberFormat('en-IN', { maximumSignificantDigits: 3 }).format(number);
  return number;
}

function loadCaseData() {
  console.log('Loading data...');
  // We need to import the case data from `toronto-covid-cases-full.json`
  return require('../toronto-covid-cases-full.json');
}

function analyzeData(data) {
  console.log('Analyzing data...');

  if (argv.fsa) {
    console.log(`Using FSA='${argv.fsa}' to limit the data`);
    // TODO: return the cases by FSA using your getCasesByFSA function...
    data = getCasesByFSA(argv.fsa);
    return data;
  }

  if (argv.neighbourhood) {
    console.log(`Using Neighbourhood='${argv.neighbourhood}' with a fuzzy match to limit the data`);
    // TODO: return the cases by Neighbourhood using your getCasesByNeighbourhood function and a fuzzy match...
    data = getCasesByNeighbourhood(allCases, argv.neighbourhood, true);
    return data;
  }

  console.log('Using all case data');
  return data;
}

function summarizeData(data) {
  const summary = getAgeGroupSummary(data);

  console.log('\nSummary');
  console.log('--------------------------');

  Object.keys(summary).forEach(ageGroup => {
    // TODO: print a line to the console that looks like this "20 to 29 Years 45 (14.29%)"
    // Use the formatNumber() and formatAsPercentage() functions to format the
    // total and percent value for this age group.
    let total = formatNumber(ageGroup.total);
    let percent = formatAsPercentage(ageGroup.percent);
    console.log(`${ageGroup} ` + total + ' (' + percent + ')');
  });

  console.log('--------------------------');
}

function main() {
  const allCases = loadCaseData();
  const data = analyzeData(allCases);
  summarizeData(data);
}

main();
