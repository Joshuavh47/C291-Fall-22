#include <stdio.h>

int main(void){
	int num;
	puts("Enter a number: ");
	scanf("%d", &num);
	if (num%2==1){
		printf("%d is an odd number\n", num);
	}
	else{
		printf("%d is an even number\n", num);
	}
	return 0;
}
