/*
 * program takes two numbers as input and outputs their sum
 */
#include <stdio.h>

int main(void){
	
	//define two int variables
	int number1 = 0;
	int number2 = 0;

	//prompt the user to enter number 1
	printf("Enter number 1: ");
	scanf("%d", &number1);
	printf("\n");
	
	
	
	
	//prompt the user to enter number 2
	printf("Enter number 2: ");
	scanf("%d", &number2);
	printf("\n");
	int numberTotal = 0;
	numberTotal= number1+number2;
	printf("The sum of %d and %d is %d\n", number1, number2,numberTotal);
	return 0;
		
}
