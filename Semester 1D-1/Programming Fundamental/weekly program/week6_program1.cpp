//week6_program1
#include <stdio.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	if(n>1){ //*(1) isn't count as triangle
		for(i=1;i<=n;i++){
			for(j=0;j<i;j++){
				printf("*");
			}
			printf("\n");
		}
	}else printf("ERROR"); // number must be greater than 0
	return 0;
}
