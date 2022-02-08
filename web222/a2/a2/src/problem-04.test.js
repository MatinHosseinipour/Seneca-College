const caseData = require('../toronto-covid-cases-partial.json');
const { getCasesById } = require('./cases');

describe('Problem 04 - getCasesById() function', function() {
  test('if an unknown id is passed, null is returned', function() {
    expect(getCasesById(caseData, 'no-such-id')).toBe(null);
  });

  test('if a single, known id is passed, the full Object should be returned', function() {
    let id = 161386;
    let result = getCasesById(caseData, id);
    expect(typeof result).toBe('object');
    expect(result._id).toBe(id);
    expect(result['Age Group']).toEqual('40 to 49 Years');
    expect(result['Neighbourhood Name']).toEqual('Banbury-Don Mills');
    expect(result['Outcome']).toEqual('ACTIVE');
    expect(result['Client Gender']).toEqual('MALE');
    expect(result['Classification']).toEqual('CONFIRMED');
    expect(result['FSA']).toEqual('M3C');
    expect(result['Currently Hospitalized']).toEqual('No');
    expect(result['Episode Date']).toEqual('2020-09-14');
    expect(result['Assigned_ID']).toEqual(18070);
    expect(result['Outbreak Associated']).toEqual('Sporadic');
    expect(result['Ever Intubated']).toEqual('No');
    expect(result['Reported Date']).toEqual('2020-09-18');
    expect(result['Currently in ICU']).toEqual('No');
    expect(result['Source of Infection']).toEqual('Community');
    expect(result['_id']).toEqual(161386);
    expect(result['Ever in ICU']).toEqual('No');
    expect(result['Ever Hospitalized']).toEqual('No');
    expect(result['Currently Intubated']).toEqual('No');
  });

  test('if a multiple known ids are passed, an Array of the full Objects should be returned', function() {
    let id1 = 161386;
    let caseForId1 = getCasesById(caseData, id1);
    let id2 = 161387;
    let caseForId2 = getCasesById(caseData, id2);

    let cases = getCasesById(caseData, id1, id2);
    expect(Array.isArray(cases)).toBe(true);
    expect(cases.length).toBe(2);
    expect(cases[0]._id).toEqual(caseForId1._id);
    expect(cases[1]._id).toEqual(caseForId2._id);
  });

  test('if some known and some unknown ids are passed, an Array of the known Objects should be returned', function() {
    let id2 = 161387;
    let caseForId2 = getCasesById(caseData, id2);

    let cases = getCasesById(caseData, 'no-such-id', id2);
    expect(Array.isArray(cases)).toBe(true);
    expect(cases.length).toBe(1);
    expect(cases[0]._id).toEqual(caseForId2._id);
  });
});
