#include <stdio.h>
#include <stdbool.h>

int primes(int n){
	int count=0;
	int numInc=2;
	bool isPrime=true;
	int last;
	while(count<n){
		for(int i=numInc-1;i>1;i--){
			if(numInc%i==0){
				isPrime=false;
			}
			
		}		
		if(isPrime){
			last=numInc;
			count++;
		}
		numInc++;
		isPrime=true;
	}
	return last;
}

float pow(float a, int b){
	float ans=a;
	if(b==0){
		return 1;
	}
	else if(b>0){
		for(int i=0;i<b-1;i++){
			ans*=a;
		}
	}
	return ans;
}

int factorial(int a){
	int ans=a;
	for(int i=a-1;i>0;i--){
		ans*=i;
	}
	return ans;
}

int main(void){
	float x;
	int n,l,r;
	printf("%s", "Enter the value of X: ");
	scanf("%f", &x);
	printf("%s", "Enter the value of n: ");
	scanf("%d", &n);
	printf("%s", "Enter the value of L: ");
	scanf("%d", &l);
	printf("%s", "Enter the value of R: ");
	scanf("%d", &r);
	int count=1;
	int primeTotal=0;
	while(primes(count)<r){
		if(primes(count)>l&&primes(count)<r){
			primeTotal+=primes(count);
		}
		count++;
	}
	float xTotal=0;
	for(int i=1;i<=n;i++){
		xTotal+=(pow(x,i)/factorial(i));
	}
	float finalTotal=xTotal+primeTotal;
	printf("Sum of series: %f\n", finalTotal);
	
	return 0;
}
