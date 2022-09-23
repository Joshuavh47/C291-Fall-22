#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int rollDice(void){
	return (rand()%6)+1;
}
int getSum(int a, int b){
	return a+b;
}
int checkCraps(int score){
	if(score==7||score==11){
		puts("You win!");
		return 0;
	}
	else if(score==2||score==3||score==12){
		puts("You lose, house wins.");
		return 1;
	}
	else{
		return 2;
	}
}
int main(void){
	srand(time(NULL));
	char play;
	printf("%s", "Would you like to play a game of craps? Type y for yes or n for no: ");
	scanf("%c", &play);
	int firstPoint;
	int point;
	int sum;
	int a,b;
	int lastSum;
	if(play=='y'||play=='Y'){
		a=rollDice();
		b=rollDice();
		sum=getSum(a,b);
		point=sum;
		lastSum=sum;
		printf("Dice is rolling...\nScore on dice: %d and %d\nSum: %d\n", a, b, sum);
		sum=0;
		if(checkCraps(lastSum)==2){
			while(checkCraps(sum)==2&&sum!=point&&lastSum!=sum){
				lastSum=sum;
				sum=0;
				a=rollDice();
				b=rollDice();
				sum=getSum(a,b);
				printf("Dice is rolling...\nScore on dice: %d and %d\nSum: %d\n", a, b, sum);
				if(checkCraps(sum)==2){
					if(lastSum==sum){
						puts("Consecutive sums. You Win!");
					}
				}
				else{
					checkCraps(sum);
					return 0;
				}
				if(sum==firstPoint){
					puts("You Win!");
					return 0;
				}
			}
		}
		else{
			return 0;		
		}
	}
	
	return 0;
}
