//week1 program1
#include <stdio.h>
int main(){
	float a=0,b=0;
	printf("Enter Number: ");
	scanf("%f %f",&a,&b);
	printf("Plus : %.2f\n",a+b);
	printf("Minus(a-b) : %.2f\n",a-b);
	printf("Minus(b-a) : %.2f\n",b-a);
	printf("Multiplie : %.2f\n",a*b);
	printf("Divide(a/b) : ");
	if(b!=0) printf("%.2f",a/b);
	else printf("Error");
	printf("\nDivide(b/a) : ");
	if(a!=0) printf("%.2f",b/a);
	else printf("Error");
	return 0;
}
