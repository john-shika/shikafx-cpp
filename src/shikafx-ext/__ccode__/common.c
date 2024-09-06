#include "./common.h"
#include "./commons/typed_nums.c"

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
