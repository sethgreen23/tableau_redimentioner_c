#include <stdlib.h>
#include <stdio.h>

typedef struct _intarray* intarray;
typedef struct _intarray S_intarray;
struct _intarray {
  int* data;
  int len;
  int alloc;
};
intarray intarray_empty_create(int alloc);
void intarray_empty_create_aux(intarray tab);
void intarray_debug(intarray tab);
void intarray_add_end(intarray tab,int value);
int intarray_get(intarray tab,int index);
void intarray_set(intarray tab, int index, int value);
void UNSORTED_intarray_delete(intarray tab, int index);
void intarray_delete(intarray tab, int index);
int intarray_get_index_of_max_from(intarray tab, int index);
int intarray_get_index_of_max(intarray tab);
int intarray_get_max(intarray tab);
int intarray_get_index_of_min_from(intarray tab, int index);
int intarray_get_index_of_min(intarray tab);
int intarray_get_min(intarray tab);
int intarray_sum(intarray tab);
float intarray_average(intarray tab);
float intarray_median(intarray tab);
intarray intarray_tri_1(intarray tab);
void intarray_tri_aux(intarray tab);
intarray intarray_copy(intarray tab);
void intarray_free(intarray tab);
