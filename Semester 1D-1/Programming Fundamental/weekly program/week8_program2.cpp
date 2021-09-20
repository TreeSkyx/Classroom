//week8_program2
#include <stdio.h>
#include <string.h>
char text[100];
int alp[26];
int alpCheck(int n){
	int textNum;
	if(n<0) {return 0;}
	else{
		if(text[n]>=65 && text[n]<=90){
			textNum = int(text[n]);
			alp[textNum-65]++;
		}
		else if(text[n]>=97 && text[n]<=122){
			textNum = int(text[n]);
			alp[textNum-97]++;
		}
	}
	return alpCheck(n-1);
}
int main(){
	int len,j;
	scanf("%[^\n]",text);
	len = strlen(text);
	alpCheck(len-1);
	for(int i=65;i<=90;i++){
		printf("%c : %d\n",i,alp[i-65]);
	}
	return 0;
}

