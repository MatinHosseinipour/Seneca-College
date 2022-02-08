const caseData = require('../toronto-covid-cases-partial.json');
const { neighbourhoodInfo, neighbourhoodInfo2 } = require('./cases');

describe('Problem 01 Part 1 - neighbourhoodInfo() function with for loop', function() {
  const originalLog = console.log;

  afterEach(() => {
    console.log = originalLog;
  });

  test('neighbourhoodInfo() should call console.log() once per case', function() {
    let called = 0;
    const mockedLog = () => (called += 1);
    console.log = mockedLog;

    neighbourhoodInfo(caseData);
    expect(called).toBe(caseData.length);
  });

  test('neighbourhoodInfo() should log correct format of all cases', function() {
    let consoleOutput = [];
    const mockedLog = output => consoleOutput.push(output);
    console.log = mockedLog;

    neighbourhoodInfo(caseData);

    consoleOutput.forEach(output =>
      expect(output).toEqual(
        // We expect a string like "Kingsview Village-The Westway (ACTIVE)"
        // which might include special characters.
        expect.stringMatching(/^[a-z- '.()/]+ \(\w+\)$/i)
      )
    );
  });
});

describe('Problem 01 Part 2 - neighbourhoodInfo() function with forEach()', function() {
  const originalLog = console.log;

  afterEach(() => {
    console.log = originalLog;
  });

  test('neighbourhoodInfo() should call console.log() once per case', function() {
    let called = 0;
    const mockedLog = () => (called += 1);
    console.log = mockedLog;

    neighbourhoodInfo2(caseData);
    expect(called).toBe(caseData.length);
  });

  test('neighbourhoodInfo() should log correct format of all cases', function() {
    let consoleOutput = [];
    const mockedLog = output => consoleOutput.push(output);
    console.log = mockedLog;

    neighbourhoodInfo2(caseData);

    consoleOutput.forEach(output =>
      expect(output).toEqual(
        // We expect a string like "Kingsview Village-The Westway (ACTIVE)"
        // which might include special characters.
        expect.stringMatching(/^[a-z- '.()/]+ \(\w+\)$/i)
      )
    );
  });
});
