#include <stdio.h>

int main(void){
	int numTemp;
	int numTemp1;
	int num;
	int count=0;
	printf("%s", "Choose a number to convert to backwards binary: ");
	scanf("%d", &num);
	int num1=num;
	printf("%s", "Output: ");
	for(int i=0;num1>0;i++){
		numTemp1=num1%2;
		num1/=2;
		count++;
		printf("%d", numTemp1);
	}
	puts("");
	char numArr[count-1];
	for(int i=0;num>0;i++){
		numTemp=num%2;
		num/=2;
		numArr[i]=(int)numTemp;
	}
	for(int i = count-1;i>=0;i--){
		printf("%d", numArr[i]);
	}
	puts("");
	return 0;
}
