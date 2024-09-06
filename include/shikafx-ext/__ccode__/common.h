#ifndef C_SHIKAFX_EXTRAS_COMMON
#define C_SHIKAFX_EXTRAS_COMMON

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "./commons/typed_nums.h"

typedef unsigned char byte_t;
typedef unsigned int uint_t;
//typedef long int int32_t;
//typedef unsigned long int uint32_t;
//typedef long long int int64_t;
//typedef unsigned long long int uint64_t;

static const char* ASCII_UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const int ASCII_UPPERCASE_SIZE = 26;

static const char* ASCII_LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
static const int ASCII_LOWERCASE_SIZE = 26;

static const char* DIGITS = "0123456789";
static const int DIGITS_SIZE = 10;

static const char* ASCII_PUNCTUATION = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
static const int ASCII_PUNCTUATION_SIZE = 32;

static const char* ASCII_DRAWABLE = "0123456789" "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
static const int ASCII_DRAWABLE_SIZE = 94;

static const char* ASCII_WHITESPACES = " \t\n\r\x0b\x0c";
static const int ASCII_WHITESPACES_SIZE = 6;

static const char* ASCII_PRINTABLE = "0123456789" "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~" " \t\n\r\x0b\x0c";
static const int ASCII_PRINTABLE_SIZE = 100;

bool is_ascii_drawable(byte_t chr);

bool is_ascii_printable(byte_t chr);

char* create_char_stack(size_t size);

void drop_char_stack(const char* data);

byte_t* create_byte_stack(size_t size);

void drop_byte_stack(const byte_t* data);

typedef struct {
    const byte_t* data;
    size_t size;
} data_t;

data_t* create_data(const byte_t* data, size_t size);

void drop_data(const data_t* data, bool drop_field);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMON
