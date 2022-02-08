const caseData = require('../toronto-covid-cases-partial.json');
const { getAgeGroupSummary } = require('./cases');

const createSample = ageGroup => ({
  'Age Group': ageGroup,
  'Neighbourhood Name': 'Humewood-Cedarvale',
  Outcome: 'ACTIVE',
  'Client Gender': 'FEMALE',
  Classification: 'CONFIRMED',
  FSA: 'M6C',
  'Currently Hospitalized': 'No',
  'Episode Date': '2020-09-11',
  Assigned_ID: 17704,
  'Outbreak Associated': 'Sporadic',
  'Ever Intubated': 'No',
  'Reported Date': '2020-09-18',
  'Currently in ICU': 'No',
  'Source of Infection': 'Close contact',
  _id: 161020,
  'Ever in ICU': 'No',
  'Ever Hospitalized': 'No',
  'Currently Intubated': 'No'
});

describe('Problem 06 - getAgeGroupSummary() function', function() {
  // Checks for the correct structure and properties of each expected age group
  expect.extend({
    toBeAgeGroupSummary(o) {
      let pass = true;

      if (typeof o !== 'object') pass = false;

      [
        'Unknown',
        '19 and younger',
        '20 to 29 Years',
        '30 to 39 Years',
        '40 to 49 Years',
        '50 to 59 Years',
        '60 to 69 Years',
        '70 to 79 Years',
        '80 to 89 Years',
        '90 and older'
      ].forEach(ageCategory => {
        if (typeof o[ageCategory] !== 'object') pass = false;
        if (typeof o[ageCategory].total !== 'number') pass = false;
        if (typeof o[ageCategory].percent !== 'number') pass = false;
      });

      return {
        pass,
        message: `Expected ${o} to be a valid age group summar object`
      };
    }
  });

  test('should return an Object with the right layout', function() {
    let result = getAgeGroupSummary(caseData);
    expect(result).toBeAgeGroupSummary();
  });

  [
    'Unknown',
    '19 and younger',
    '20 to 29 Years',
    '30 to 39 Years',
    '40 to 49 Years',
    '50 to 59 Years',
    '60 to 69 Years',
    '70 to 79 Years',
    '80 to 89 Years',
    '90 and older'
  ].forEach(ageCategory => {
    test(`should include a '${ageCategory}' category with correct info`, function() {
      let data = [createSample(ageCategory), createSample(ageCategory), createSample(ageCategory)];
      let result = getAgeGroupSummary(data);
      let category = result[ageCategory];
      expect(category.total).toBe(3);
      expect(category.percent).toBe(1);
    });
  });

  test('should properly calculate percents', function() {
    let data = [
      createSample('19 and younger'),
      createSample('19 and younger'),
      createSample('20 to 29 Years'),
      createSample('20 to 29 Years')
    ];
    let result = getAgeGroupSummary(data);
    expect(result['19 and younger'].total).toBe(2);
    expect(result['19 and younger'].percent).toBe(0.5);
    expect(result['20 to 29 Years'].total).toBe(2);
    expect(result['20 to 29 Years'].percent).toBe(0.5);
  });
});
