#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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



char ***parse(char *xmlStr){
  char ***out=(char***)malloc(getDelimAmt(xmlStr,"<book id")*sizeof(char**));
  for(int i=0;i<getDelimAmt(xmlStr,"<book id");i++){
    out[i]=(char**)malloc(6*sizeof(char*));
  }
  int count=0;
  for(int i=0;i<getDelimAmt(xmlStr,"<book id");i++){
    out[i][0]=(char*)malloc((getDelimIndex(xmlStr,"</author>",i+1)-getDelimIndex(xmlStr,"<author>",i+1)-7)*sizeof(char));
    for(int j=0;j<getDelimIndex(xmlStr,"</author>",i+1)-getDelimIndex(xmlStr,"<author>",i+1)-8;j++){
      out[i][0][j]=xmlStr[getDelimIndex(xmlStr,"<author>",i+1)+8+j];
    }
    out[i][1]=(char*)malloc((getDelimIndex(xmlStr,"</title>",i+1)-getDelimIndex(xmlStr,"<title>",i+1)-7)*sizeof(char));
    for(int j=0;j<getDelimIndex(xmlStr,"</title>",i+1)-getDelimIndex(xmlStr,"<title>",i+1)-7;j++){
      out[i][1][j]=xmlStr[getDelimIndex(xmlStr,"<title>",i+1)+7+j];
    }
    out[i][2]=(char*)malloc((getDelimIndex(xmlStr,"</genre>",i+1)-getDelimIndex(xmlStr,"<genre>",i+1)-6)*sizeof(char));
    for(int j=0;j<getDelimIndex(xmlStr,"</genre>",i+1)-getDelimIndex(xmlStr,"<genre>",i+1)-7;j++){
      out[i][2][j]=xmlStr[getDelimIndex(xmlStr,"<genre>",i+1)+7+j];
    }
    out[i][3]=(char*)malloc((getDelimIndex(xmlStr,"</price>",i+1)-getDelimIndex(xmlStr,"<price>",i+1)-6)*sizeof(char));
    for(int j=0;j<getDelimIndex(xmlStr,"</price>",i+1)-getDelimIndex(xmlStr,"<price>",i+1)-7;j++){
      out[i][3][j]=xmlStr[getDelimIndex(xmlStr,"<price>",i+1)+7+j];
    }
    out[i][4]=(char*)malloc((getDelimIndex(xmlStr,"</publish_date>",i+1)-getDelimIndex(xmlStr,"<publish_date>",i+1)-13)*sizeof(char));
    for(int j=0;j<getDelimIndex(xmlStr,"</publish_date>",i+1)-getDelimIndex(xmlStr,"<publish_date>",i+1)-14;j++){
      out[i][4][j]=xmlStr[getDelimIndex(xmlStr,"<publish_date>",i+1)+14+j];
    }
    out[i][5]=(char*)malloc((getDelimIndex(xmlStr,"</description>",i+1)-getDelimIndex(xmlStr,"<description>",i+1)-12)*sizeof(char));
    for(int j=0;j<getDelimIndex(xmlStr,"</description>",i+1)-getDelimIndex(xmlStr,"<description>",i+1)-13;j++){
      out[i][5][j]=xmlStr[getDelimIndex(xmlStr,"<description>",i+1)+13+j];
    }
  }
  return out;
}

int main(void){
  char * xmlString =
  "<?xml version=\"1.0\"?>\n<catalog>\n"
  "<book id=\"bk101\">\n"
     "<author>Gambardella, Matthew</author>\n"
     "<title>XML Developer's Guide</title>\n"
     "<genre>Computer</genre>\n"
     "<price>44.95</price>\n"
     "<publish_date>2000-10-01</publish_date>\n"
     "<description>An in-depth look at creating applications with XML.</description>\n"
  "</book>\n"
  "<book id=\"bk102\">\n"
     "<author>Cormen, Stein</author>\n"
     "<title>Introduction of Algorithm, fourth edition</title>\n"
     "<genre>Computer</genre>\n"
     "<price>84.89</price>\n"
     "<publish_date>2022-04-05</publish_date>\n"
     "<description>A comprehensive update of the leading algorithms text, with new material on matchings in bipartite graphs, online algorithms, machine learning, and other topics.</description>\n"
  "</book>\n"
  "<book id=\"bk103\">\n"
     "<author>Ryan, Carl</author>\n"
     "<title>Python Programming for beginners: A Crash Course</title>\n"
     "<genre>Computer</genre>\n"
     "<price>7.11</price>\n"
     "<publish_date>2022-01-19</publish_date>\n"
     "<description>The Ultimate Python guide for beginners!</description>\n"
  "</book>\n"
  "</catalog>";

  char ***out=parse(xmlString);
  int highestInd=0;
  for(int i=0;i<getDelimAmt(xmlString,"<price>");i++){
    if(atof(out[i][3])>atof(out[highestInd][3])){
      highestInd=i;
    }
  }
  int lowestInd=0;
  for(int i=0;i<getDelimAmt(xmlString,"<price>");i++){
    if(atof(out[i][3])<atof(out[lowestInd][3])){
      lowestInd=i;
    }
  }
  puts("Most expensive book: ");
  printf("Author: %s\n", out[highestInd][0]);
  printf("Title: %s\n", out[highestInd][1]);
  printf("Genre: %s\n", out[highestInd][2]);
  printf("Price: $%s\n", out[highestInd][3]);
  printf("Publication Date: %s\n", out[highestInd][4]);
  printf("Description: %s\n", out[highestInd][5]);
  puts("");
  puts("Least expensive book: ");
  printf("Author: %s\n", out[lowestInd][0]);
  printf("Title: %s\n", out[lowestInd][1]);
  printf("Genre: %s\n", out[lowestInd][2]);
  printf("Price: $%s\n", out[lowestInd][3]);
  printf("Publication Date: %s\n", out[lowestInd][4]);
  printf("Description: %s\n", out[lowestInd][5]);

}
