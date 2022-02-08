const { quotePath, quotePaths } = require('./solutions');

describe('Problem 8 - quotePath() and quotePaths() functions', function() {
  describe('quotePath()', function() {
    test('absolute Unix paths without spaces should be unchanged', function() {
      let path = '/a/b/c';
      expect(quotePath(path)).toBe(path);
    });

    test('absolute Unix paths with spaces should be quoted', function() {
      let path = '/a/b /c d';
      expect(quotePath(path)).toBe('"/a/b /c d"');
    });

    test('absolute Windows paths without spaces should be unchanged', function() {
      let path = 'C:\\a\\b\\c';
      expect(quotePath(path)).toBe(path);
    });

    test('absolute Windows paths with spaces should be quoted', function() {
      let path = 'C:\\a\\b \\c d';
      expect(quotePath(path)).toBe('"C:\\a\\b \\c d"');
    });

    test('relative paths without spaces should be unchanged', function() {
      let path = 'a';
      expect(quotePath(path)).toBe(path);
    });

    test('relative paths with spaces should be quoted', function() {
      let path = 'a b';
      expect(quotePath(path)).toBe('"a b"');
    });
  });

  describe('quotePaths()', function() {
    test('passing a single path should work the same as quotePath()', function() {
      expect(quotePaths('a b')).toBe('"a b"');
      expect(quotePaths('ab')).toBe('ab');

      expect(quotePaths('/a/b /c d')).toBe('"/a/b /c d"');
      expect(quotePaths('/a/b/cd')).toBe('/a/b/cd');

      expect(quotePaths('C:\\a\\b \\c d')).toBe('"C:\\a\\b \\c d"');
      expect(quotePaths('C:\\a\\b\\cd')).toBe('C:\\a\\b\\cd');
    });

    test('passing multiple paths should result in a space delimited list of paths', function() {
      expect(quotePaths('a', 'b')).toBe('a b');
      expect(quotePaths('a', 'b')).toBe('a b');
      expect(quotePaths('a', 'b', 'c')).toBe('a b c');
      expect(quotePaths('a', 'b', 'c', 'd')).toBe('a b c d');
    });

    test('passing paths with and without spaces works as expected', function() {
      expect(quotePaths('/a', '/b /c')).toBe('/a "/b /c"');
      expect(quotePaths('./path1', 'C:\\path 2', 'path 3')).toBe('./path1 "C:\\path 2" "path 3"');
    });
  });
});
