#include "./utils.h"

char* copy_char_stack_func(const char* buff, const size_t size) {

    char* temp = create_char_stack(size);
    memcpy(temp, buff, size);

    return temp;
}

// wnt: with null terminate

char* copy_char_stack_wnt_func(const char* buff, const size_t size) {

    char* temp = create_char_stack(size + 1);
    memcpy(temp, buff, size);

    return temp;
}

byte_t* copy_byte_stack_func(const byte_t* buff, const size_t size) {

    byte_t* temp = create_byte_stack(size);
    memcpy(temp, buff, size);

    return temp;
}

// wnt: with null terminate

byte_t* copy_byte_stack_wnt_func(const byte_t* buff, const size_t size) {

    byte_t* temp = create_byte_stack(size + 1);
    memcpy(temp, buff, size);

    return temp;
}

// extra files
#include "./utils/quicksort.c"
#include "./utils/mergesort.c"
#include "./utils/sort.c"
