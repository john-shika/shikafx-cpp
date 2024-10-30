#include "./quicksort.h"

void skx_NumTyped__quicksort__swap(NumTyped_t* data, size_t left, size_t right) {
    NumTyped_t temp = data[left];
    data[left] = data[right];
    data[right] = temp;
}

size_t skx_NumTyped__quicksort__partition(NumTyped_t* data, size_t low, size_t high) {
    NumTyped_t pivot = data[high];
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        if (skx_NumTyped__lt(data[j], pivot)) {
            skx_NumTyped__quicksort__swap(data, i, j);
            i++;
        }
    }

    skx_NumTyped__quicksort__swap(data, i, high);
    return i;
}

#ifdef __clang__
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#elif defined(__GNUC__) || defined(__GNUG__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#elif defined(_MSC_VER)
#pragma warning(disable : 4068) // unknown pragma
#endif

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
void skx_NumTyped__quicksort__init(NumTyped_t* data, size_t low, size_t high) {
    if (low < high) {
        size_t m = skx_NumTyped__quicksort__partition(data, low, high);
        if (0 < m) skx_NumTyped__quicksort__init(data, low, m - 1);
        skx_NumTyped__quicksort__init(data, m + 1, high);
    }
}
#pragma clang diagnostic pop

void skx_NumTyped__quicksort(NumTyped_t* data, size_t size) {
    skx_NumTyped__quicksort__init(data, 0, size - 1);
}

void skx_quicksort_swap(int* data, size_t left, size_t right) {
    int temp = data[left];
    data[left] = data[right];
    data[right] = temp;
}

size_t skx_quicksort_partition(int* data, size_t low, size_t high) {
    int pivot = data[high];
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        if (data[j] < pivot) {
            skx_quicksort_swap(data, i, j);
            i++;
        }
    }

    skx_quicksort_swap(data, i, high);
    return i;
}

#ifdef __clang__
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#elif defined(__GNUC__) || defined(__GNUG__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#elif defined(_MSC_VER)
#pragma warning(disable : 4068) // unknown pragma
#endif

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
void skx_quicksort_init(int* data, size_t low, size_t high) {
    if (low < high) {
        size_t m = skx_quicksort_partition(data, low, high);
        if (0 < m) skx_quicksort_init(data, low, m - 1);
        skx_quicksort_init(data, m + 1, high);
    }
}
#pragma clang diagnostic pop

void skx_quicksort(int* data, size_t size) {
    skx_quicksort_init(data, 0, size - 1);
}
