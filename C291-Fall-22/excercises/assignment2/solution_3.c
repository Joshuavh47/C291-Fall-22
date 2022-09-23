#include <stdio.h>
#include <math.h>

int main(void){
	double first;
	char opp;
	double second;
	double ans;
	puts("Enter first number: ");
	scanf("%lf", &first);
	puts("Enter the opperation: ");
	scanf("%s", &opp);
	puts("Enter the second number: ");
	scanf("%lf", &second);
	switch(opp){
		case '+':
			ans=first+second;
			printf("%.2lf", ans);
			break;
	
		case '-':
			ans=first-second;
			break;
	
		case '*':
			ans=first*second;
			break;
	
		case '/':
			if(second!=0){
				ans=first/second;
			}
			else{
				puts("Error: dividing by 0");
				return 0;
			}
			break;
	
		case '%':
			ans=fmod((int)first,(int)second);
			break;
	
		case '^':
			ans=pow(first,second);
			break;
	
		case 'r':
			second=pow(second,-1);
			ans=pow(first, second);
			break;
	}
	printf("Answer: %.2lf\n", ans);
	return 0;

}
