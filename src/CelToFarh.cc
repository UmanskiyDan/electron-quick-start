#include <assert.h>
#include <node_api.h>
#include <stdio.h>


static napi_value CelToFarh(napi_env env, napi_callback_info info) {
  
  napi_status status;

  size_t argc = 1;
  napi_value args[1];

  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);

  if (argc < 1) {
    napi_throw_type_error(env, NULL, "Wrong number of arguments");
    return NULL;
  }

  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  assert(status == napi_ok);

  if (valuetype != napi_number) {
    napi_throw_type_error(env, NULL, "Wrong arguments");
    return NULL;
  }

  double Celcius;
  status = napi_get_value_double(env, args[1], &Celcius);
  assert(status == napi_ok);

  napi_value result;
  status = napi_create_double(env, Celcius*9/5+32, &result);
  assert(status == napi_ok);
  return result;
}

#define DECLARE_NAPI_METHOD(name, func)                 \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor addDescriptor = DECLARE_NAPI_METHOD("CelToFarh", CelToFarh);
  status = napi_define_properties(env, exports, 1, &addDescriptor);
  assert(status == napi_ok);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init);

