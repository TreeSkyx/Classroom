//week1 program2
#include <stdio.h>
int main(){
	float n[2];
	printf("Enter Number: ");
	scanf("%f %f",&n[0],&n[1]);
	printf("Plus : %.2f\n",n[0]+n[1]);
	printf("Minus(a-b) : %.2f\n",n[0]-n[1]);
	printf("Minus(b-a) : %.2f\n",n[1]-n[0]);
	printf("Multiplie : %.2f\n",n[0]*n[1]);
	printf("Divide(a/b) : ");
	if(n[1]!=0) printf("%.2f",n[0]/n[1]);
	else printf("Error");
	printf("\nDivide(b/a) : ");
	if(n[0]!=0) printf("%.2f",n[1]/n[0]);
	else printf("Error");
	return 0;
}
