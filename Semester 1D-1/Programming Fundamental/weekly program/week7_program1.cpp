//week7_program1
#include <stdio.h>
#include <string.h>
int main(){
	char t[100],a[1];
	int i,len=0;
	scanf("%[^\n]",t);
	scanf("%s",&a[0]);
	len = strlen(t);
	for(i=0;i<len;i++){
		if(t[i]!=a[0]){
			printf("%c",t[i]);
		}
	}
	return 0;
}
