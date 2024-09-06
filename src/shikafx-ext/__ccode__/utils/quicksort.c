#include "./quicksort.h"

void skx_quicksort_typed_nums__swap(typed_nums_t* data, const int64_t left, const int64_t right) {
    //skx_typed_nums__swap(&data[left], &data[right]);

    typed_nums_t temp = data[left];
    data[left] = data[right];
    data[right] = temp;
}

int64_t skx_quicksort_typed_nums__partition(typed_nums_t* data, const int64_t low, const int64_t high) {
    typed_nums_t pivot = data[high];
    int64_t i = low;

    for (int64_t j = low; j < high; j++) {
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
void skx_quicksort_typed_nums__init(typed_nums_t* data, const int64_t low, const int64_t high) {
    if (low < high) {
        int64_t m = skx_quicksort_typed_nums__partition(data, low, high);
        skx_quicksort_typed_nums__init(data, low, m - 1);
        skx_quicksort_typed_nums__init(data, m + 1, high);
    }
}
#pragma clang diagnostic pop

void skx_quicksort_typed_nums(typed_nums_t* data, const int64_t size) {
    skx_quicksort_typed_nums__init(data, 0, size - 1);
}
