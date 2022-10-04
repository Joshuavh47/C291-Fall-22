#include <stdio.h>


void generateKGrams(int n, int k, char input[], char kGrams[][k+1], int l){
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			kGrams[i][j]=input[i+j];
		}
	}
	
}

void printKGrams(int l, int k, char kGrams[][k+1]){
	for(int i=0;i<l-k+1;i++){
		for(int j=0;j<k;j++){
			printf("%c",kGrams[i][j]);
		}
		puts("");
	}
}

int length(char str[]){
	return sizeof(str)-1;
}

int main(void){
	char str[]="hello";
	int k=2;
	char kGrams[length(str)-k+1][k+1];
	generateKGrams(length(str)-k+1, k, str, kGrams, length(str));
	printKGrams(length(str), k, kGrams);
	return 0;
}

