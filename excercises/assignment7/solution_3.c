#include <stdio.h>
#include <stdbool.h>

int getDelimIndex(char *str, const char *delim, int num){
  int count=0;
  int delimSize=0;
  bool isNull=false;
  int match=0;
  while(delim[count]!='\0'){
    delimSize++;
    count++;
  }
  count=0;
  char *buffer=(char*)malloc(sizeof(char)*delimSize);
  for(int i=0;i<delimSize;i++){
    buffer[i]=str[i];
  }
  while(str[count]!='\0'){
    for(int i=0;i<delimSize;i++){
      if(str[i+count]=='\0'){
        isNull=true;
      }
    }
    if(!isNull){
      for(int i=0;i<delimSize;i++){
        buffer[i]=str[i+count];
      }
    }

    for(int i=0;i<delimSize;i++){
      if(buffer[i]==delim[i]){
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

bool equals(char *s1,char *s2){
  int count=0;
  bool out=true;
  while(s1!='\0'&&s2!='\0'&&s1!='\n'&&s2!='\n'){
    if(s1[count]!=s2[count]){
      return false;
    }
    count++;
  }
  return true;
}

int getDelimAmt(char * str, const char *delim){
  if(str[0]=='\0'){
    return NULL;
  }
  int arrSize=1;
  int count=0;
  int delimSize=0;
  bool isNull=false;
  int match=0;
  while(delim[count]!='\0'){
    delimSize++;
    count++;
  }
  if(delimSize==0){
    char **output=(char**)malloc(sizeof(char*));
    output[0]=str;
    return output;
  }
  count=0;
  char *buffer=(char*)malloc(sizeof(char)*delimSize);
  for(int i=0;i<delimSize;i++){
    buffer[i]=str[i];
  }
  while(str[count]!='\0'){
    for(int i=0;i<delimSize;i++){
      if(str[i+count]=='\0'){
        isNull=true;
      }
    }
    if(!isNull){
      for(int i=0;i<delimSize;i++){
        buffer[i]=str[i+count];
      }
    }

    for(int i=0;i<delimSize;i++){
      if(buffer[i]==delim[i]){
        match++;
      }
    }
    if(match==delimSize){
      count+=delimSize-1;
    }
    match=0;
    count++;
  }
  int delimAmt=1;
  int delimCount=1;
  while(getDelimIndex(str,delim,delimCount)!=-1){
    delimAmt++;
    delimCount++;
  }
  delimAmt-=1;
  return delimAmt;
}

char *replaceAll(const char * string, char * target, char * replacement){
  int delimAmt=getDelimAmt(string,target);
  int replacementSize=0;
  while(replacement[replacementSize]!='\0'&&replacement[replacementSize]!='\n'){
    replacementSize++;
  }
  int stringSize=0;
  while(string[stringSize]!='\0'&&string[stringSize]!='\n'){
    stringSize++;
  }
  int targetSize=0;
  while(target[targetSize]!='\0'&&target[targetSize]!='\n'){
    targetSize++;
  }
  int totalNewSize=stringSize-(targetSize*delimAmt)+(replacementSize*delimAmt)+1;
  char *newStr=(char*)malloc(totalNewSize*sizeof(char));
  int count=0;
  char *buffer=(char*)malloc(targetSize*sizeof(char)+1);
  int countInd=1;
  for(int i=0;i<stringSize;i++){
    if(i==getDelimIndex(string,target,countInd)){
      for(int j=0;j<replacementSize;j++){
        newStr[count]=replacement[j];
        count++;
      }
      countInd++;
      i+=targetSize-1;
    }
    else{
      newStr[count]=string[i];
      count++;
    }
  }
  return newStr;
}

int main(void){
  char *str=(char*)malloc(1001*sizeof(char));
  char *delim=(char*)malloc(1001*sizeof(char));
  char *rep=(char*)malloc(1001*sizeof(char));
  printf("%s", "Enter test: ");
  fgets(str,1000,stdin);
  printf("%s","Enter a target: ");
  fgets(delim,1000,stdin);
  printf("%s","Enter a replacement String: ");
  fgets(rep,1000,stdin);
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
  count=0;
  while(rep[count]!='\0'&&rep[count]!='\n'){
    count++;
  }
  char *repNew=(char*)malloc((count+2)*sizeof(char));
  count=0;
  while(rep[count]!='\0'&&rep[count]!='\n'){
    repNew[count]=rep[count];
    count++;
  }
  printf("Output: %s\n", replaceAll(strNew,delimNew,repNew));

}
