#include <stdio.h>

int main(void){
	int num;
	printf("%s", "Pick a starting number: ");
	scanf("%d", &num);
	puts("");
	int count=0;
	if (num<=0){
		puts("Number must be positive and non 0.");
	}
	else{
		for(int i=0;i<num;i){
			if(num%15==0){
				printf("%s","Fizz-Buzz ");
				num--;
				count++;
			}
			else if(num%5==0){
				printf("%s", "Buzz ");
				num--;
				count++;
			}
			else if(num%3==0){
				printf("%s", "Fizz ");
				num--;
				count++;
			}
			else{
				printf("%d ", num);
				num--;
				count++;
			}
			if(count%4==0){
				puts("");
			}
		}
	}
	puts("");
	return 0;
}
