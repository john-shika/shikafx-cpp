#include "./errno.h"

void panic(const char* format, ...) {
    va_list args;
    va_start(args, format);

    size_t size = 1024;
    char* buffer = calloc(size, sizeof *buffer);
    vsnprintf(buffer, size, format, args);
    size_t count = strlen(buffer);

    if (count > 0) {
        size_t last = count - 1;
        if (count < size) {
            if (buffer[last] != 0x0A) buffer[last] = 0x0A;
            fputs(buffer, stderr);
        } else {
            const char* newLine = "\x0A";
            fputs(buffer, stderr);
            if (buffer[last] != 0x0A) fputs(newLine, stderr);
        }
    }

    va_end(args);
    free(buffer);
    exit(1);
}
