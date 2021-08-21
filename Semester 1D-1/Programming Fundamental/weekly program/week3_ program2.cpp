//week3_program2
#include <stdio.h>
int print_Star(int x){
	if(x==0){
		return 0;
	}
	else printf("*");
	return print_Star(x-1);
}
int main(){
	int n;
	scanf("%d",&n);
	if(n>0){
		print_Star(n);
	}else printf("Error");
	return 0;
}

