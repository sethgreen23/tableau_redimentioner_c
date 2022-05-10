#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "intarray.h"
//create from an empty array
intarray intarray_empty_create(int alloc){
  intarray tab = malloc(sizeof(struct _intarray));
  tab->len = 0;
  tab->alloc = alloc;
  if(alloc <=0){
    tab->alloc = 40;
    printf("intarray_empty_create: intarray_empty_create: the size of the array need to be >=0\n");
    printf("We allocated the size of the table as %d \n",tab->alloc);
  }
  intarray_empty_create_aux(tab);
  return tab;
  
}
// fill the table with zero till the acctual size of the array
void intarray_empty_create_aux(intarray tab){
  tab->data = malloc(tab->alloc*sizeof(int));
  int i;
  for(i=0;i<tab->alloc; i++){
      tab->data[i]=0;
  }
}
// show the table
void intarray_debug(intarray tab){
  int i;
  printf("[ ");
  for(i=0;i<tab->len;i++){
    if(i!=tab->len-1)
      printf("%d, ",tab->data[i]);
    else
      printf("%d",tab->data[i]);
  }
  printf(" ]");
}
//add element at the end of the array
void intarray_add_end(intarray tab,int value){
  // if(tab->len>=tab->alloc){
  //   printf("intarray_add_end: We can't allow the adding of value %d array out of the size\n",value);
  //   return;
  // }
  // tab->data[tab->len++]=value;
  ext_intarray_set(tab,tab->len,value);
  
}
// void intarray_add_end(intarray tab,int value){
//   if(tab->len>=tab->alloc){
//     printf("intarray_add_end: We can't allow the adding of value %d array out of the size\n",value);
//     return;
//   }
//   tab->data[tab->len++]=value;
//   // printf("The value %d added successfully\n",value);
// }

