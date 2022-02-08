const { toDate } = require('./solutions');

describe('Problem 5 - toDate() function', function() {
  // Returns true if two dates have same year, month, day (ignoring time)
  function compareDates(a, b) {
    return (
      a.getFullYear() === b.getFullYear() &&
      a.getMonth() === b.getMonth() &&
      a.getDate() === b.getDate()
    );
  }

  // Checks that a date uses the given year, month, day values
  function assertDate(d, year, month, day) {
    return d.getFullYear() === year && d.getMonth() === month - 1 && d.getDate() === day;
  }

  test('not passing a date string results in current date', function() {
    let now = new Date();
    let result = toDate();
    expect(compareDates(now, result)).toBe(true);
  });

  test('passing a null date string results in current date', function() {
    let now = new Date();
    let result = toDate(null);
    expect(compareDates(now, result)).toBe(true);
  });

  test('passing an empty date string results in current date', function() {
    let now = new Date();
    let result = toDate('');
    expect(compareDates(now, result)).toBe(true);
  });

  test('passing an invalid date string throws an Error', function() {
    // 2-digit year
    expect(() => toDate('20-03-12')).toThrow('invalid date');
    // 1-digit month
    expect(() => toDate('2020-3-12')).toThrow('invalid date');
    // using spaces vs. dashes
    expect(() => toDate('2020 03 12')).toThrow('invalid date');
    // using slashes vs dashes
    expect(() => toDate('2020/03/12')).toThrow('invalid date');
    // string, but not a date string
    expect(() => toDate('invalid string')).toThrow('invalid date');
  });

  test('passing a valid date string results in correct date', function() {
    let result = toDate('2020-03-12');
    expect(assertDate(result, 2020, 3, 12)).toBe(true);
  });
});
