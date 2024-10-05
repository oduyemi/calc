#include <nan.h>

void Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  double value1 = info[0]->NumberValue(Nan::GetCurrentContext()).FromJust();
  double value2 = info[1]->NumberValue(Nan::GetCurrentContext()).FromJust();
  v8::Local<v8::Number> num = Nan::New(value1 + value2);

  info.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("add").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Add)->GetFunction(Nan::GetCurrentContext()).ToLocalChecked());
}

NODE_MODULE(binding, Init)
