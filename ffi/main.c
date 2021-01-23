#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <ffi.h>

int main() {
  /* ffi_cif cif; */
  /* ffi_type *args[1]; */
  /* void *values[1]; */
  /* char *s; */
  /* ffi_arg rc; */

  /* args[0] = &ffi_type_pointer; */
  /* values[0] = &s; */

  /* if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 1, &ffi_type_sint, args) == FFI_OK) { */
  /*   s = "Hello World!"; */
  /*   ffi_call(&cif, puts, &rc, values); */
  /*   s = "This is cool!"; */
  /*   ffi_call(&cif, puts, &rc, values); */
  /* } */

  void* handle = dlopen("./libsample.dylib", RTLD_LAZY);
  if (handle == NULL) {
    printf("error dlopen");
    exit(1);
  }
  void* fn = dlsym(handle, "add");
  if (fn == NULL) {
    printf("error dlsym");
    exit(1);
  }

  // argument type
  ffi_type* args[] = {&ffi_type_sint, &ffi_type_sint};

  ffi_cif cif;
  ffi_status status = ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 2, &ffi_type_sint, args);
  if (status != FFI_OK) {
    printf("error ffi");
    exit(1);
  }

  int a = 3;
  int b = 4;
  int value1 = a;
  int value2 = b;
  void* values[] = {&value1, &value2};
  int result;
  ffi_call(&cif, FFI_FN(fn), &result, values);
  printf("%d + %d = %d\n", a, b, result);
  printf("arg1: %d, arg2: %d\n", value1, value2);
  
  return 0;
}
