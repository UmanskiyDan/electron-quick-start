#include "FahrToCel.h"

using namespace std;
double FahrToCel::calc(double fahrenheit){
 return ((fahrenheit - 32) * 5/9);
}

Napi::Number FahrToCel::addWrapped(const Napi::CallbackInfo& info){
 Napi::Env env = info.Env();

 //convert javascripts datatype to c++
 Napi::Number first = info[0].As<Napi::Number>();
//run c++ function return value and return it in javascript
 Napi::Number returnValue = Napi::Number::New(env, example::calc(first.NumberValue()));

 return returnValue;
}
Napi::Object example::Init(Napi::Env env, Napi::Object exports)
{
  //export Napi function
  exports.Set("calc", Napi::Function::New(env, example::addWrapped));
  return exports;
}
