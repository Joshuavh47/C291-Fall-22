#include <stdio.h>

int main(void){
	int num;
	printf("%s", "Enter an odd number of rows: ");
	scanf("%d", &num);
	puts("");
	if(num%2!=1){
		puts("Number of rows must be odd.");
		return 0;
	}
	else{
		for(int i=1;i<=(num-1)/2+1;i++){
			for(int j=(num-1)/2-i+1;j>0;j--){
				printf("%c", ' ');
			}
			for(int k=1;k<=i*2-1;k++){
				printf("%c", '*');
			}
			puts("");
		}
		for(int i=(num-1)/2;i>=1;i--){
			for(int j=1;j<=(num-1)/2-i+1;j++){
				printf("%c", ' ');
			}
			for(int k=i*2-1;k>=1;k--){
				printf("%c", '*');
			}
			puts("");
		}
	}
	return 0;
}
