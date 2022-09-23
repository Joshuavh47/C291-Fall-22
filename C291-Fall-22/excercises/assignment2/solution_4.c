#include <stdio.h>
#include <stdbool.h>

int main(void){
	int year;
	int month;
	int day;
	bool valid;
	puts("Enter the year: ");
	scanf("%d", &year);
	puts("Enter the month: ");
	scanf("%d", &month);
	puts("Enter the day: ");
	scanf("%d", &day);
	if(year>0){
		if(month>0&&month<=12){
			if(month==1){
				if(day>0&&day<=31){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else if(month==2){
				if(year%4==0){
					if(day>0&&day<=29){
						valid=true;
					}
				}
				else{
					if(day>0&&day<=28){
						valid=false;
					}
					else{
						valid=false;
					}
				}
			}
			else if(month==3){
				if(day>0&&day<=31){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else if(month==4){
				if(day>0&&day<=30){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else if(month==5){
				if(day>0&&day<=31){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else if(month==6){
				if(day>0&&day<=30){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else if(month==7){
				if(day>0&&day<=31){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else if(month==8){
				if(day>0&&day<=31){
					valid=true;
				}
				else{
					valid==false;
				}
			}
			else if(month==9){
				if(day>0&&day<=30){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else if (month==10){
				if(day>0&&day<=31){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else if(month=11){
				if(day>0&&day<=30){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else if(month==12){
				if(day>0&&day<=31){
					valid=true;
				}
				else{
					valid=false;
				}
			}
			else{
				valid=false;
			}
		}
		else{
			valid=false;
		}
	}
	else{
		valid=false;
	}
	if(valid){
		puts("The date is valid.");
	}
	else{
		puts("The date is invalid.");
	}
	return 0;
}
