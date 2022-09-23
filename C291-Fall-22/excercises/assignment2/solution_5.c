#include <stdio.h>
#include <stdbool.h>

int main(void){
	char eType;
	double salary;
	double overtime;
	bool vacation;
	int prodSold;
	double hoursWeek;
	bool isMarried;
	char married;
	char vac;
	double total;
	double taxTotal;
	double hours;

	puts("What is your employee code: ");
	scanf("%s", &eType);
	puts("Are you married: ");
	scanf("%s", &married);
	if(married=='y'||married=='Y'){
		isMarried=true;
	}
	else if(married=='n'||married=='N'){
		isMarried=false;
	}
	if(eType=='a'||eType=='A'){
		puts("What is your monthly salary: ");
		scanf("%lf", &salary);
		total=salary*12;
	}
	else if(eType=='S'||eType=='s'){
		puts("What is your monthly salary: ");
		scanf("%lf", &salary);
		puts("How many hours of overtime did you work this month: ");
		scanf("%lf", &overtime);
		if(overtime>10){
			overtime=10;
		}
		else if(overtime<0){
			overtime=0;
		}
		total=salary*12+(12*salary/160*overtime*1.5);
	}
	else if(eType=='e'||eType=='E'){
		puts("What is your monthly salary: ");
		scanf("%lf", &salary);
		puts("How many hours of overtime did you work this month: ");
		scanf("%lf", &overtime);
		if(overtime>20){
			overtime=20;
		}
		else if(overtime<0){
			overtime=0;
		}
		puts("Did you take a vacation this year (y/n)");
		scanf("%s", &vac);
		if(vac=='y'||vac=='Y'){
			vacation=true;
			salary/=2;
		}
		else if(vac=='n'||vac=='N'){
			vacation=false;
		}
		puts("How many products did you sell: ");
		scanf("%d", &prodSold);
		total=salary*12+(12*salary/160*overtime*1.35)+(prodSold*600);
	}
	else if(eType=='p'||eType=='P'){
		puts("What is your weekly salary: ");
		scanf("%lf", &salary);
		puts("How many hours of overtime do you work each week: ");
		scanf("%lf", &overtime);
		if(overtime>10){
			overtime=10;
		}
		else if(overtime<0){
			overtime=0;
		}
		puts("How many products did you sell: ");
		scanf("%d", &prodSold);
		total=salary*52+(52*overtime*salary/40)+(prodSold*600);
	}
	else if(eType=='h'||eType=='H'){
		puts("What is your hourly salarly: ");
		scanf("%lf", &salary);
		puts("How many hours do you work a week in total: ");
		scanf("%lf", &hours);
		if(hours>10){
			if(hours>20){
				overtime=10;
				hours=10;
			}
			else{
				overtime=hours-10;
				hours=10;
			}
		}
		else if(hours<=10&&hours>=0){
			overtime=0;
		}
		else{
			hours=0;
			overtime=0;
		}
		total=salary*hours*52+(salary*overtime*1.25*52);
	}
	if(salary<0||hours<0||overtime<0){
		puts("Invalid input.");
		return 0;
	}
	if(married){
		if(total>32000){
			taxTotal=total-(total*.25);
		}
		else{
			taxTotal=total-(total*.1);
		}
	}
	else{
		if(total>64000){
			taxTotal=total-(total*.25);
		}
		else{
			taxTotal=total-(total*.1);
		}
	}
	printf("This employee's annual income is $%.2lf before tax and $%.2lf after tax.\n", total, taxTotal);
	return 0;
}
