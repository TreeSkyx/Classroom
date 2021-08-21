//week3_program1
#include <stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	if(n>0){
		for(i=0;i<n;i++){
		printf("*");
		}
	}else printf("Error");
	return 0;
}
