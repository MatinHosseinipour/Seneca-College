const { crush } = require('./solutions');

describe('Problem 1 - crush() function', function() {
  test('returns string unmodified if it is already crushed', function() {
    let result = crush('abc');
    expect(result).toBe('abc');
  });

  test('returns string with all lowercase letters', function() {
    let result = crush('ABC');
    expect(result).toBe('abc');
  });

  test('returns string with spaces removed', function() {
    let result = crush(' A B C                ');
    expect(result).toBe('abc');
  });

  test('returns string with dashes removed', function() {
    let result = crush('-A-B-----------------------C---------');
    expect(result).toBe('abc');
  });

  test('returns string with dashes and spaces removed', function() {
    let result = crush(
      '- A- B- - - - - - -       ----- - - - - - -        -----C--              -------'
    );
    expect(result).toBe('abc');
  });
});
