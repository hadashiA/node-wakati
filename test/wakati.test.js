var wakati = require('../')
  , expect = require('chai').expect;

describe('wakati', function() {
  it('create array of wakati-gaki', function() {
    expect(wakati.parse('太郎は次郎が持っている本を花子に渡した。')).to.deep.equal([
      "太郎", "は", "次郎", "が", "持っ", "て", "いる", "本", "を", "花", "子", "に", "渡し", "た", "。"]);
  });
});