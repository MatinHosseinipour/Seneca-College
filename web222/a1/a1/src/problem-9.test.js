const { normalizeBoolean, allTrue, allFalse } = require('./solutions');

describe('Problem 9 - normalizeBoolean(), allTrue(), allFalse() functions', function() {
  describe('normalizeBoolean()', function() {
    test('pure boolean values work as expected', function() {
      expect(normalizeBoolean(true)).toBe(true);
      expect(normalizeBoolean(false)).toBe(false);
    });

    test('various forms of Yes should return true', function() {
      expect(normalizeBoolean('Yes')).toBe(true);
      expect(normalizeBoolean('yes')).toBe(true);
      expect(normalizeBoolean('YES')).toBe(true);
      expect(normalizeBoolean('YeS')).toBe(true);
      expect(normalizeBoolean('YEs')).toBe(true);
      expect(normalizeBoolean('Y')).toBe(true);
      expect(normalizeBoolean('y')).toBe(true);
    });

    test('various forms of No should return false', function() {
      expect(normalizeBoolean('No')).toBe(false);
      expect(normalizeBoolean('no')).toBe(false);
      expect(normalizeBoolean('nO')).toBe(false);
      expect(normalizeBoolean('n')).toBe(false);
      expect(normalizeBoolean('N')).toBe(false);
    });

    test('various forms of True should return true', function() {
      expect(normalizeBoolean('True')).toBe(true);
      expect(normalizeBoolean('true')).toBe(true);
      expect(normalizeBoolean('TRUE')).toBe(true);
      expect(normalizeBoolean('TruE')).toBe(true);
      expect(normalizeBoolean('TRuE')).toBe(true);
      expect(normalizeBoolean('TRue')).toBe(true);
      expect(normalizeBoolean('trUE')).toBe(true);
      expect(normalizeBoolean('truE')).toBe(true);
      expect(normalizeBoolean('t')).toBe(true);
      expect(normalizeBoolean('T')).toBe(true);
    });

    test('various forms of False should return false', function() {
      expect(normalizeBoolean('False')).toBe(false);
      expect(normalizeBoolean('false')).toBe(false);
      expect(normalizeBoolean('FALSE')).toBe(false);
      expect(normalizeBoolean('FALSe')).toBe(false);
      expect(normalizeBoolean('FALSe')).toBe(false);
      expect(normalizeBoolean('FALse')).toBe(false);
      expect(normalizeBoolean('FAlse')).toBe(false);
      expect(normalizeBoolean('falsE')).toBe(false);
      expect(normalizeBoolean('falSE')).toBe(false);
      expect(normalizeBoolean('faLSE')).toBe(false);
      expect(normalizeBoolean('fALSE')).toBe(false);
      expect(normalizeBoolean('f')).toBe(false);
      expect(normalizeBoolean('F')).toBe(false);
    });

    test('the number 1 should be true', function() {
      expect(normalizeBoolean(1)).toBe(true);
    });
    test('the number -1 should be false', function() {
      expect(normalizeBoolean(-1)).toBe(false);
    });

    test('various non-values should be false', function() {
      expect(normalizeBoolean(undefined)).toBe(false);
      expect(normalizeBoolean()).toBe(false);
      expect(normalizeBoolean(null)).toBe(false);
      expect(normalizeBoolean(NaN)).toBe(false);
    });
  });

  describe('allTrue()', function() {
    test('lists of normalized true values results in true', function() {
      expect(allTrue('Yes', 'yes', 'YES', 'Y', 't', 'TRUE', true, 'True', 1)).toBe(true);
    });

    test('lists of mostly normalized true values results in false', function() {
      expect(allTrue('Yes', 'yes', 'YES', 'Y', 't', 'TRUE', true, 'True', 1)).toBe(true);
      // Last value switched to false
      expect(allTrue('Yes', 'yes', 'YES', 'Y', 't', 'TRUE', true, 'True', 0)).toBe(false);
    });
  });

  describe('allFalse()', function() {
    test('lists of normalized false values results in true', function() {
      expect(
        allFalse('No', 'no', 'NO', 'N', 'n', 'f', 'FALSE', false, 'False', 0, null, undefined, -1)
      ).toBe(true);
    });

    test('lists of mostly normalized false values results in false', function() {
      expect(
        allFalse('No', 'no', 'NO', 'N', 'n', 'f', 'FALSE', false, 'False', 0, null, undefined, -1)
      ).toBe(true);
      // Last value switched to true
      expect(
        allFalse('No', 'no', 'NO', 'N', 'n', 'f', 'FALSE', false, 'False', 0, null, undefined, 1)
      ).toBe(false);
    });
  });
});
