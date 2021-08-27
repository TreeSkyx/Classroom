//LAB3
//Add the digits until there is only one left.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sumCal(char x[]){
	int len = strlen(x);
	int i,sum=0;
	char snum[100];
	if(len==1){
		printf("%s",x);
		return 0;
	}
	else{
		for(i=0;i<len;i++){
			sum = sum+(x[i]-48);
		}
		itoa(sum,snum,10);
	}
	return sumCal(snum);
}
int main(){
	int j,len,check=0;
	char n[100];
	scanf("%s",n);
	len = strlen(n);
	for(j=0;j<len;j++){
		if(n[j]>=48&&n[j]<=57) check++;
	}
	if(check==len) sumCal(n);
	else printf("Error");
	return 0;
}
