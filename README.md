# node-wakati

npm module for libmecab によるわかち書き

* dependencies
  * mecab
  * 
## USAGE

```javascript
var wakati = require('wakati');
require.parse('太郎は次郎が持っている本を花子に渡した。');
#=> ["太郎", "は", "次郎", "が", "持っ", "て", "いる", "本", "を", "花", "子", "に", "渡し", "た", "。"]
```

