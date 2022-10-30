#include <stdio.h>
#include <stdbool.h>

int indexOf(char *haystack, const char *needle, int num){
  int count=0;
  int delimSize=0;
  bool isNull=false;
  int match=0;
  while(needle[count]!='\0'&&needle[count]!='\n'){
    delimSize++;
    count++;
  }
  count=0;
  char *buffer=(char*)malloc(sizeof(char)*delimSize);
  for(int i=0;i<delimSize;i++){
    buffer[i]=haystack[i];
  }
  while(haystack[count]!='\0'){
    for(int i=0;i<delimSize;i++){
      if(haystack[i+count]=='\0'){
        isNull=true;
      }
    }
    if(!isNull){
      for(int i=0;i<delimSize;i++){
        buffer[i]=haystack[i+count];
      }
    }

    for(int i=0;i<delimSize;i++){
      if(buffer[i]==needle[i]){
        match++;
      }
    }
    if(match==delimSize&&num-1!=0){
      count+=delimSize-1;
      num--;
    }
    else if(match==delimSize&&num-1==0){
      return count;
    }
    match=0;
    count++;
  }
  if(num>0){
    return -1;
  }
}

int main(void){
  char *str=(char*)malloc(1001*sizeof(char));
  char *delim=(char*)malloc(1001*sizeof(char));
  printf("%s", "Haystack: ");
  fgets(str,1000,stdin);
  printf("%s", "Needle: ");
  fgets(delim,1000,stdin);
  int count=0;
  while(str[count]!='\0'&&str[count]!='\n'){
    count++;
  }
  char *strNew = (char*)malloc((count+2)*sizeof(char));
  for(int i=0;i<count;i++){
    strNew[i]='\0';
  }
  count=0;
  while(str[count]!='\0'&&str[count]!='\n'){
    strNew[count]=str[count];
    count++;
  }
  count=0;
  while(delim[count]!='\0'&&delim[count]!='\n'){
    count++;
  }
  char *delimNew=(char*)malloc((count+2)*sizeof(char));
  for(int i=0;i<count;i++){
    delimNew[i]='\0';
  }
  count=0;
  while(delim[count]!='\0'&&delim[count]!='\n'){
    delimNew[count]=delim[count];
    count++;
  }
  printf("%s\n", strNew);
  printf("%s\n", delimNew);
  printf("%d\n",indexOf(str,delim,1));
}
