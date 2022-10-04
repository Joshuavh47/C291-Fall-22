#include <stdio.h>

void printUniqueElements(int elements[], int lenArray){
  int count=0;
  for(int i=0;i<lenArray-1;i++){
    if(elements[i]!=elements[i+1]){
      count++;
    }
  }
  int output[count+1];
  count=0;
  for(int i=0;i<lenArray-1;i++){
    if(elements[i]!=elements[i+1]){
      output[count]=elements[i];
      count++;
    }
  }
  for(int i=0;i<count+1;i++){
    printf("%d ", output[i]);
  }
}

int main(void){
  int size;
  printf("%s", "Enter size of array: ");
  scanf("%d", &size);
  char in[100];
  printf("%s","Enter the array: ");
  scanf("%s", &in);
  int elements[size];
  int count=0;
  for(int i=0;i<size*2;i++){
    if(i%2==0){
      elements[count]=(int)in[i];
      count++;
    }
  }
  printUniqueElements(elements, size);
  return 0;

}
