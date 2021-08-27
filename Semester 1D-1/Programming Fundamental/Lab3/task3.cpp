//LAB 3
// Butterfly C Program
#include <stdio.h>
int main(){
	int n,i,j,k,l;
	scanf("%d",&n);
	if(n>1){ // 0 and * don't count as a butterfly
	for(i=1;i<=n-1;i++){
		for(j=1;j<=i;j++){
			printf("* ");
		}
		for(k=i*2;k<=n*2-2;k++){
			printf("  ");
		}
		for(l=1;l<=i;l++){
			printf("* ");
		}
		printf("\n");
	}
	for(i=1;i<n*2;i++){
		printf("* ");
	}
	printf("\n");
	for(i=1;i<=n-1;i++){
		for(j=n-1;j>=i;j--){
			printf("* ");
		}
		for(k=1;k<=i*2-1;k++){
			printf("  ");
		}
		for(l=n-1;l>=i;l--){
			printf("* ");
		}
		printf("\n");
	}
	}else printf("Error");
	return 0;
}
