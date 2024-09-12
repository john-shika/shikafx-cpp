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

static const char* ASCII_ALPHANUM = "0123456789" "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const int ASCII_ALPHANUM_SIZE = 62;

static const char* ASCII_DRAWABLE = "0123456789" "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
static const int ASCII_DRAWABLE_SIZE = 94;

static const char* ASCII_WHITESPACES = " \t\n\r\x0b\x0c";
static const int ASCII_WHITESPACES_SIZE = 6;

static const char* ASCII_PRINTABLE = "0123456789" "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~" " \t\n\r\x0b\x0c";
static const int ASCII_PRINTABLE_SIZE = 100;

bool ascii_isAlphaNum(const byte_t chr);
bool ascii_isDrawable(byte_t chr);
bool ascii_isPrintable(byte_t chr);

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

bool isEmptySpaceOrNull(byte_t chr);
bool isEmptySpace(const byte_t chr);

bool isLower(byte_t chr);
bool isUpper(byte_t chr);

char toLower(char chr);
char toUpper(char chr);

const char* toLowerCase(const char* value, size_t size);
const char* toUpperCase(const char* value, size_t size);

char toCapitalized(char chr, const bool capitalized);

size_t toTrimStartCalcSize(const char* value, size_t size);
const data_t* toTrimStart(const char* value, size_t size);

size_t toTrimEndCalcSize(const char* value, const size_t size);
const data_t* toTrimEnd(const char* value, size_t size);

size_t toTrimCalcSize(const char* value, size_t size);
const data_t* toTrim(const char* value, size_t size);

size_t toTitleCaseCalcSize(const char* value, size_t size);
const data_t* toTitleCase(const char* value, size_t size);

size_t toCamelCaseCalcSize(const char* value, size_t size);
const data_t* toCamelCase(const char* value, size_t size);
const data_t* toUpperCamelCase(const char* value, size_t size);

size_t toSnakeCaseCalcSize(const char* value, size_t size);
const data_t* toSnakeCase(const char* value, size_t size);

size_t toKebabCaseCalcSize(const char* value, size_t size);
const data_t* toKebabCase(const char* value, size_t size);

// ============ data ============ //

const data_t* data_toLowerCase(const data_t* data);
const data_t* data_toUpperCase(const data_t* data);
const data_t* data_toTrimStart(const data_t* data);
const data_t* data_toTrimEnd(const data_t* data);
const data_t* data_toTrim(const data_t* data);
const data_t* data_toTitleCase(const data_t* data);
const data_t* data_toCamelCase(const data_t* data);
const data_t* data_toUpperCamelCase(const data_t* data);
const data_t* data_toSnakeCase(const data_t* data);
const data_t* data_toKebabCase(const data_t* data);

// ============ data ============ //

// extras files
#include "./commons/datetime.h"
#include "./commons/typed_num.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMON
