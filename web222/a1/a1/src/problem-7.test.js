const { mimeFromExt } = require('./solutions');

describe('Problem 7 - mimeFromExt() function', function() {
  test('correct mime type for HTML extensions with and without leading `.`', function() {
    expect(mimeFromExt('.html')).toEqual('text/html');
    expect(mimeFromExt('.htm')).toEqual('text/html');

    expect(mimeFromExt('html')).toEqual('text/html');
    expect(mimeFromExt('htm')).toEqual('text/html');
  });

  test('correct mime type for CSS extension with and without leading `.`', function() {
    expect(mimeFromExt('.css')).toEqual('text/css');
    expect(mimeFromExt('css')).toEqual('text/css');
  });

  test('correct mime type for JS extension with and without leading `.`', function() {
    expect(mimeFromExt('.js')).toEqual('text/javascript');
    expect(mimeFromExt('js')).toEqual('text/javascript');
  });

  test('correct mime type for JPEG extensions with and without leading `.`', function() {
    expect(mimeFromExt('.jpg')).toEqual('image/jpeg');
    expect(mimeFromExt('jpg')).toEqual('image/jpeg');

    expect(mimeFromExt('.jpeg')).toEqual('image/jpeg');
    expect(mimeFromExt('jpeg')).toEqual('image/jpeg');
  });

  test('correct mime type for GIF extension with and without leading `.`', function() {
    expect(mimeFromExt('.gif')).toEqual('image/gif');
    expect(mimeFromExt('gif')).toEqual('image/gif');
  });

  test('correct mime type for BMP extension with and without leading `.`', function() {
    expect(mimeFromExt('.bmp')).toEqual('image/bmp');
    expect(mimeFromExt('bmp')).toEqual('image/bmp');
  });

  test('correct mime type for Icon extensions with and without leading `.`', function() {
    expect(mimeFromExt('.ico')).toEqual('image/x-icon');
    expect(mimeFromExt('ico')).toEqual('image/x-icon');

    expect(mimeFromExt('.cur')).toEqual('image/x-icon');
    expect(mimeFromExt('cur')).toEqual('image/x-icon');
  });

  test('correct mime type for PNG extension with and without leading `.`', function() {
    expect(mimeFromExt('.png')).toEqual('image/png');
    expect(mimeFromExt('png')).toEqual('image/png');
  });

  test('correct mime type for SVG extension with and without leading `.`', function() {
    expect(mimeFromExt('.svg')).toEqual('image/svg+xml');
    expect(mimeFromExt('svg')).toEqual('image/svg+xml');
  });

  test('correct mime type for WEBP extension with and without leading `.`', function() {
    expect(mimeFromExt('.webp')).toEqual('image/webp');
    expect(mimeFromExt('webp')).toEqual('image/webp');
  });

  test('correct mime type for MP3 extension with and without leading `.`', function() {
    expect(mimeFromExt('.mp3')).toEqual('audio/mp3');
    expect(mimeFromExt('mp3')).toEqual('audio/mp3');
  });

  test('correct mime type for WAV extension with and without leading `.`', function() {
    expect(mimeFromExt('.wav')).toEqual('audio/wav');
    expect(mimeFromExt('wav')).toEqual('audio/wav');
  });

  test('correct mime type for MP4 extension with and without leading `.`', function() {
    expect(mimeFromExt('.mp4')).toEqual('video/mp4');
    expect(mimeFromExt('mp4')).toEqual('video/mp4');
  });

  test('correct mime type for WEBM extension with and without leading `.`', function() {
    expect(mimeFromExt('.webm')).toEqual('video/webm');
    expect(mimeFromExt('webm')).toEqual('video/webm');
  });

  test('correct mime type for JSON extension with and without leading `.`', function() {
    expect(mimeFromExt('.json')).toEqual('application/json');
    expect(mimeFromExt('json')).toEqual('application/json');
  });

  test('correct mime type for unknown extensions', function() {
    expect(mimeFromExt('.exe')).toEqual('application/octet-stream');
    expect(mimeFromExt('exe')).toEqual('application/octet-stream');
    expect(mimeFromExt('.dll')).toEqual('application/octet-stream');
    expect(mimeFromExt('dll')).toEqual('application/octet-stream');
    expect(mimeFromExt('.xht')).toEqual('application/octet-stream');
    expect(mimeFromExt('xht')).toEqual('application/octet-stream');
    expect(mimeFromExt('.m')).toEqual('application/octet-stream');
    expect(mimeFromExt('m')).toEqual('application/octet-stream');
  });
});
