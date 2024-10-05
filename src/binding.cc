#include <nan.h>

void Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    // Check the number of arguments
    if (info.Length() < 2) {
        Nan::ThrowTypeError("Two arguments required");
        return;
    }

    // Ensure arguments are numbers
    if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
        Nan::ThrowTypeError("Both arguments must be numbers");
        return;
    }

    double value1 = info[0]->NumberValue(Nan::GetCurrentContext()).FromJust();
    double value2 = info[1]->NumberValue(Nan::GetCurrentContext()).FromJust();
    v8::Local<v8::Number> num = Nan::New(value1 + value2);

    info.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
    // Get the current context
    v8::Local<v8::Context> context = Nan::GetCurrentContext();

    // Set the 'add' function in the exports object
    exports->Set(context, Nan::New("add").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(Add)->GetFunction(context).ToLocalChecked()).FromJust();
}

NODE_MODULE(binding, Init)
