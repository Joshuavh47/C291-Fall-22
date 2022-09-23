#include <stdio.h>

int main(void){
	int single;
	float income;
	float tax;
	puts("Are you single or married (1=married 0=single)");
	scanf("%d", &single);
	puts("What is your income?: ");
	scanf("%f", &income);
	if(single==0){
		if(income<=32000){
			tax=income*.1;
		}
		else{
			tax=(32000*.1)+(income-32000)*(.25)+3200;
		}
	}
	else if (single==1){
		if(income<=64000){
			tax=income*.1;
		}
		else{
			tax=(64000*.1)+(income-64000)*(.25)+6400;
		}
	}
	printf("You owe $%.2f in taxes\n", tax);
	return 0;
}
