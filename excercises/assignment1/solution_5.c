#include <stdio.h>

int main(void){
	float a = 0;
	float d = 0;
	int n = 0;
	printf("Enter the starting number of the AP series: ");
	scanf("%f", &a);
	printf("\nEnter the common difference: ");
	scanf("%f", &d);
	printf("\nEnter the Nth term to be found: ");
	scanf("%d", &n);
	float answer = ((n-1)*d)+a;
	printf("\nThe %d term of the series is %f\n", n, answer);
	return 0;
}
