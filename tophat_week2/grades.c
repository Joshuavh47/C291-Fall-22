#include <stdio.h>

int main(void){
	float grade;
	puts("Enter a grade: ");
	scanf("%f", &grade);
	if (grade>=90){
		puts("A");
	}
	else if(grade>=80&&grade<90){
		puts("B");
	}
	else if (grade>=70&&grade<80){
		puts("C");
	}
	else if (grade>=60&&grade<70){
		puts("D");
	}
	else{
		puts("F");
	}
	return 0;
}
