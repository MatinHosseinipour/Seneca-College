const caseData = require('../toronto-covid-cases-partial.json');
const { getCasesByFSA } = require('./cases');

describe('Problem 02 - getCasesByFSA()', function() {
  test('should include the expected objects for a given FSA value', function() {
    const fsa = 'M6C';
    const casesForFSA = getCasesByFSA(caseData, fsa);

    casesForFSA.forEach(c => {
      expect(typeof c).toBe('object');
      expect(c.FSA).toBe(fsa);
    });
  });

  test('should include the expected objects for a lowercase FSA value', function() {
    const fsaLower = 'm6c';
    const fsaUpper = 'M6C';
    const casesForFSA = getCasesByFSA(caseData, fsaLower);

    casesForFSA.forEach(c => {
      expect(typeof c).toBe('object');
      expect(c.FSA).toBe(fsaUpper);
    });
  });

  test('should skip any cases with a null FSA value', function() {
    const fsa = 'M6C';
    // Use a data set with a single case Object that has a null FSA value
    const data = [
      {
        'Age Group': '20 to 29 Years',
        'Neighbourhood Name': 'Niagara',
        Outcome: 'ACTIVE',
        'Client Gender': 'FEMALE',
        Classification: 'CONFIRMED',
        FSA: null,
        'Currently Hospitalized': 'No',
        'Episode Date': '2020-09-18',
        Assigned_ID: 17703,
        'Outbreak Associated': 'Sporadic',
        'Ever Intubated': 'No',
        'Reported Date': '2020-09-20',
        'Currently in ICU': 'No',
        'Source of Infection': 'Unknown/Missing',
        _id: 161019,
        'Ever in ICU': 'No',
        'Ever Hospitalized': 'No',
        'Currently Intubated': 'No'
      }
    ];
    const casesForFSA = getCasesByFSA(data, fsa);

    expect(Array.isArray(casesForFSA)).toBe(true);
    expect(casesForFSA.length).toBe(0);
  });
});
