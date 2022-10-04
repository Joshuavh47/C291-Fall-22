#include <stdio.h>

#define NCOLS 4
void filterStudents(int output[], int students[][NCOLS], int minAge, int minYear, int minGrade){
  int count = 0;
  for(int i=0;i<5;i++){
    if(minAge!=-1&&minYear==-1&&minGrade==-1){
      if(students[i][1]>=minAge){
        output[count]=students[i][0];
        count++;
      }
    }
    else if(minAge==-1&&minYear!=-1&&minGrade==-1){
      if(students[i][2]>=minYear){
        output[count]=students[i][0];
        count++;
      }
    }
    else if(minAge==-1&&minYear==-1&&minGrade!=-1){
      if(students[i][3]>=minGrade){
        output[count]=students[i][0];
        count++;
      }
    }
    else if(minAge!=-1&&minYear!=-1&&minGrade==-1){
      if(students[i][1]>=minAge&&students[i][2]>=minYear){
        output[count]=students[i][0];
        count++;
      }
    }
    else if(minAge==-1&&minYear!=-1&&minGrade!=-1){
      if(students[i][2]>=minYear&&students[i][3]>=minGrade){
        output[count]=students[i][0];
        count++;
      }
    }
    else if(minAge!=-1&&minYear==-1&&minGrade!=-1){
      if(students[i][1]>=minAge&&students[i][3]>=minGrade){
        output[count]=students[i][0];
        count++;
      }
    }
    else if(minAge!=-1&&minYear!=-1&&minGrade!=-1){
      if(students[i][1]>=minAge&&students[i][2]>=minYear&&students[i][3]>=minGrade){
        output[count]=students[i][0];
        count++;
      }
    }
  }
}

int main(void){
  int a,b,c;
  int output[5]={-1, -1, -1, -1, -1};
  int students[5][4]={{1,17,11,90},{2,16,10,70},{3,15,10,45},{4,18,12,67},{5,14,9,100}};
  printf("%s", "Enter the first parameter: ");
  scanf("%d", &a);
  printf("%s", "Enter the second parameter: ");
  scanf("%d", &b);
  printf("%s", "Enter the third parameter: ");
  scanf("%d", &c);
  filterStudents(output, students, a, b, c);
  for(int i=0;i<3;i++){
    if(output[i]>=0){
      printf("%d ",output[i]);
    }
  }
  return 0;
}
