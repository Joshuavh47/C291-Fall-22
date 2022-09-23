#include <stdio.h>

int main(void){
	float ang1;
	float ang2;
	float ang3;
	puts("Input first angle: ");
	scanf("%f", &ang1);
	puts("Input second angle: ");
	scanf("%f", &ang2);
	puts("Input third angle: ");
	scanf("%f", &ang3);
	if(ang1>0&&ang2>0&&ang3>0&&ang1+ang2+ang3==180){
		puts("The triangle is valid.");
		if(ang1<90&&ang2<90&&ang3<90){
			puts("The triangle is acute.");
		}
		else if(ang1==90||ang2==90||ang3==90){
			puts("This is a right triangle.");
		}
		else{
			puts("This is an obtuse triangle.");
		}
		if(ang1==ang2||ang2==ang3||ang1==ang3){
			puts("The triangle is isosceles");
			if(ang1==60&&ang2==60&&ang3==60){
				puts("The triangle is equilateral.");
			}
		}
		
	}
	return 0;
}
