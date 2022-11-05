#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int* data;
    size_t length;
} Array;

Array* new_array(size_t len){
  Array *newArr=(Array*)malloc(sizeof(Array));
  newArr->length=len;
  newArr->data=(int*)malloc(len*sizeof(int));
  return newArr;
}
int array_get(Array* arr, int index){
  return arr->data[index];
}
void array_set(Array* arr, int index, int value){
  arr->data[index]=value;
}
void delete_array(Array* arr){
  free(arr->data);
  free(arr);
}

int main(void){
  Array *a=new_array(3);
  array_set(a,0,1);
  array_set(a,1,2);
  array_set(a,2,3);
  for(int i=0;i<a->length;i++){
    printf("%d\n",array_get(a,i));
  }
  delete_array(a);
  return 0;
}
