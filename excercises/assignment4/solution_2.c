#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool findGCD(int num1, int num2, int test){
	if(test<=num1&&test<=num2&&fmod(num1,test)==0&&fmod(num2,test)==0){
		return true;
	}

	return false;
	
}

int main(void){
	int num1, num2;
	printf("%s", "Enter the 1st positive integer: ");
	scanf("%d", &num1);
	printf("%s", "Enter the 2nd positive integer: ");
	scanf("%d", &num2);
	int highest=1;
	for(int i=1;i<=num1;i++){
		if(findGCD(num1, num2, i)==true){
			highest=i;
		}
	}
	printf("The GCD of %d and %d is %d.\n", num1, num2, highest);
	return 0;
}
