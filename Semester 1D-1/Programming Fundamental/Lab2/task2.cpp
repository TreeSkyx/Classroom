// GDC Calculator (Two number)
#include <stdio.h>
#include <math.h>
int main(){
	int a,b,x,y,temp,gcd=1;
	printf("Enter first number : ");
	scanf("%d",&a);
	printf("Enter second number : ");
	scanf("%d",&b);
	x=abs(a);
	y=abs(b);
	while(y!=0){
		temp = y;
		y = x%y;
		x = temp;
	}
	gcd = x;
	printf("Greatest common divisor = %d",gcd);
	return 0;
}
