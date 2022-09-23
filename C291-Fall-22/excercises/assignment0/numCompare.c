#include <stdio.h>

int main(void){
	int number1 = 0;
	int number2 = 0;

	printf("Enter the first number: ");
	scanf("%d", &number1);
	printf("\n");

	printf("Enter the second number: ");
	scanf("%d", &number2);
	printf("\n");

	if(number1==number2){
		printf("%d is equal to %d\n", number1, number2);
	}
	if (number1!=number2){
		printf("%d is not equal to %d\n", number1, number2);
	}
	if(number1>number2){
		printf("%d is greater than %d\n", number1, number2);
	}
	if(number1<number2){
		printf("%d is less then %d\n", number1, number2);
	}
}
