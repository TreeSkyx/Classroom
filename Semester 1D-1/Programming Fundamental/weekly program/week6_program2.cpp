//week6_program2
#include <stdio.h>
int triangleShow(int);
int l=1;
int main(){
	int n,i,j;
	scanf("%d",&n);
	if(n>1){ // *(1) isn't count as triangle
		triangleShow(n);
	}else printf("ERROR"); // number must be greater than 0
	return 0;
}
int triangleShow(int x){
	int j;
	if(x==0){
		return 0;
	}else 
	for(j=0;j<x-(x-l);j++){
			printf("*");
		}
		printf("\n");
		l++;
	return triangleShow(x-1);
}
