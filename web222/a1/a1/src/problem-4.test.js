const { ageToRange } = require('./solutions');

describe('Problem 4 - ageToRange() function', function() {
  test('negative ages throw an Error', function() {
    expect(() => ageToRange(-1)).toThrow('invalid age');
  });

  // Automatically generate tests for all values between a lower and upper bound.
  // Use the provided range string for comparison, or provide a standard one.
  function generateTestsForRange(lower, upper, range) {
    range = range || `${lower} to ${upper} Years`;

    test(`ages ${lower} to ${upper} result in ${range}`, function() {
      for (let i = lower; i <= upper; i++) {
        expect(ageToRange(i)).toBe(range);
      }
    });
  }

  generateTestsForRange(0, 19, '19 and younger');
  generateTestsForRange(20, 29);
  generateTestsForRange(30, 39);
  generateTestsForRange(40, 49);
  generateTestsForRange(50, 59);
  generateTestsForRange(60, 69);
  generateTestsForRange(70, 79);
  generateTestsForRange(80, 89);
  generateTestsForRange(90, 124, '90 and older');
});
