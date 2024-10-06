#ifndef C_SHIKAFX_EXTRAS_BASE64_CUSTOM
#define C_SHIKAFX_EXTRAS_BASE64_CUSTOM

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "./common.h"
#include "./utils.h"

static const char* BASE64_CHARACTERS;
static const int BASE64_CHARACTERS_SIZE = 64;
static const char BASE64_PADDING = '=';

typedef struct {
    const char* data;
    size_t size;
    int pads;
} base64_data_t;

base64_data_t* create_base64_data(const char* val, size_t size, int pads);
void drop_base64_data(const base64_data_t* base64_data, bool drop_field);

typedef struct {
    size_t size;
    int pads;
} base64_calc_size_t;

base64_calc_size_t* create_base64_calc_size(size_t size, int pads);
void drop_base64_calc_size(const base64_calc_size_t* base64_calc_size);

base64_calc_size_t* base64_encoding_calc_size_func(size_t size);
base64_calc_size_t* base64_decoding_calc_size_func(size_t size);

base64_data_t* base64_encode_func(const data_t* data);
const data_t* base64_decode_func(const base64_data_t* base64_data);

const data_t* base64_data_to_ascii_cvt_func(const base64_data_t* data, bool padding);
base64_data_t* ascii_to_base64_data_cvt_func(const char* val, size_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_BASE64_CUSTOM
