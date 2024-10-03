#ifndef C_SHIKAFX_EXTRAS_UTILS
#define C_SHIKAFX_EXTRAS_UTILS


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdio.h>
#include <stdlib.h>
#include "./common.h"

// TLDR: wnt with meaning of `with null terminate`

char* copy_char_stack_func(const char* buff, size_t size);
char* copy_char_stack_wnt_func(const char* buff, size_t size);

byte_t* copy_byte_stack_func(const byte_t* buff, size_t size);
byte_t* copy_byte_stack_wnt_func(const byte_t* buff, size_t size);

const data_t* copy_byte_stack_to_data_func(const byte_t* buff, size_t size);
const data_t* copy_data_func(const data_t* data);

// extra files
#include "./utils/quicksort.h"
#include "./utils/mergesort.h"
#include "./utils/sort.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_UTILS
