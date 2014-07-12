#include <node.h>
#include <v8.h>
#include <mecab.h>

#include <iostream>

// if (! eval) {
//     const char *e = tagger ? tagger->what() : MeCab::getTaggerError();      
//     std::cerr << "Exception:" << e << std::endl;
//     delete tagger;
//     return -1;
// }

using namespace std;
using namespace v8;

Handle<Value> Method(const Arguments& args) {
    HandleScope scope;

    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }

    String::String::Utf8Value text_utf8(args[0]);

    Local<Array> result = Array::New();
    MeCab::Tagger *tagger = MeCab::createTagger("");
    const MeCab::Node *first = tagger->parseToNode(*text_utf8);
    size_t i = 0;
    for (const MeCab::Node *node = first->next; node->next; node = node->next) {
        // strncpy(buf, node->surface, node->length);
        result->Set(i++, String::New(node->surface, node->length));
    }
    return scope.Close(result);
}

void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("parse"),
                 FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(wakati, init)
