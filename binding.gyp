{
  "targets": [
    {
      "target_name": "wakati",
      "include_dirs": [
        "<!@(mecab-config --inc-dir)",
        "<!(node -e \"require('nan')\")"
      ],
      "sources": [ "src/wakati.cc" ],
      "libraries": [
        '<!@(mecab-config --libs)'
      ]
    }
  ]
}