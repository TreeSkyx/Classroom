//week5_program1
#include <stdio.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	if(n>1){ // * isn't count as rectangle && length > 0
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("*");
			}
			printf("\n");
		}
	}
	else printf("ERROR");
	return 0;
}
