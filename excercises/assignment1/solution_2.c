#include <stdio.h>

int main(void){
	int month=0;
	printf("Enter current month: ");
	scanf("%d", &month);
	int year = 0;
	printf("\nEnter current year: ");
	scanf("%d", &year);
	int age = 0;
	printf("\nEnter your age: ");
	scanf("%d", &age);
	printf("\nIt is month %d of year %d and you are %d years old!\n", month, year, age);
	return 0;
}
