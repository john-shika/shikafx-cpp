#include "./common.h"

bool ascii_isAlphaNum(const byte_t chr) {
    const char* chars = ASCII_ALPHANUM;
    int size_chars = ASCII_ALPHANUM_SIZE;
    for (int i = 0; i < size_chars; i++) {
        if (chars[i] == chr) return true;
    }
    return false;
}

bool ascii_isDrawable(byte_t chr) {
    const char* chars = ASCII_DRAWABLE;
    int size_chars = ASCII_DRAWABLE_SIZE;
    for (int i = 0; i < size_chars; i++) {
        if (chars[i] == chr) return true;
    }
    return false;
}

bool ascii_isPrintable(byte_t chr) {
    const char* chars = ASCII_DRAWABLE;
    int size_chars = ASCII_DRAWABLE_SIZE;
    for (int i = 0; i < size_chars; i++) {
        if (chars[i] == chr) return true;
    }
    return false;
}

char* create_char_stack(const size_t size) {
#ifdef DEBUG
    printf("[CC] create memory allocator for <char> stack pointer\n");
#endif

    char* ptr = calloc(size, sizeof *ptr);
    return ptr;
}

void drop_char_stack(const char* data) {
    char* ptr = (char*)data;

    if (ptr == NULL) return;

#ifdef DEBUG
    printf("[CC] free up memory allocator for <char> stack pointer\n");
#endif

    free(ptr);
    ptr = NULL;
}

byte_t* create_byte_stack(const size_t size) {
#ifdef DEBUG
    printf("[CC] create memory allocator for <byte_t> stack pointer\n");
#endif

    byte_t* ptr = calloc(size, sizeof *ptr);
    return ptr;
}

void drop_byte_stack(const byte_t* data) {
    byte_t* ptr = (byte_t*)data;

    if (ptr == NULL) return;

#ifdef DEBUG
    printf("[CC] free up memory allocator for <char> stack pointer\n");
#endif

    free(ptr);
    ptr = NULL;
}

data_t* create_data(const byte_t* data, const size_t size) {
#ifdef DEBUG
    printf("[CC] create memory allocator for <data_t> pointer\n");
#endif

    data_t* ptr = malloc(sizeof *ptr);
    ptr->data = data;
    ptr->size = size;
    return ptr;
}

void drop_data(const data_t* data, const bool drop_field) {
    data_t* ptr = (data_t*)data;

    if (ptr == NULL) return;

#ifdef DEBUG
    printf("[CC] free up memory allocator for <data_t> pointer\n");
#endif

    if (drop_field && ptr->data != NULL) drop_byte_stack(ptr->data);
    
    free(ptr);
    ptr = NULL;
}

bool isEmptySpaceOrNull(const byte_t chr) {
    if (chr == 0 || chr == 32) return true;
    return false;
}

bool isEmptySpace(const byte_t chr) {
    // TAB 9
    // SPACE 32
    // LF 10
    // CRLF 13, 10
    // NBSP 160 (Unicode) 11 12 (UTF-8)

    // TODO: using unicode wide char instead using this method
    // this method strict in traditional ASCII word
    switch (chr) {
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 32:
            return true;
        default:
            return false;
    }
}

bool isLower(const byte_t chr) {
    if (97 <= chr && chr <= 122) return true;
    return false;
}

bool isUpper(const byte_t chr) {
    if (65 <= chr && chr <= 90) return true;
    return false;
}

char toLower(char chr) {
    if (isUpper(chr)) chr += 32;
    return chr;
}

char toUpper(char chr) {
    if (isLower(chr)) chr += -32;
    return chr;
}

const char* toLowerCase(const char* value, const size_t size) {
    char* temp = create_char_stack(size);

    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        temp[i] = toLower(chr);
    }

    return temp;
}

const char* toUpperCase(const char* value, const size_t size) {
    char* temp = create_char_stack(size);

    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        temp[i] = toUpper(chr);
    }

    return temp;
}

char toCapitalized(char chr, const bool capitalized) {
    if (capitalized) return toUpper(chr);
    return toLower(chr);
}

