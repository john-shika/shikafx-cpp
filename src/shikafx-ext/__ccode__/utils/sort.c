#include "./sort.h"

void skx_sort_typed_num__swap(typed_num_t *data, size_t a, size_t b) {
  typed_num_t temp = data[a];
  data[a] = data[b];
  data[b] = temp;
}

void skx_sort_typed_num(typed_num_t *data, size_t size) {
  
  for (size_t i = 0; i < size; i++) {
    typed_num_t curr = data[i];

    for (size_t j = 0; j < i; j++) {
      typed_num_t check = data[j];
    
      if (skx_typed_num__gt(check, curr)) {
          skx_sort_typed_num__swap(data, i, j);
      }
    }
  }
}
