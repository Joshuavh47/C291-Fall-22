#include <stdio.h>
#include <math.h>



int factorial(int num){
	int total=num;
	if(num>0){
		for(int i=num-1;i>0;i--){
			total*=i;
		}
	}
	else if(num==0){
		total=1;
	}
	else{
		total=-100;
	}
	return total;
}
int main(void){
	int k;
	int n;
	float p;
	printf("%s", "Enter a k value: ");
	scanf("%d", &k);
	puts("");
	printf("%s", "Enter an n value: ");
	scanf("%d", &n);
	puts("");
	printf("%s", "Enter a p value: ");
	scanf("%f", &p);
	puts("");
	if(factorial(n)<0||factorial(k)<0){
		puts("n and k must be greaterthan or equal to 0");
		return 0;
	}
	float combination=factorial(n)/(factorial(k)*factorial(n-k));
	float ans=combination*pow(p,k)*pow(1-p,n-k);
	printf("The answer is %f", ans);
	puts("");
	return 0;


}

