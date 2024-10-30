#ifndef C_SHIKAFX_EXTRAS_UTILS_MERGESORT
#define C_SHIKAFX_EXTRAS_UTILS_MERGESORT

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//#define DEBUG

#include "../common.h"

void skx_NumTyped__mergesort__merge(NumTyped_t* data, size_t left, size_t mid, size_t right);
void skx_NumTyped__mergesort__init(NumTyped_t* data, size_t left, size_t right);
void skx_NumTyped__mergesort(NumTyped_t* data, size_t size);

void skx_mergesort_merge(int* data, size_t left, size_t mid, size_t right);
void skx_mergesort_init(int* data, size_t left, size_t right);
void skx_mergesort(int* data, size_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_UTILS_MERGESORT
