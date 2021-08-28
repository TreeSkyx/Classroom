//week4_program1
#include <stdio.h>
int main(){
	int n[3],i,temp,max;
	for(i=0;i<3;i++){
		scanf("%d",&n[i]);
	}
	max = n[0];
	for(i=0;i<3;i++){
		if(n[i]>max){
			max = n[i];
		}
	}
	printf("%d",max);
	return 0;
}
