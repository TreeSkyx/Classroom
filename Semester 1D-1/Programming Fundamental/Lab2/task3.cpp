// Rectangle
#include <stdio.h>
int main(){
	int n,i,j;
	printf("Enter number : ");
	scanf("%d",&n);
	if(n>1) // * doesn't count as a square 
	{ 
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==0 || i==n-1) printf("*");
				else if(j==0 || j==n-1) printf("*");
				else if(j!=0 || j!=n-1) printf(" ");		
			}
			printf("\n");
		}
	}else printf("error");
	
	return 0;
}
