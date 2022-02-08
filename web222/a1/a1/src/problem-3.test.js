const { extractFSA } = require('./solutions');

describe('Problem 3 - extractFSA() function', function() {
  test('valid FSA from valid postal codes', function() {
    // King Campus
    expect(extractFSA('L7B 1B3')).toBe('L7B');
    // Markham Campus
    expect(extractFSA('L3R 5Y1')).toBe('L3R');
    // Newnham Campus
    expect(extractFSA('M2J 2X5')).toBe('M2J');
  });

  test('should throw an Error if there are not enough letters', function() {
    expect(() => extractFSA('L')).toThrowError('invalid FSA');
    expect(() => extractFSA('L7')).toThrowError('invalid FSA');
  });

  test('invalid FSA should throw an Error if first letter is invalid', function() {
    // Can't start with a D
    expect(() => extractFSA('D7B 1B3')).toThrowError('invalid FSA');
    // Can't start with an F
    expect(() => extractFSA('F7B 1B3')).toThrowError('invalid FSA');
    // Can't start with a I
    expect(() => extractFSA('I7B 1B3')).toThrowError('invalid FSA');
    // Can't start with an O
    expect(() => extractFSA('O7B 1B3')).toThrowError('invalid FSA');
    // Can't start with a Q
    expect(() => extractFSA('Q7B 1B3')).toThrowError('invalid FSA');
    // Can't start with a U
    expect(() => extractFSA('U7B 1B3')).toThrowError('invalid FSA');
    // Can't start with a W
    expect(() => extractFSA('W7B 1B3')).toThrowError('invalid FSA');
  });

  test('invalid FSA should throw an Error if second character is not a number', function() {
    // Can't have letter in second position
    expect(() => extractFSA('LAB 1B3')).toThrowError('invalid FSA');
    // Can't have space in second position
    expect(() => extractFSA('L B 1B3')).toThrowError('invalid FSA');
    // Can't have . in second position
    expect(() => extractFSA('L.B 1B3')).toThrowError('invalid FSA');
  });

  test('invalid FSA should throw an Error if third character is not a letter', function() {
    // Can't have a number in third position
    expect(() => extractFSA('L79 1B3')).toThrowError('invalid FSA');
    // Can't have space in second position
    expect(() => extractFSA('L7  1B3')).toThrowError('invalid FSA');
    // Can't have . in second position
    expect(() => extractFSA('L7. 1B3')).toThrowError('invalid FSA');
  });
});
