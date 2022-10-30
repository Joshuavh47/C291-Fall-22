#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char toLowercase(char c){
  if(c=='\0'){
    return '\0';
  }
  else if((int)c>=65&&(int)c<=90){
    c+=32;
  }
  return c;
}

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
      if(toLowercase(buffer[i])==toLowercase(delim[i])){
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
  while(s1!='\0'&&s2!='\0'){
    if(s1[count]!=s2[count]){
      return false;
    }
    count++;
  }
  return true;
}

char ** myTokenizer(char * str, const char *delim){
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
    if(getDelimIndex(str,delim,delimCount)+delimSize==getDelimIndex(str,delim,delimCount+1)&&getDelimIndex(str,delim,delimCount+1)!=-1){
      delimAmt--;
    }
    if(getDelimIndex(str,delim,delimCount+1)==-1&&getDelimIndex(str,delim,delimCount)+delimSize==count){
      delimAmt--;
    }
    delimAmt++;
    delimCount++;
  }
  delimAmt-=1;
  arrSize=delimAmt-1;
  if(getDelimIndex(str,delim,1)!=0){
    arrSize++;
  }
  if(getDelimIndex(str,delim,delimAmt)+delimSize<count){
    arrSize++;
  }
  char **output=(char**)malloc(arrSize*sizeof(char*));
  int arrCount=0;

  if(getDelimIndex(str,delim,1)!=0){
    output[0]=(char*)malloc((getDelimIndex(str,delim,1)+1)*sizeof(char));
    for(int j=0;j<getDelimIndex(str,delim,1);j++){
      output[0][j]=str[arrCount];
      arrCount++;
    }
    output[0][getDelimIndex(str,delim,1)]='\0';
    arrCount=getDelimIndex(str,delim,2)+delimSize;
  }
  else if(getDelimIndex(str,delim,1)==0&&getDelimIndex(str,delim,2)!=-1){
    arrCount=getDelimIndex(str,delim,1)+delimSize;
    output[0]=(char*)malloc((getDelimIndex(str,delim,2)-getDelimIndex(str,delim,2)-delimSize)*sizeof(char));
    for(int j=0;j<getDelimIndex(str,delim,2)-getDelimIndex(str,delim,2)-delimSize;j++){
      output[0][j]=str[arrCount];
      arrCount++;
    }
    output[0][getDelimIndex(str,delim,2)]='\0';
  }

  else if(getDelimIndex(str,delim,1)==0){
    int inc=1;
    while((getDelimIndex(str,delim,inc)+1)/inc==delimSize){
      arrCount+=delimSize;
    }
  }

  if(getDelimIndex(str,delim,delimAmt)<count-delimSize){
    arrCount=getDelimIndex(str,delim,delimAmt)+delimSize;
    output[arrSize-1]=(char*)malloc((count-getDelimIndex(str,delim,delimAmt)-delimSize)*sizeof(char));
    char *buff=(char*)malloc(delimSize*sizeof(char));
    int buffCount=arrCount;
    for(int i=0;i<=delimSize;i++){
      buff[i]=str[arrCount];
    }
    buff[delimSize]='\0';
    while(equals(buff,delim)){
      arrCount+=delimSize;
      for(int i=0;i<delimSize;i++){
        buff[i]=str[arrCount];
      }
    }


    for(int j=0;j<count-getDelimIndex(str,delim,delimAmt)-delimSize;j++){
      output[arrSize-1][j]=str[arrCount];
      arrCount++;
    }
    output[arrSize-1][count-getDelimIndex(str,delim,delimAmt)-delimSize]='\0';

  }
  else if(getDelimIndex(str,delim,delimAmt-1)==count-delimSize){
    arrCount=getDelimIndex(str,delim,delimAmt)+delimSize;
    output[arrSize-1]=(char*)malloc((getDelimIndex(str,delim,delimAmt)-getDelimIndex(str,delim,delimAmt-1)-delimSize+1)*sizeof(char));
    for(int j=0;j<getDelimIndex(str,delim,delimAmt)-getDelimIndex(str,delim,delimAmt-1)-delimSize+1;j++){

      output[arrSize-1][j]=str[arrCount];
    }
    output[arrSize-1][getDelimIndex(str,delim,delimAmt)-getDelimIndex(str,delim,delimAmt-1)-delimSize+1]='\0';
  }

  delimCount=1;
  for(int i=1;i<=arrSize-1;i++){
    arrCount=getDelimIndex(str,delim,delimCount)+delimSize;
    if(getDelimIndex(str,delim,delimCount+1)-getDelimIndex(str,delim,delimCount)-delimSize>0){
      output[i]=(char*)malloc((getDelimIndex(str,delim,delimCount+1)-getDelimIndex(str,delim,delimCount)-delimSize+1)*sizeof(char));
      for(int j=0;j<getDelimIndex(str,delim,delimCount+1)-getDelimIndex(str,delim,delimCount)-delimSize;j++){

        output[i][j]=str[arrCount];
        arrCount++;
      }
      output[i][getDelimIndex(str,delim,delimCount+1)-getDelimIndex(str,delim,delimCount)-delimSize+1]='\0';
    }
    else if(getDelimIndex(str,delim,delimCount+1)-getDelimIndex(str,delim,delimCount)==delimSize){
      i--;
    }
    delimCount++;
  }

  return output;
}
int getArrSize(char *str,char *delim){
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
    if(getDelimIndex(str,delim,delimCount)+delimSize==getDelimIndex(str,delim,delimCount+1)&&getDelimIndex(str,delim,delimCount+1)!=-1){
      delimAmt--;
    }
    if(getDelimIndex(str,delim,delimCount+1)==-1&&getDelimIndex(str,delim,delimCount)+delimSize==count){
      delimAmt--;
    }
    delimAmt++;
    delimCount++;
  }
  delimAmt-=1;
  arrSize=delimAmt-1;
  if(getDelimIndex(str,delim,1)!=0){
    arrSize++;
  }
  if(getDelimIndex(str,delim,delimAmt)+delimSize<count){
    arrSize++;
  }
  return arrSize;
}




int main(void){
  char *str=(char*)malloc(1001*sizeof(char));
  char *delim=(char*)malloc(1001*sizeof(char));
  printf("%s", "Enter a String: ");
  fgets(str,1000,stdin);
  printf("%s", "Enter a delimiter: ");
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
  char **out=myTokenizer(str,delim);
  for(int i=0;i<getArrSize;i++){
    printf("%s\n",out[i]);
  }

  return 0;
}
