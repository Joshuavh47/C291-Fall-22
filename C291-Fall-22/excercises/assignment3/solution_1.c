#include <stdio.h>

int main(void){
	char site[2] = "";
	for(int i=97;i<=122;i++){
		site[0]=(char)i;
		for(int j=97;j<=122;j++){
			site[1]=(char)j;
			printf("www.%c%c.com\n", site[0], site[1]);
		}
	}
	return 0;
}