//get element at index 
int intarray_get(intarray tab,int index){
  if(index<0 || index>=tab->len){
    printf("intarray_get: The index have to be between 0 and %d.\n",tab->len-1);
    return 0;
  }
  return tab->data[index];
}
//set value at index
void intarray_set(intarray tab, int index, int value){
  if(index<0 || index>=tab->len){
    printf("intarray_set: The index have to be between 0 and %d.\n");
    return;
  }
  tab->data[index]=value;
}
//delete element at index with replacing it with the value of the last element in the array
void UNSORTED_intarray_delete(intarray tab, int index){
  if(index<0 || index>=tab->len){
    printf("UNSORTED_intarray_delete: the index need to be betweein 0  and %d.\n ",tab->len-1);
    return;
  }
  tab->data[index]=tab->data[tab->len-1];
  
  tab->len--;
}
// we will keep the order but it will be slow
void intarray_delete(intarray tab, int index){
  if(index<0 || index>=tab->len){
    printf("intarray_delete: the index need to be betweein 0  and %d.\n ",tab->len-1);
    return;
  }
  int i;
  for(i=index+1;i<tab->len;i++){
    tab->data[i-1]=tab->data[i];
  }

  tab->len--;
}
// get the index of max from a starting position
int intarray_get_index_of_max_from(intarray tab, int index){
  if(index <0 || index>=tab->len){
    printf("intarray_get_index_of_max_from: index needs to be betoween 0 and %d.\n",tab->len-1);
    return 0;
  }
  int max = tab->data[index];
  int maxIndex = index;
  for(int i= index+1;i<tab->len;i++){
    if(tab->data[i]>max){
      max = tab->data[i];
      maxIndex = i;
    }
  }
  return maxIndex;
}
// get the index of the max value 
int intarray_get_index_of_max(intarray tab){
  return intarray_get_index_of_max_from(tab,0);
}
// get the value of the max
int intarray_get_max(intarray tab){
  return tab->data[intarray_get_index_of_max(tab)];
}
// get the index of min from a starting position
int intarray_get_index_of_min_from(intarray tab, int index){
  if(index <0 || index>=tab->len){
    printf("intarray_get_index_of_min_from: index needs to be betoween 0 and %d.\n",tab->len-1);
    return 0;
  }
  int min = tab->data[index];
  int minIndex = index;
  for(int i= index+1;i<tab->len;i++){
    if(tab->data[i]<min){
      min = tab->data[i];
      minIndex = i;
    }
  }
  return minIndex;
}
// get the index of the minimum
int intarray_get_index_of_min(intarray tab){
  return intarray_get_index_of_min_from(tab,0);
}
// get the index of the min value 
int intarray_get_min(intarray tab){
  return tab->data[intarray_get_index_of_min(tab)];
}
// get the sum of the elements of the array
int intarray_sum(intarray tab){
  if(tab->len<=0){
    printf("intarray_sum: the array is empty");
    return 0;
  }
  int sum=0;
  for( int i=0;i<tab->len;i++){
    sum+=tab->data[i];
  }
  return sum;
}
// get the average of the array elements
float intarray_average(intarray tab){
  if(tab->len<=0){
    printf("intarray_average: the array is empty");
    return 0.0;
  }
  return (intarray_sum(tab)*1.0)/2.0;
}
// get the median value of the elements of the array
float intarray_median(intarray tab){
  if(tab->len<=0){
    printf("intarray_median: the array is empty");
    return 0.0;
  }
  int indexAvg=tab->len/2;
  float avg;
  if(tab->len % 2 == 1){
    avg = tab->data[indexAvg];
  }else{
    avg = (tab->data[indexAvg]+tab->data[indexAvg-1])/2.0;
  }
  return avg;
}
intarray intarray_tri_1(intarray tab){
  // make a copy of the the tab
  intarray copy = intarray_copy(tab);
  //get the index of the min on a sertain position and interchange the positions
  intarray_tri_aux(copy);
  // intarray_debug(copy);
  return copy;
}
void intarray_tri_aux(intarray tab){
  int i;
  for(i=0;i<tab->len;i++){
    int min = intarray_get_index_of_min_from(tab,i);
    
    interchange(tab->data+i, tab->data+min);//interchange(&tab->data[i],&tab->data[min]);
    // intarray_debug(tab);
    // printf("%d\n",min);
    
  }
}

intarray intarray_copy(intarray tab){
  intarray copy = intarray_empty_create(tab->alloc);
  copy->len = tab->len;
  int i;
  for(i=0;i<copy->len;i++){
    copy->data[i]=tab->data[i];
  }
  return copy;
}
void intarray_free(intarray tab){
  free(tab->data);
  free(tab);
}
void ext_intarray_set(intarray tab, int index, int value){
  // if the index negative it is not possible return 
  if(index < 0){
    printf("The index cant be negative !\n");
    return;
  }
  // if the index < len then set normally return
  if(index < tab->len){
    tab->data[index]=value;
    return;
  }
  //if the index >= alloc resize  newalloc=2*index +1
  if(index >= tab->alloc)
    intarray_resise(tab, 2*index+1);
  // make the data between len and index to 0
  for(int i=tab->len;i<index;i++){
    tab->data[i]=0;
  }
  //the box with index take the value
  tab->data[index]=value;
  // if index >= len then len = index+1
  if(index >= tab->len)
    tab->len=index+1;

}
void intarray_resise(intarray tab, int newalloc){
  // allo new array with size newalloc*2+1;
  int* newdata = malloc(sizeof(int)*newalloc);
  //assign the array values from the new to the old
  for(int i=0;i<tab->len;i++)
    newdata[i]=tab->data[i];
  //all take the value of the new alloc
  tab->alloc = newalloc;
  //free the old data
  free(tab->data);
  // give the data the new table
  tab->data = newdata;
}
// modifier intarray_add
void ext_intarray_debug(intarray tab){
  printf("The new alloc is %d and the len is %d.\n",tab->alloc, tab->len);
  intarray_debug(tab);
}