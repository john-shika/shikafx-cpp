#include "./common.h"

bool is_ascii_alphanum(const byte_t chr) {
    const char* chars = ASCII_ALPHANUM;
    int size_chars = ASCII_ALPHANUM_SIZE;
    for (int i = 0; i < size_chars; i++) {
        if (chars[i] == chr) return true;
    }
    return false;
}

bool is_ascii_drawable(const byte_t chr) {
    const char* chars = ASCII_DRAWABLE;
    int size_chars = ASCII_DRAWABLE_SIZE;
    for (int i = 0; i < size_chars; i++) {
        if (chars[i] == chr) return true;
    }
    return false;
}

bool is_ascii_printable(const byte_t chr) {
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

bool isSpaceTab(byte_t chr) {
    // TAB 9
    // SPACE 32

    // LF 10
    // CRLF 13, 10
    // NBSP 160

    switch (chr) {
        case 9:
        case 32:
            return true;
        default:
            return false;
    }
}

size_t spaceTabsCount(const char* value, size_t size) {
    size_t m = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isSpaceTab(chr)) m += 1;
    }
    return m;
}

bool isLower(const char chr) {
    if (97 <= chr && chr <= 122) return true;
    return false;
}

bool isUpper(const char chr) {
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
        temp[i] = toLower(chr);
    }

    return temp;
}

const char* toUpperCase(const char* value, const size_t size) {
    char* temp = create_char_stack(size);

    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        temp[i] = toUpper(chr);
    }

    return temp;
}

char toCapitalized(char chr, const bool capitalized) {
    if (capitalized) return toUpper(chr);
    return toLower(chr);
}

const data_t* toTrimStart(const char* value, const size_t size) {
    byte_t* temp = create_byte_stack(size);
    bool trimStart = true;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if ((isSpaceTab(chr) || chr == 0) && trimStart) continue;
        trimStart = false;
        temp[j] = chr;
        j += 1;
    }

    return create_data(temp, j);
}

const data_t* toTrimEnd(const char* value, const size_t size) {
    byte_t* temp = copy_byte_stack_func((const byte_t*)value, size);
    size_t j = size;

    //trimEnd
    if (j > 0) {
        for (size_t k = 0; k < j; k++) {
            size_t x = j - k - 1;
            byte_t chr = temp[x];
            if (!(isSpaceTab(chr) || chr == 0)) break;
            temp[x] = 0;
            j = x;
        }
    }

    return create_data(temp, j);
}

const data_t* toTrim(const char* value, const size_t size) {
    byte_t* temp = create_byte_stack(size);
    bool trimStart = true;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if ((isSpaceTab(chr) || chr == 0) && trimStart) continue;
        trimStart = false;
        temp[j] = chr;
        j += 1;
    }

    //trimEnd
    if (j > 0) {
        for (size_t k = 0; k < j; k++) {
            size_t x = j - k - 1;
            byte_t chr = temp[x];
            if (!(isSpaceTab(chr) || chr == 0)) break;
            temp[x] = 0;
            j = x;
        }
    }

    return create_data(temp, j);
}

const data_t* toTitleCase(const char* value, const size_t size) {
    byte_t* temp = create_byte_stack(size);
    bool capitalized = true;
    bool trimStart = true;
    bool skipped = false;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isSpaceTab(chr) || chr == 0) {
            if (trimStart) continue;
            if (skipped) continue;
            capitalized = true;
            skipped = true;
            temp[j] = 32; // space
            j += 1;
            continue;
        }
        trimStart = false;
        skipped = false;
        chr = toCapitalized(chr, capitalized);
        capitalized = false;
        temp[j] = chr;
        j += 1;
    }

    //trimEnd
    if (j > 0) {
        for (size_t k = 0; k < j; k++) {
            size_t x = j - k - 1;
            byte_t chr = temp[x];
            if (!(isSpaceTab(chr) || chr == 0)) break;
            temp[x] = 0;
            j = x;
        }
    }

    return create_data(temp, j);
}

const data_t* toCamelCase(const char* value, const size_t size) {
    byte_t* temp = create_byte_stack(size);
    bool capitalized = false;
    bool trimStart = true;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isSpaceTab(chr) || chr == 0) {
            if (trimStart) continue;
            capitalized = true;
            continue;
        }
        trimStart = false;
        if (!is_ascii_alphanum(chr)) continue;
        chr = toCapitalized(chr, capitalized);
        capitalized = false;
        temp[j] = chr;
        j += 1;
    }

    return create_data(temp, j);
}

const data_t* toSnakeCase(const char* value, const size_t size) {
    byte_t* temp = create_byte_stack(size);
    bool trimStart = true;
    bool skipped = false;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isSpaceTab(chr) || chr == 0 || chr == 95) {
            if (trimStart) continue;
            if (skipped) continue;
            skipped = true;
            temp[j] = 95; // underscore
            j += 1;
            continue;
        }
        if (!is_ascii_alphanum(chr)) continue;
        trimStart = false;
        skipped = false;
        chr = toLower(chr);
        temp[j] = chr;
        j += 1;
    }

    //trimEnd
    if (j > 0) {
        for (size_t k = 0; k < j; k++) {
            size_t x = j - k - 1;
            byte_t chr = temp[x];
            if (!(isSpaceTab(chr) || chr == 0 || chr == 95)) break;
            temp[x] = 0;
            j = x;
        }
    }

    return create_data(temp, j);
}

const data_t* toKebabCase(const char* value, const size_t size) {
    byte_t* temp = create_byte_stack(size);
    bool trimStart = true;
    bool skipped = false;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isSpaceTab(chr) || chr == 0 || chr == 45) {
            if (trimStart) continue;
            if (skipped) continue;
            skipped = true;
            temp[j] = 45; // hyphens
            j += 1;
            continue;
        }
        if (!is_ascii_alphanum(chr)) continue;
        trimStart = false;
        skipped = false;
        chr = toLower(chr);
        temp[j] = chr;
        j += 1;
    }

    //trimEnd
    if (j > 0) {
        for (size_t k = 0; k < j; k++) {
            size_t x = j - k - 1;
            byte_t chr = temp[x];
            if (!(isSpaceTab(chr) || chr == 0 || chr == 45)) break;
            temp[x] = 0;
            j = x;
        }
    }

    return create_data(temp, j);
}

const data_t* toUpperCamelCase(const char* value, const size_t size) {
    byte_t* temp = create_byte_stack(size);
    bool capitalized = true;

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        char chr = value[i];
        if (isSpaceTab(chr) || chr == 0) {
            capitalized = true;
            continue;
        }
        if (!is_ascii_alphanum(chr)) continue;
        chr = toCapitalized(chr, capitalized);
        capitalized = false;
        temp[j] = chr;
        j += 1;
    }

    return create_data(temp, j);
}

// extras files
#include "./commons/datetime.c"
#include "./commons/typed_nums.c"
