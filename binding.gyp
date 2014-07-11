{
  "targets": [
    {
      "target_name": "wakati",
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "sources": [ "src/wakati.cc" ]
    }
  ]
}
