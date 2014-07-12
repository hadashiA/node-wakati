#include <node.h>
#include <v8.h>
#include <mecab.h>

#include <iostream>

using namespace std;
using namespace v8;

Handle<Value> Method(const Arguments& args) {
    HandleScope scope;

    if (args.length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }

    String::Utf8Value utf8Text(args[0]);
    cout << utf8Text << endl;

    // MeCab::Tagger *tagger = MeCab::createTagger("");
  
    return scope.Close(String::New("world"));
}

void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("wakati"),
                 FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(wakati, init)
