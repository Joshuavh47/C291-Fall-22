#include <stdio.h>

int main(void){
	float radius =0;
	printf("Enter the radius: ");
	scanf("%f", &radius);
	float area = 3.14159*radius*radius;
	float diameter = 2*radius;
	float circumference = 2*3.14159*radius;
	printf("\nThe area of a circle with radius %f is %f\n", radius, area);
	printf("The diameter of a circle with the radius %f is %f\n", radius, diameter);
	printf("The circumference is a circle with radius %f is %f\n", radius, circumference);
	return 0;

}
