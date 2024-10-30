#ifndef C_SHIKAFX_EXTRAS_UTILS_QUICKSORT
#define C_SHIKAFX_EXTRAS_UTILS_QUICKSORT

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../common.h"

void skx_NumTyped__quicksort__swap(NumTyped_t* data, size_t left, size_t right);
size_t skx_NumTyped__quicksort__partition(NumTyped_t* data, size_t low, size_t high);
void skx_NumTyped__quicksort__init(NumTyped_t* data, size_t low, size_t high);
void skx_NumTyped__quicksort(NumTyped_t* data, size_t size);

void skx_quicksort_swap(int* data, size_t left, size_t right);
size_t skx_quicksort_partition(int* data, size_t low, size_t high);
void skx_quicksort_init(int* data, size_t low, size_t high);
void skx_quicksort(int* data, size_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_UTILS_QUICKSORT