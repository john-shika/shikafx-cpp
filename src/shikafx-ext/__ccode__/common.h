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
#include "./errno.h"

typedef unsigned char byte_t;
typedef unsigned int uint_t;
//typedef long int int32_t;
//typedef unsigned long int uint32_t;
//typedef long long int int64_t;
//typedef unsigned long long int uint64_t;

static const char* ASCII_UPPERCASE;
static const char* ASCII_LOWERCASE;
static const char* DIGITS;
static const char* ASCII_PUNCTUATION;
static const char* ASCII_ALPHANUM;
static const char* ASCII_DRAWABLE;
static const char* ASCII_PRINTABLE;
static const char* ASCII_WHITESPACES;

static const int ASCII_UPPERCASE_SIZE = 26;
static const int ASCII_LOWERCASE_SIZE = 26;
static const int DIGITS_SIZE = 10;
static const int ASCII_PUNCTUATION_SIZE = 32;
static const int ASCII_ALPHANUM_SIZE = 62;
static const int ASCII_DRAWABLE_SIZE = 94;
static const int ASCII_PRINTABLE_SIZE = 100;
static const int ASCII_WHITESPACES_SIZE = 6;

bool Ansi_isAlphaNum(byte_t chr);
bool Ansi_isDrawable(byte_t chr);
bool Ansi_isPrintable(byte_t chr);

char* create_char_stack(size_t size);
void drop_char_stack(const char* data);

byte_t* create_byte_stack(size_t size);
void drop_byte_stack(const byte_t* data);

typedef struct {
    const byte_t* data;
    size_t size;
} data_t;

const data_t* create_data(const byte_t* data, size_t size);
void drop_data(const data_t* data, bool drop_field);

#define EXPAND(x) x
#define DROP_DATA_1(a) drop_data(a, true)
#define DROP_DATA_2(a, b) DROP_DATA_1(a); DROP_DATA_1(b)
#define DROP_DATA_3(a, b, c) DROP_DATA_2(a, b); DROP_DATA_1(c)
#define DROP_DATA_4(a, b, c, d) DROP_DATA_3(a, b, c); DROP_DATA_1(d)
#define DROP_DATA_5(a, b, c, d, e) DROP_DATA_4(a, b, c, d); DROP_DATA_1(e)
#define DROP_DATA_6(a, b, c, d, e, f) DROP_DATA_5(a, b, c, d, e); DROP_DATA_1(f)
#define DROP_DATA_7(a, b, c, d, e, f, g) DROP_DATA_6(a, b, c, d, e, f); DROP_DATA_1(g)
#define DROP_DATA_8(a, b, c, d, e, f, g, h) DROP_DATA_7(a, b, c, d, e, f, g); DROP_DATA_1(h)

#define MOVE_DATA_1(a) drop_data(a, false)
#define MOVE_DATA_2(a, b) MOVE_DATA_1(a); MOVE_DATA_1(b)
#define MOVE_DATA_3(a, b, c) MOVE_DATA_2(a, b); MOVE_DATA_1(c)
#define MOVE_DATA_4(a, b, c, d) MOVE_DATA_3(a, b, c); MOVE_DATA_1(d)
#define MOVE_DATA_5(a, b, c, d, e) MOVE_DATA_4(a, b, c, d); MOVE_DATA_1(e)
#define MOVE_DATA_6(a, b, c, d, e, f) MOVE_DATA_5(a, b, c, d, e); MOVE_DATA_1(f)
#define MOVE_DATA_7(a, b, c, d, e, f, g) MOVE_DATA_6(a, b, c, d, e, f); MOVE_DATA_1(g)
#define MOVE_DATA_8(a, b, c, d, e, f, g, h) MOVE_DATA_7(a, b, c, d, e, f, g); MOVE_DATA_1(h)

#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define DROP_DATA_M(...) EXPAND(GET_MACRO(__VA_ARGS__, DROP_DATA_8, DROP_DATA_7, DROP_DATA_6, DROP_DATA_5, DROP_DATA_4, DROP_DATA_3, DROP_DATA_2, DROP_DATA_1)(__VA_ARGS__))
#define MOVE_DATA_M(...) EXPAND(GET_MACRO(__VA_ARGS__, MOVE_DATA_8, MOVE_DATA_7, MOVE_DATA_6, MOVE_DATA_5, MOVE_DATA_4, MOVE_DATA_3, MOVE_DATA_2, MOVE_DATA_1)(__VA_ARGS__))

const data_t* data_slice(const data_t* data, size_t size);
const data_t* data_pack(const char* data, size_t size);
const data_t* data_copy(const data_t* data);

int data_cmp(const data_t* data, const data_t* other);
bool data_eq(const data_t* data, const data_t* other);

bool isEmptySpaceOrNull(byte_t chr);
bool isEmptySpace(byte_t chr);

bool isLower(byte_t chr);
bool isUpper(byte_t chr);

char toLower(char chr);
char toUpper(char chr);

const char* toLowerCase(const char* value, size_t size);
const char* toUpperCase(const char* value, size_t size);

char toCapitalized(char chr, bool capitalized);

size_t toTrimStartCalcSize(const char* value, size_t size);
const data_t* toTrimStart(const char* value, size_t size);

size_t toTrimEndCalcSize(const char* value, size_t size);
const data_t* toTrimEnd(const char* value, size_t size);

size_t toTrimCalcSize(const char* value, size_t size);
const data_t* toTrim(const char* value, size_t size);

const data_t* trimToLowerCase(const char* value, size_t size);
const data_t* trimToUpperCase(const char* value, size_t size);

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

const data_t* data_trimToLowerCase(const data_t* data);
const data_t* data_trimToUpperCase(const data_t* data);

// ============ data ============ //

// extras files
#include "./commons/datetime.h"
#include "./commons/num_typed.h"

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMON
