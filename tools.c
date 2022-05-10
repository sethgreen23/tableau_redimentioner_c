#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "intarray.h"
void interchange(int* a,int* b){
  int intermediaire;
  intermediaire=*a;
  *a=*b;
  *b=intermediaire;
}
int safe_string_to_int(char* str, int* ok){
    if(str[0]=='-')
      return -safe_string_to_int(str+1,ok);
    int number =0;
    int i=0;
    *ok=1;
    while(str[i]!='\0'){
      
      if(str[i]<'0' || str[i]>'9' ){
        *ok=0;
        return 0;
      }
      number*=10;
      number+=str[i]-48;
      // printf("%c\n",str[i]);
      i++;
    }
    return number;
}
int string_to_int(char* str){
  int* ok=malloc(sizeof(int));
  int result ;
  if(*ok==1){
    return result;
  }else if(*ok==0){
    return 0;
  }
}