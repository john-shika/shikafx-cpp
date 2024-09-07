#include "./quicksort.h"

void skx_quicksort_typed_nums__swap(typed_nums_t* data, const size_t left, const size_t right) {
    //skx_typed_nums__swap(&data[left], &data[right]);

    typed_nums_t temp = data[left];
    data[left] = data[right];
    data[right] = temp;
}

size_t skx_quicksort_typed_nums__partition(typed_nums_t* data, const size_t low, const size_t high) {
    typed_nums_t pivot = data[high];
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        if (skx_typed_nums__lt(data[j], pivot)) {
            skx_quicksort_typed_nums__swap(data, i, j);
            i++;
        }
    }

    skx_quicksort_typed_nums__swap(data, i, high);
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
void skx_quicksort_typed_nums__init(typed_nums_t* data, const size_t low, const size_t high) {
    if (low < high) {
        size_t m = skx_quicksort_typed_nums__partition(data, low, high);
        if (0 < m) skx_quicksort_typed_nums__init(data, low, m - 1);
        skx_quicksort_typed_nums__init(data, m + 1, high);
    }
}
#pragma clang diagnostic pop

void skx_quicksort_typed_nums(typed_nums_t* data, const size_t size) {
    skx_quicksort_typed_nums__init(data, 0, size - 1);
}
