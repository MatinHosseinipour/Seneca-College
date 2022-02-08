const { formatQS, containsID } = require('./solutions');

describe('Problem 10 - formatQS() and containsID() functions', function() {
  describe('formatQS()', function() {
    test('id without neighbourhood should produce correct query string', function() {
      let result = formatQS(12345);
      expect(result).toBe('?id=12345');
    });

    test('id with neighbourhood should produce correct query string', function() {
      let result = formatQS(12345, 'neighbourhood');
      expect(result).toBe('?id=12345&n=neighbourhood');
    });

    test('neighbourhood with spaces should be encoded in query string', function() {
      let result = formatQS(12345, 'Islington-City Centre West');
      expect(result).toBe('?id=12345&n=Islington-City%20Centre%20West');
    });

    test('neighbourhood with special characters should be encoded in query string', function() {
      let result = formatQS(12345, 'a!@#$%^&*()_+');
      expect(result).toBe('?id=12345&n=a!%40%23%24%25%5E%26*()_%2B');
    });
  });

  describe('containsID()', function() {
    test('query string with id should return true', function() {
      let id = 123451234;
      let qs = formatQS(id);
      let result = containsID(id, qs);
      expect(result).toBe(true);
    });

    test('query string without id should return false', function() {
      let result = containsID(2, '?id=1');
      expect(result).toBe(false);
    });

    test('query string with correct id and neighbourhood should return true', function() {
      let id = 123451234;
      let qs = formatQS(id, 'neighbourhood string');
      let result = containsID(id, qs);
      expect(result).toBe(true);
    });

    test('query string with only partial id and neighbourhood should return false', function() {
      let id = 100000;
      let qs = formatQS(id, 'neighbourhood string');
      let result = containsID(10, qs);
      expect(result).toBe(false);
    });

    test('query string with only partial id should return false', function() {
      let id = 100000;
      let qs = formatQS(id);
      let result = containsID(10, qs);
      expect(result).toBe(false);
    });
  });
});

/**
  'Willowdale East',
  'Parkwoods-Donalda',
  'Church-Yonge Corridor',
  'Newtonbrook West',
  'Milliken',
  'Willowdale West',
  'Henry Farm',
  'Don Valley Village',
  'Lawrence Park South',
  'Bridle Path-Sunnybrook-York Mills',
  'Moss Park',
  'Annex',
  'Westminster-Branson',
  'Leaside-Bennington',
  null,
  'St.Andrew-Windfields',
  'Malvern',
  'Bedford Park-Nortown',
  'High Park North',
  'Waterfront Communities-The Island',
  'Mimico (includes Humber Bay Shores)',
  'Danforth-East York',
  'Princess-Rosethorn',
  'Roncesvalles',
  'Long Branch',
  'Dovercourt-Wallace Emerson-Junction',
  'Mount Pleasant West',
  'Oakwood Village',
  'South Parkdale',
  'Mount Pleasant East',
  'North Riverdale',
  'Eringate-Centennial-West Deane',
  'Palmerston-Little Italy',
  'Stonegate-Queensway',
  'Rouge',
  'Agincourt South-Malvern West',
  'Englemount-Lawrence',
  'Forest Hill North',
  'New Toronto',
  'West Humber-Clairville',
  'Casa Loma',
  'Niagara',
  'High Park-Swansea',
  'Downsview-Roding-CFB',
  'Kensington-Chinatown',
  'Trinity-Bellwoods',
  'Kennedy Park',
  'Victoria Village',
  'The Beaches',
  'Woodbine-Lumsden',
  'Newtonbrook East',
  "L'Amoreaux",
  'Banbury-Don Mills',
  'Caledonia-Fairbank',
  'Willowridge-Martingrove-Richview',
  'Yonge-St.Clair',
  'Bayview Woods-Steeles',
  "O'Connor-Parkview",
  'Clairlea-Birchmount',
  'Bay Street Corridor',
  'Forest Hill South',
  'Flemingdon Park',
  'Yonge-Eglinton',
  'Little Portugal',
  'Greenwood-Coxwell',
  'Rosedale-Moore Park',
  'Guildwood',
  'Junction Area',
  'Dorset Park',
  'Edenbridge-Humber Valley',
  'Bendale',
  'East End-Danforth',
  'Playter Estates-Danforth',
  'University',
  'Wychwood',
  'Cliffcrest',
  'Danforth',
  'Lansing-Westgate',
  'Clanton Park',
  'Eglinton East',
  'Humewood-Cedarvale',
  'Glenfield-Jane Heights',
  'Lawrence Park North',
  'Cabbagetown-South St. James Town',
  'Highland Creek',
  'Woburn',
  'South Riverdale',
  'Morningside',
  'West Hill',
  'Etobicoke West Mall',
  'Agincourt North',
  'Markland Wood',
  'Runnymede-Bloor West Village',
  'Taylor-Massey',
  'Steeles',
  'Blake-Jones',
  'Black Creek',
  'Woodbine Corridor',
  'Thistletown-Beaumond Heights',
  'Islington-City Centre West',
  'Wexford/Maryvale',
  'Elms-Old Rexdale',
  'North St. James Town',
  'Dufferin Grove',
  'Humber Summit',
  'Birchcliffe-Cliffside',
  'Kingsway South',
  'Bathurst Manor',
  "Tam O'Shanter-Sullivan",
  'Mount Olive-Silverstone-Jamestown',
  'Rockcliffe-Smythe',
  'Scarborough Village',
  'Keelesdale-Eglinton West',
  'Centennial Scarborough',
  'Weston-Pellam Park',
  'York University Heights',
  'Broadview North',
  'Maple Leaf',
  'Yorkdale-Glen Park',
  'Humbermede',
  'Mount Dennis',
  'Weston',
  'Thorncliffe Park',
  'Bayview Village',
  'Pleasant View',
  'Brookhaven-Amesbury',
  'Ionview',
  'Corso Italia-Davenport',
  'Rexdale-Kipling',
  'Beechborough-Greenbrook',
  'Kingsview Village-The Westway',
  'Oakridge',
  'Briar Hill - Belgravia',
  'Pelmo Park-Humberlea',
  'Lambton Baby Point',
  'Humber Heights-Westmount',
  'Rustic',
  'Hillcrest Village',
  'Alderwood',
  'Old East York',
  'Regent Park'
 */
