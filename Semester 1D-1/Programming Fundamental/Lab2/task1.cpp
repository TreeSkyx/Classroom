//Factoring Number
#include <stdio.h>
int main(){
    int n,x = 2;
    printf("Enter number : ");
    scanf("%d", &n);
    printf("Factoring Result : ");
    while(n != 1){
        while(n % x == 0){
            printf("%d", x);
            n = n / x;
            if(n!=1){
            	printf(" x ");
			}
        }
        x++;
    }
    return 0;
}

