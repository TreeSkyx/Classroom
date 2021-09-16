//week7_program2
#include <stdio.h>
#include <string.h>
int main(){
	char t[100],a[1],f[100];
	int len=0,count=0,i;
	scanf("%[^\n]",t);
	scanf("%s",&a[0]);
	len = (strlen(t)-1);
	while(len>=0){
		if(t[len]!=a[0]){
			f[count]=t[len];
			count++;	
		}
		len--;
	}
	for(i=count-1;i>=0;i--){
		printf("%c",f[i]);
	}
	return 0;
}
