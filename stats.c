#include <stdlib.h>
#include <stdio.h>
#include "intarray.h"
#include "tools.h"
#include "stats.h"
intarray stats_table(char** tab, int alloc){
  intarray arr = intarray_empty_create(alloc);
  int* ok = malloc(sizeof(int));
  for(int i=1;i<arr->alloc;i++){
    *ok=1;
    int number = safe_string_to_int(tab[i],ok);
    if(*ok==1){
      intarray_add_end(arr,number);
    }  
  }
  return arr;
}
void stats(char** tab, int alloc){
  intarray result = stats_table(tab, alloc);
  intarray copy = intarray_tri_1(result);
  int sum = intarray_sum(copy);
  float average = intarray_average(copy);
  float median = intarray_median(copy);
  printf("Showing some statistic:");
  intarray_debug(copy);
  printf("\n");
  printf("The sum is %d.",sum);
  printf("\n");
  printf("The average is %f.",average);
  printf("\n");
  printf("The median is %f.",median);
  free(result);
}