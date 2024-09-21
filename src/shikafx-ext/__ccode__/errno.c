#include "./errno.h"

void panic(const char* format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), format, args);
    size_t size = strlen(buffer);

    if (size == 0 || buffer[size - 1] != '\n') strncat(buffer, "\n", sizeof(buffer) - size - 1);
    fputs(buffer, stderr);

    va_end(args);
    exit(1);
}
