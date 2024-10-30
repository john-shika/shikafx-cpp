#include "./mergesort.h"

void skx_NumTyped__mergesort__merge(NumTyped_t* data, size_t left, size_t mid, size_t right) {
    
    size_t i, j, k;
    const size_t n1 = mid - left + 1;
    const size_t n2 = right - mid;
    
    if (n1 <= 0 || n2 <= 0) {
        return;
    }

    NumTyped_t* L = calloc(n1, sizeof(NumTyped_t));
    NumTyped_t* R = calloc(n2, sizeof(NumTyped_t));
    for (i = 0; i < n1; i++) {
        L[i] = data[left + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = data[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (skx_NumTyped__le(L[i], R[j])) { // <=
            data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
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
void skx_NumTyped__mergesort__init(NumTyped_t* data, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        
        // Sort first and second halves recursively
        skx_NumTyped__mergesort__init(data, left, mid);
        skx_NumTyped__mergesort__init(data, mid + 1, right);
        
        // Merge the sorted halves back together
        skx_NumTyped__mergesort__merge(data, left, mid, right);
    }
}
#pragma clang diagnostic pop

void skx_NumTyped__mergesort(NumTyped_t* data, size_t size) {
    skx_NumTyped__mergesort__init(data, 0, size - 1);
}

void skx_mergesort_merge(int* data, size_t left, size_t mid, size_t right) {

    size_t i, j, k;
    const size_t n1 = mid - left + 1;
    const size_t n2 = right - mid;

    if (n1 <= 0 && n2 <= 0) return;

    int* arrLeft = calloc(n1, sizeof(int));
    int* arrRight = calloc(n2, sizeof(int));

    for (i = 0; i < n1; i++) {
        arrLeft[i] = data[left + i];
    }

    for (j = 0; j < n2; j++) {
        arrRight[j] = data[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (arrLeft[i] <= arrRight[j]) {
            data[k] = arrLeft[i];
            i++;
        }
        else {
            data[k] = arrRight[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        data[k] = arrLeft[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = arrRight[j];
        j++;
        k++;
    }

    free(arrLeft);
    free(arrRight);
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
void skx_mergesort_init(int* data, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;

        // Sort first and second halves recursively
        skx_mergesort_init(data, left, mid);
        skx_mergesort_init(data, mid + 1, right);

        // Merge the sorted halves back together
        skx_mergesort_merge(data, left, mid, right);
    }
}
#pragma clang diagnostic pop

void skx_mergesort(int* data, size_t size) {
    skx_mergesort_init(data, 0, size - 1);
}

