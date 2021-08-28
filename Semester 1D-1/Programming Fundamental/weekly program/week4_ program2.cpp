//week4_program2
#include <stdio.h>
int main(){
	int n[3],i,j,temp;
	for(i=0;i<=2;i++){
		scanf("%d",&n[i]);
	}
	for(i=1;i<=2;i++)
	{
		j = i;
		while(j>0 && n[j-1] > n[j]){
			temp = n[j];
			n[j] = n[j-1];
			n[j-1] = temp;
			j--;
		}
	}
	printf("%d",n[2]);
	return 0;
}

