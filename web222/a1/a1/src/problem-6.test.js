const { simpleMovingAverage } = require('./solutions');

describe('Problem 6 - simpleMovingAverage() function', function() {
  test('correct average for a set of integer Numbers', function() {
    let result = simpleMovingAverage(20, 22, 24, 25, 23);
    expect(result).toEqual(22.8);
  });

  test('correct average for a set of integer Numbers formatted as Strings', function() {
    let result = simpleMovingAverage('20', '22', '24', '25', '23');
    expect(result).toEqual(22.8);
  });

  test('correct average for a mix of Numbers and Strings', function() {
    let result = simpleMovingAverage('20', 22, '24', 25, '23');
    expect(result).toEqual(22.8);
  });

  test('correct average for a single number', function() {
    let result = simpleMovingAverage(20);
    expect(result).toEqual(20);
  });

  test('correct average for Numbers with decimals', function() {
    let result = simpleMovingAverage(20.345, 22.125, 24.1, 25, 23.0);
    expect(result).toBeCloseTo(22.914);
  });

  test('passing an empty string argument throws an Error', function() {
    expect(() => simpleMovingAverage('', 1)).toThrowError('invalid argument');
  });

  test('passing a boolean argument throws an Error', function() {
    expect(() => simpleMovingAverage(false, 1)).toThrowError('invalid argument');
    expect(() => simpleMovingAverage(true, 1)).toThrowError('invalid argument');
  });

  test('passing a non-numeric String argument throws an Error', function() {
    expect(() => simpleMovingAverage('invalid', 1)).toThrowError('invalid argument');
  });
});
