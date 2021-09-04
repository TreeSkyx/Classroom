//week5_program2
#include <stdio.h>
int recPrint(int);
int n;
int main(){
	scanf("%d",&n);
	if(n>1){ // * isn't count as rectangle && length > 0
		recPrint(n);
	}
	else printf("ERROR");
	return 0;
}
int recPrint(int x){
	if(x==0){
		return 0;
	}
	else{
		for(int i=0;i<n;i++) printf("*");
		printf("\n");
	}
	return recPrint(x-1);
}