size_t toTrimStartCalcSize(const char* value, const size_t size) {
    if (size == 0) return 0;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (!isEmptySpace(chr)) break;
        j += 1;
    }

    return size - j;
}

const data_t* toTrimStart(const char* value, const size_t size) {
    size_t m = toTrimStartCalcSize(value, size);
    byte_t* temp = create_byte_stack(m);
    bool trimStart = true;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr) && trimStart) continue;
        trimStart = false;
        temp[j] = chr;
        j += 1;
    }

    return create_data(temp, m);
}

size_t toTrimEndCalcSize(const char* value, const size_t size) {
    if (size == 0) return 0;

    size_t j = 0;
    for (size_t k = 0; k < size; k++) {
        size_t x = size - k - 1;
        char chr = value[x];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (!isEmptySpace(chr)) break;
        j += 1;
    }

    return size - j;
}

const data_t* toTrimEnd(const char* value, const size_t size) {
    size_t m = toTrimEndCalcSize(value, size);
    byte_t* temp = create_byte_stack(m);
    bool trimEnd = true;

    size_t j = 0;
    for (size_t k = 0; k < size; k++) {
        if (m <= j) panic("var `j` is out of bound string");
        size_t x = size - k - 1;
        char chr = value[x];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr) && trimEnd) continue;
        trimEnd = false;
        size_t y = m - j - 1;
        temp[y] = chr;
        j += 1;
    }

    return create_data(temp, m);
}

size_t toTrimCalcSize(const char* value, const size_t size) {
    if (size == 0) return 0;

    // trimming end
    size_t j = 0;
    for (size_t k = 0; k < size; k++) {
        size_t x = size - k - 1;
        char chr = value[x];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (!isEmptySpace(chr)) break;
        j += 1;
    }

    // assign new size
    size_t n = size - j;

    // trimming start
    j = 0;
    for (size_t i = 0; i < n; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (!isEmptySpace(chr)) break;
        j += 1;
    }

    return n - j;
}

const data_t* toTrim(const char* value, const size_t size) {
    size_t m = toTrimCalcSize(value, size);
    byte_t* temp = create_byte_stack(m);
    bool trimStart = true;

    // trimming
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (m <= j) break;
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr) && trimStart) continue;
        trimStart = false;
        temp[j] = chr;
        j += 1;
    }

    return create_data(temp, m);
}

size_t toTitleCaseCalcSize(const char* value, const size_t size) {
    bool skipped = false;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr)) {
            if (skipped) continue;
            skipped = true;
            j += 1;
            continue;
        }
        skipped = false;
        j += 1;
    }

    return j;
}

const data_t* toTitleCase(const char* value, const size_t size) {
    const data_t* data = toTrim(value, size);
    const char* buff = (const char*)data->data;
    size_t len = data->size;

    size_t m = toTitleCaseCalcSize(buff, len);
    byte_t* temp = create_byte_stack(m);

    bool capitalized = true;
    bool skipped = false;

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        char chr = buff[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr)) {
            if (skipped) continue;
            skipped = true;
            capitalized = true;
            temp[j] = chr;
            j += 1;
            continue;
        }
        skipped = false;
        chr = toCapitalized(chr, capitalized);
        capitalized = false;
        temp[j] = chr;
        j += 1;
    }

    drop_data(data, true);
    return create_data(temp, m);
}

size_t toCamelCaseCalcSize(const char* value, const size_t size) {
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr) || !ascii_isAlphaNum(chr)) continue;
        j += 1;
    }

    return j;
}

const data_t* toCamelCase(const char* value, const size_t size) {
    size_t m = toCamelCaseCalcSize(value, size);
    byte_t* temp = create_byte_stack(m);
    bool capitalized = false;
    bool trimStart = true;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr)) {
            if (trimStart) continue;
            capitalized = true;
            continue;
        }
        trimStart = false;
        if (!ascii_isAlphaNum(chr)) continue;
        chr = toCapitalized(chr, capitalized);
        capitalized = false;
        temp[j] = chr;
        j += 1;
    }

    return create_data(temp, m);
}

