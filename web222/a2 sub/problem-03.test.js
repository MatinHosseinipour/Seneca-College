const caseData = require('../toronto-covid-cases-partial.json');
const { transformCase, transformCases, transformCases2 } = require('./cases');

const createSample = () => ({
  'Age Group': '20 to 29 Years',
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

describe('Problem 03 - transformCase(), transformCases(), transformCases2() functions', function() {
  describe('transformCase() function', function() {
    let sample;

    beforeEach(() => {
      sample = createSample();
    });

    test('should return an Object', function() {
      let result = transformCase(sample);
      expect(typeof result).toBe('object');
    });

    test('should return an Object containing an id property', function() {
      let result = transformCase(sample);
      expect(result.id).toBe(sample._id);
    });

    test('should return an Object containing an isActive property', function() {
      sample.Outcome = 'RESOLVED';
      let resolvedResult = transformCase(sample);
      expect(resolvedResult.isActive).toBe(false);

      sample.Outcome = 'ACTIVE';
      let activeResult = transformCase(sample);
      expect(activeResult.isActive).toBe(true);
    });

    test('should return an Object containing a neighbourhood property', function() {
      let result = transformCase(sample);
      expect(result.neighbourhood).toBe(sample['Neighbourhood Name']);
    });

    test('should return an Object containing a hospitalInfo property', function() {
      let result = transformCase(sample);
      expect(typeof result.hospitalInfo).toBe('object');
    });

    test('should return an Object containing a hospitalInfo.current property', function() {
      let result = transformCase(sample);
      expect(typeof result.hospitalInfo.current).toBe('object');
    });

    test('should return an Object containing correct hospitalInfo.current data', function() {
      sample['Currently Hospitalized'] = 'Yes';
      expect(transformCase(sample).hospitalInfo.current.hospitalized).toBe(true);
      sample['Currently Hospitalized'] = 'No';
      expect(transformCase(sample).hospitalInfo.current.hospitalized).toBe(false);

      sample['Currently in ICU'] = 'Yes';
      expect(transformCase(sample).hospitalInfo.current.inICU).toBe(true);
      sample['Currently in ICU'] = 'No';
      expect(transformCase(sample).hospitalInfo.current.inICU).toBe(false);

      sample['Currently Intubated'] = 'Yes';
      expect(transformCase(sample).hospitalInfo.current.intubated).toBe(true);
      sample['Currently Intubated'] = 'No';
      expect(transformCase(sample).hospitalInfo.current.intubated).toBe(false);
    });

    test('should return an Object containing a hospitalInfo.historical property', function() {
      let result = transformCase(sample);
      expect(typeof result.hospitalInfo.historical).toBe('object');
    });

    test('should return an Object containing correct hospitalInfo.historical data', function() {
      sample['Ever Hospitalized'] = 'Yes';
      expect(transformCase(sample).hospitalInfo.historical.hospitalized).toBe(true);
      sample['Ever Hospitalized'] = 'No';
      expect(transformCase(sample).hospitalInfo.historical.hospitalized).toBe(false);

      sample['Ever in ICU'] = 'Yes';
      expect(transformCase(sample).hospitalInfo.historical.inICU).toBe(true);
      sample['Ever in ICU'] = 'No';
      expect(transformCase(sample).hospitalInfo.historical.inICU).toBe(false);

      sample['Ever Intubated'] = 'Yes';
      expect(transformCase(sample).hospitalInfo.historical.intubated).toBe(true);
      sample['Ever Intubated'] = 'No';
      expect(transformCase(sample).hospitalInfo.historical.intubated).toBe(false);
    });
  });

  describe('transformCases() function', function() {
    let sample, samples;

    beforeEach(() => {
      sample = createSample();
      samples = [sample];
    });

    test('should return an Array', function() {
      let result = transformCases(caseData);
      expect(Array.isArray(result)).toBe(true);
    });

    test('should return a new Array', function() {
      let result = transformCases(caseData);
      expect(result).not.toBe(caseData);
    });

    test('should return an Array with the same number of elements', function() {
      let result = transformCases(caseData);
      expect(result.length).toBe(caseData.length);
    });

    test('should return an Array of Objects', function() {
      let result = transformCases(caseData);
      result.forEach(o => expect(typeof o).toBe('object'));
    });

    test('should return an Array with Objects containing an id property', function() {
      let result = transformCases(samples);
      expect(result[0].id).toBe(samples[0]._id);
    });

    test('should return an Array with Objects containing an isActive property', function() {
      sample.Outcome = 'RESOLVED';
      let resolvedResult = transformCases(samples);
      expect(resolvedResult[0].isActive).toBe(false);

      sample.Outcome = 'ACTIVE';
      let activeResult = transformCases(samples);
      expect(activeResult[0].isActive).toBe(true);
    });

    test('should return an Array with Objects containing a neighbourhood property', function() {
      let result = transformCases(samples);
      expect(result[0].neighbourhood).toBe(samples[0]['Neighbourhood Name']);
    });

    test('should return an Array with Objects containing a hospitalInfo property', function() {
      let result = transformCases(samples);
      expect(typeof result[0].hospitalInfo).toBe('object');
    });

    test('should return an Array with Objects containing a hospitalInfo.current property', function() {
      let result = transformCases(samples);
      expect(typeof result[0].hospitalInfo.current).toBe('object');
    });

    test('should return an Array with Objects containing correct hospitalInfo.current data', function() {
      sample['Currently Hospitalized'] = 'Yes';
      expect(transformCases(samples)[0].hospitalInfo.current.hospitalized).toBe(true);
      sample['Currently Hospitalized'] = 'No';
      expect(transformCases(samples)[0].hospitalInfo.current.hospitalized).toBe(false);

      sample['Currently in ICU'] = 'Yes';
      expect(transformCases(samples)[0].hospitalInfo.current.inICU).toBe(true);
      sample['Currently in ICU'] = 'No';
      expect(transformCases(samples)[0].hospitalInfo.current.inICU).toBe(false);

      sample['Currently Intubated'] = 'Yes';
      expect(transformCases(samples)[0].hospitalInfo.current.intubated).toBe(true);
      sample['Currently Intubated'] = 'No';
      expect(transformCases(samples)[0].hospitalInfo.current.intubated).toBe(false);
    });

    test('should return an Array with Objects containing a hospitalInfo.historical property', function() {
      let result = transformCases(samples);
      expect(typeof result[0].hospitalInfo.historical).toBe('object');
    });

    test('should return an Array with Objects containing correct hospitalInfo.historical data', function() {
      sample['Ever Hospitalized'] = 'Yes';
      expect(transformCases(samples)[0].hospitalInfo.historical.hospitalized).toBe(true);
      sample['Ever Hospitalized'] = 'No';
      expect(transformCases(samples)[0].hospitalInfo.historical.hospitalized).toBe(false);

      sample['Ever in ICU'] = 'Yes';
      expect(transformCases(samples)[0].hospitalInfo.historical.inICU).toBe(true);
      sample['Ever in ICU'] = 'No';
      expect(transformCases(samples)[0].hospitalInfo.historical.inICU).toBe(false);

      sample['Ever Intubated'] = 'Yes';
      expect(transformCases(samples)[0].hospitalInfo.historical.intubated).toBe(true);
      sample['Ever Intubated'] = 'No';
      expect(transformCases(samples)[0].hospitalInfo.historical.intubated).toBe(false);
    });
  });

  describe('transformCases2() function', function() {
    let sample, samples;

    beforeEach(() => {
      sample = createSample();
      samples = [sample];
    });

    test('should return an Array', function() {
      let result = transformCases2(caseData);
      expect(Array.isArray(result)).toBe(true);
    });

    test('should return a new Array', function() {
      let result = transformCases2(caseData);
      expect(result).not.toBe(caseData);
    });

    test('should return an Array with the same number of elements', function() {
      let result = transformCases2(caseData);
      expect(result.length).toBe(caseData.length);
    });

    test('should return an Array of Objects', function() {
      let result = transformCases2(caseData);
      result.forEach(o => expect(typeof o).toBe('object'));
    });

    test('should return an Array with Objects containing an id property', function() {
      let result = transformCases2(samples);
      expect(result[0].id).toBe(samples[0]._id);
    });

    test('should return an Array with Objects containing an isActive property', function() {
      sample.Outcome = 'RESOLVED';
      let resolvedResult = transformCases2(samples);
      expect(resolvedResult[0].isActive).toBe(false);

      sample.Outcome = 'ACTIVE';
      let activeResult = transformCases2(samples);
      expect(activeResult[0].isActive).toBe(true);
    });

    test('should return an Array with Objects containing a neighbourhood property', function() {
      let result = transformCases2(samples);
      expect(result[0].neighbourhood).toBe(samples[0]['Neighbourhood Name']);
    });

    test('should return an Array with Objects containing a hospitalInfo property', function() {
      let result = transformCases2(samples);
      expect(typeof result[0].hospitalInfo).toBe('object');
    });

    test('should return an Array with Objects containing a hospitalInfo.current property', function() {
      let result = transformCases2(samples);
      expect(typeof result[0].hospitalInfo.current).toBe('object');
    });

    test('should return an Array with Objects containing correct hospitalInfo.current data', function() {
      sample['Currently Hospitalized'] = 'Yes';
      expect(transformCases2(samples)[0].hospitalInfo.current.hospitalized).toBe(true);
      sample['Currently Hospitalized'] = 'No';
      expect(transformCases2(samples)[0].hospitalInfo.current.hospitalized).toBe(false);

      sample['Currently in ICU'] = 'Yes';
      expect(transformCases2(samples)[0].hospitalInfo.current.inICU).toBe(true);
      sample['Currently in ICU'] = 'No';
      expect(transformCases2(samples)[0].hospitalInfo.current.inICU).toBe(false);

      sample['Currently Intubated'] = 'Yes';
      expect(transformCases2(samples)[0].hospitalInfo.current.intubated).toBe(true);
      sample['Currently Intubated'] = 'No';
      expect(transformCases2(samples)[0].hospitalInfo.current.intubated).toBe(false);
    });

    test('should return an Array with Objects containing a hospitalInfo.historical property', function() {
      let result = transformCases2(samples);
      expect(typeof result[0].hospitalInfo.historical).toBe('object');
    });

    test('should return an Array with Objects containing correct hospitalInfo.historical data', function() {
      sample['Ever Hospitalized'] = 'Yes';
      expect(transformCases2(samples)[0].hospitalInfo.historical.hospitalized).toBe(true);
      sample['Ever Hospitalized'] = 'No';
      expect(transformCases2(samples)[0].hospitalInfo.historical.hospitalized).toBe(false);

      sample['Ever in ICU'] = 'Yes';
      expect(transformCases2(samples)[0].hospitalInfo.historical.inICU).toBe(true);
      sample['Ever in ICU'] = 'No';
      expect(transformCases2(samples)[0].hospitalInfo.historical.inICU).toBe(false);

      sample['Ever Intubated'] = 'Yes';
      expect(transformCases2(samples)[0].hospitalInfo.historical.intubated).toBe(true);
      sample['Ever Intubated'] = 'No';
      expect(transformCases2(samples)[0].hospitalInfo.historical.intubated).toBe(false);
    });
  });
});
