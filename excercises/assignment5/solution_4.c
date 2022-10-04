#include <stdio.h>

int checkSet(int input[], int input_length){
  if(sizeof(input)<1){
    puts("Set cannot be empty!");
    return 1;
  }
  return 0;
}

int findIntersection(int input1[], int input1_length, int input2[], int input2_length){
  int same=0;
  for(int i=0;i<input1_length;i++){
    for(int j=0;j<input2_length;j++){
      if(input1[i]==input2[j]){
        same++;
      }
    }
  }
  return same;
}

int findUnion(int input1[], int input1_length, int input2[], int input2_length){
  int k=0;
  int j=0;
  int i=0;
  int out[input1_length+input2_length];
  for(i=0;i<input1_length;i++){
    for(j=0;j<k;j++){
      if(out[j]==input1[i]){
        break;
      }
    }
    if(j==k){
      out[k]=input1[i];
      k++;
    }
  }
  for(i=0;i<input2_length;i++){
    for(j=0;j<k;j++){
      if(out[j]==input2[i]){
        break;
      }
    }

    if(j==k){
      out[k]=input2[i];
      k++;
    }
  }
  return k;
}
void calculateJaccard(int input1[], int input1_length, int input2[], int input2_length){
  double out=findIntersection(input1, input1_length, input2, input2_length)/findUnion(input1, input1_length, input2, input2_length);
  printf("The Jaccard similarity is %lf\n", out);
}

int main(void){
  int a[]={1,2,3,4};
  int b[]={2,7,9,4};
  if(checkSet(a,4)!=0||checkSet(b,4)!=0){
    checkSet(a,4);
    checkSet(b,4);
    return 0;
  }
  else{
    calculateJaccard(a,4,b,4);
  }
  return 0;

}
