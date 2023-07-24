#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[]) {
  list_t new_listt = { length, { 0 }};
  return &new_listt;
}