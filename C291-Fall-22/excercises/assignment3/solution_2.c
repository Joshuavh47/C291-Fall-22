#include <stdio.h>

int main(void){
	int num;
	puts("Enter a positive integer to calculate the prime factors of: ");
	scanf("%d", &num);
	if(num<0){
		puts("Number must be positive. ");
		return 0;
	}
	else if(num==0||num==1){
		printf("%d has no prime factorization\n", num);
		return 0;
	}
	else{
		printf("The prime factorization of %d is: ", num);
		while(num%2==0){
			printf("%d ", 2);
			num/=2;
		}
		for(int i=3;i<=num;i+=2){
			while(num%i==0){
				printf("%d ", i);
				num=num/i;
			}
		}
	}
	puts("");
	return 0;
}
