# node-wakati

libmecab によるわかち書き

* dependencies
  * mecab

## INSTALL  
  
npm publish not yet...

## USAGE

```javascript
var wakati = require('wakati');
wakati.parse('太郎は次郎が持っている本を花子に渡した。');
//=> ["太郎", "は", "次郎", "が", "持っ", "て", "いる", "本", "を", "花", "子", "に", "渡し", "た", "。"]
```

## TODO

* マルコフ連鎖

