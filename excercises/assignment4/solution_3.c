#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPerfectNumber(int num){
	int test=0;
	for(int i=1;i<num;i++){
		if(fmod(num,i)==0){
			test+=i;
		}
	}
	if(test==num){
		return true;
	}
	return false;
}

int main(void){
	int num;
	printf("%s","Enter a number: ");
	scanf("%d",&num);
	if(isPerfectNumber(num)){
		printf("%d is a perfect number.\n", num);
		return 0;
	}
	printf("%d is not a perfect number.\n", num);
	return 0;
}
