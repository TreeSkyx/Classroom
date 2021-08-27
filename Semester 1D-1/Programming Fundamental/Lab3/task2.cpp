//LAB3
// task : P(x) be the sum of the number from 1 to n that is evenly divisible to x
// write program to finding the number 1 to 10,000 which number give the value P(x) = x 
#include <stdio.h>
int main() {
	int n,i,j,sum=0;
	for(i=1;i<=10000;i++){
		for(j=1;j<i;j++){
			if(i%j==0){
				sum = sum + j;
			}
		}
		if(i==sum) printf("%d\n",i);
		sum=0;
	}
	return 0;
}
