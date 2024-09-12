#include "./sort.h"

void skx_sort_typed_nums__swap(typed_nums_t *data, const size_t a, const size_t b) {
  typed_nums_t temp = data[a];
  data[a] = data[b];
  data[b] = temp;
}

void skx_sort_typed_nums(typed_nums_t *data, const size_t size) {
  
  for (size_t i = 0; i < size; i++) {
    typed_nums_t curr = data[i];

    for (size_t j = 0; j < i; j++) {
      typed_nums_t check = data[j];
    
      if (skx_typed_nums__gt(check, curr)) {
        skx_sort_typed_nums__swap(data, i, j);
      }
    }
  }
}
