const caseData = require('../toronto-covid-cases-partial.json');
const { getCasesByNeighbourhood } = require('./cases');

describe('Problem 05 - getCasesByNeighbourhood() function', function() {
  /**
   * Bug fix: Muath noticed that the tests weren't accounting for number of
   * elements in the resulting array. This corrects that.
   * @param {Array} data - returned array
   * @param {Number} expectedLength - expected length of array
   */
  function expectSuitableArray(data, expectedLength) {
    expect(Array.isArray(data)).toBe(true);
    expect(data.length).toBe(expectedLength);
  }

  test('exact neighbourhood name returns an Array of expected results', function() {
    let neighbourhoodName = 'Niagara';
    let results = getCasesByNeighbourhood(caseData, neighbourhoodName);
    expectSuitableArray(results, 17);
    results.forEach(result => expect(result['Neighbourhood Name']).toBe(neighbourhoodName));
  });

  test('exact neighbourhood name only works if the case is the same', function() {
    let neighbourhoodName = 'niagara';
    let results = getCasesByNeighbourhood(caseData, neighbourhoodName);
    expectSuitableArray(results, 0);
  });

  test('fuzzy neighbourhood name returns an Array of expected results', function() {
    let neighbourhoodName = 'Niagara';
    let results = getCasesByNeighbourhood(caseData, neighbourhoodName, true);
    expectSuitableArray(results, 17);
    results.forEach(result => expect(result['Neighbourhood Name']).toBe(neighbourhoodName));
  });

  test('fuzzy neighbourhood fragment returns an Array of expected results', function() {
    let neighbourhoodName = 'Niagara';
    let results = getCasesByNeighbourhood(caseData, 'gar', true);
    expectSuitableArray(results, 17);
    results.forEach(result => expect(result['Neighbourhood Name']).toBe(neighbourhoodName));
  });

  test('fuzzy neighbourhood fragment with mixed case returns an Array of expected results', function() {
    let neighbourhoodName = 'Niagara';
    let results = getCasesByNeighbourhood(caseData, 'IaGA', true);
    expectSuitableArray(results, 17);
    results.forEach(result => expect(result['Neighbourhood Name']).toBe(neighbourhoodName));
  });

  test('fuzzy neighbourhood fragment with upper case returns an Array of expected results', function() {
    let neighbourhoodName = 'Niagara';
    let results = getCasesByNeighbourhood(caseData, 'IAGA', true);
    expectSuitableArray(results, 17);
    results.forEach(result => expect(result['Neighbourhood Name']).toBe(neighbourhoodName));
  });

  test('fuzzy neighbourhood fragment with lower case returns an Array of expected results', function() {
    let neighbourhoodName = 'Niagara';
    let results = getCasesByNeighbourhood(caseData, 'iaga', true);
    expectSuitableArray(results, 17);
    results.forEach(result => expect(result['Neighbourhood Name']).toBe(neighbourhoodName));
  });
});