const data_t* toUpperCamelCase(const char* value, const size_t size) {
    size_t m = toCamelCaseCalcSize(value, size);
    byte_t* temp = create_byte_stack(m);
    bool capitalized = true;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr)) {
            capitalized = true;
            continue;
        }
        if (!ascii_isAlphaNum(chr)) continue;
        chr = toCapitalized(chr, capitalized);
        capitalized = false;
        temp[j] = chr;
        j += 1;
    }

    return create_data(temp, m);
}

size_t toSnakeCaseCalcSize(const char* value, const size_t size) {
    bool skipped = false;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr) || chr == 95) {
            if (skipped) continue;
            skipped = true;
            j += 1;
            continue;
        }
        if (!ascii_isAlphaNum(chr)) continue;
        skipped = false;
        j += 1;
    }

    return j;
}

const data_t* toSnakeCase(const char* value, const size_t size) {
    const data_t* data = toTrim(value, size);
    const char* buff = (const char*)data->data;
    size_t len = data->size;

    size_t m = toSnakeCaseCalcSize(buff, len);
    byte_t* temp = create_byte_stack(m);
    bool skipped = false;

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        char chr = buff[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr) || chr == 95) {
            if (skipped) continue;
            skipped = true;
            temp[j] = 95; // underscore
            j += 1;
            continue;
        }
        if (!ascii_isAlphaNum(chr)) continue;
        skipped = false;
        chr = toLower(chr);
        temp[j] = chr;
        j += 1;
    }

    drop_data(data, true);
    return create_data(temp, m);
}

size_t toKebabCaseCalcSize(const char* value, const size_t size) {
    bool skipped = false;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr) || chr == 45) {
            if (skipped) continue;
            skipped = true;
            j += 1;
            continue;
        }
        if (!ascii_isAlphaNum(chr)) continue;
        skipped = false;
        j += 1;
    }

    return j;
}

const data_t* toKebabCase(const char* value, const size_t size) {
    const data_t* data = toTrim(value, size);
    const char* buff = (const char*)data->data;
    size_t len = data->size;

    size_t m = toKebabCaseCalcSize(buff, len);
    byte_t* temp = create_byte_stack(m);
    bool skipped = false;

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        char chr = buff[i];
        if (isEmptySpaceOrNull(chr)) chr = 32;
        if (isEmptySpace(chr) || chr == 45) {
            if (skipped) continue;
            skipped = true;
            temp[j] = 45; // hyphens
            j += 1;
            continue;
        }
        if (!ascii_isAlphaNum(chr)) continue;
        skipped = false;
        chr = toLower(chr);
        temp[j] = chr;
        j += 1;
    }

    drop_data(data, true);
    return create_data(temp, m);
}

// ============ data ============ //

const data_t* data_toLowerCase(const data_t* data) {
    const byte_t* buff = (const byte_t*)toLowerCase((const char*)data->data, data->size);
    return create_data(buff, data->size);
}

const data_t* data_toUpperCase(const data_t* data) {
    const byte_t* buff = (const byte_t*)toUpperCase((const char*)data->data, data->size);
    return create_data(buff, data->size);
}

const data_t* data_toTrimStart(const data_t* data) {
    return toTrimStart((const char*)data->data, data->size);
}

const data_t* data_toTrimEnd(const data_t* data) {
    return toTrimEnd((const char*)data->data, data->size);
}

const data_t* data_toTrim(const data_t* data) {
    return toTrim((const char*)data->data, data->size);
}

const data_t* data_toTitleCase(const data_t* data) {
    return toTitleCase((const char*)data->data, data->size);
}

const data_t* data_toCamelCase(const data_t* data) {
    return toCamelCase((const char*)data->data, data->size);
}

const data_t* data_toUpperCamelCase(const data_t* data) {
    return toUpperCamelCase((const char*)data->data, data->size);
}

const data_t* data_toSnakeCase(const data_t* data) {
    return toSnakeCase((const char*)data->data, data->size);
}

const data_t* data_toKebabCase(const data_t* data) {
    return toKebabCase((const char*)data->data, data->size);
}

// ============ data ============ //

// extras files
#include "./commons/datetime.c"
#include "./commons/typed_num.c"
