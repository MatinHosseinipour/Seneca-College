const caseData = require('../toronto-covid-cases-partial.json');
const { firstId } = require('./cases');

describe('Problem 00 - firstId() function', function() {
  test('firstId() should return the correct _id', function() {
    /**
     * Take a look at the file `toronto-covid-cases-partial.json`.
     * The first Case Object in the Array looks like this:
     *
     *   {
     *     "Age Group": "20 to 29 Years",
     *     "Neighbourhood Name": "Niagara",
     *     "Outcome": "ACTIVE",
     *     "Client Gender": "FEMALE",
     *     "Classification": "CONFIRMED",
     *     "FSA": "M6K",
     *     "Currently Hospitalized": "No",
     *     "Episode Date": "2020-09-18",
     *     "Assigned_ID": 17703,
     *     "Outbreak Associated": "Sporadic",
     *     "Ever Intubated": "No",
     *     "Reported Date": "2020-09-20",
     *     "Currently in ICU": "No",
     *     "Source of Infection": "Unknown/Missing",
     *     "_id": 161019,
     *     "Ever in ICU": "No",
     *     "Ever Hospitalized": "No",
     *     "Currently Intubated": "No"
     *   },
     *
     * Notice that the _id is 161019. That's what our test expects to receive.
     */

    expect(firstId(caseData)).toBe(161019);
  });

  test('firstId() should return a Number', function() {
    /**
     * We also expect that our value should be of type Number
     */

    expect(typeof firstId(caseData)).toBe('number');
  });
});
