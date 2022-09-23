#include <stdio.h>

int main(void){
	int a=0;
	int b=0;
	printf("Input a: ");
	scanf("%d", &a);
	printf("\nInput b: ");
	scanf("%d", &b);
	int sum=a+b;
	int diff=a-b;
	int mult=a*b;
	int mod=a%b;
	printf("\nThe sum of %d and %d is %d.\n",a, b, sum);
	printf("The difference of %d and %d is %d\n", a, b, diff);
	printf("The product of %d and %d is %d\n", a, b, mult);
	printf("The remainder of %d and %d is %d\n", a, b, mod);
	return 0;
}
