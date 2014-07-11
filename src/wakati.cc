#include <node.h>
#include <v8.h>
#include <mecab.h>

using namespace v8;

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;

  MeCab::Tagger *tagger = MeCab::createTagger("");
  
  return scope.Close(String::New("world"));
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("wakati"),
      FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(wakati, init)
