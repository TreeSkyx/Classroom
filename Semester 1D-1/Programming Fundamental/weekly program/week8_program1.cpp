//week8_program1
#include <stdio.h>
#include <string.h>
int main(){
	char text[100];
	int alp[26];
	int len,c,i;
	for(i=0;i<26;i++){
		alp[i]=0;
	}
	scanf("%[^\n]",text);
	len = strlen(text);
	for(i=0;i<len;i++){
		c=int(text[i]);
		alp[c-65]++;
	}
	for(i=0;i<len;i++){
		c=int(text[i]);
		alp[c-97]++;
	}
	for(i=65;i<=90;i++){
		printf("%c : %d\n",i,alp[i-65]);
	}
	return 0;
}
