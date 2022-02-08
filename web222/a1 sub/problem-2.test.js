const { createEmailAddress } = require('./solutions');

describe('Problem 2 - createEmailAddress() function', function() {
  test('email address is correct for regular names and host', function() {
    let firstName = 'Jeff';
    let lastName = 'Sickel';
    let host = 'myseneca.ca';
    let result = createEmailAddress(firstName, lastName, host);
    expect(result).toBe('Jeff Sickel <jsickel@myseneca.ca>');
  });

  test('email address is correct for regular names and missing host (defaults to gmail.com)', function() {
    let firstName = 'Jeff';
    let lastName = 'Sickel';
    let result = createEmailAddress(firstName, lastName);
    expect(result).toBe('Jeff Sickel <jsickel@gmail.com>');
  });

  test('email address is correct for names with spaces', function() {
    let firstName = 'Mary Lou';
    let lastName = 'Jordan Roberts';
    let result = createEmailAddress(firstName, lastName);
    expect(result).toBe('Mary Lou Jordan Roberts <mjordanroberts@gmail.com>');
  });

  test('email address is correct for names with dashes', function() {
    let firstName = 'Mary-Lou';
    let lastName = 'Jordan-Roberts';
    let result = createEmailAddress(firstName, lastName);
    expect(result).toBe('Mary-Lou Jordan-Roberts <mjordanroberts@gmail.com>');
  });
});
