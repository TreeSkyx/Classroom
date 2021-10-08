//week9_program1
#include <stdio.h>
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	printf("Before : x=%d y=%d\n",x,y);
	x=x+y;
	y=x-y;
	x=x-y;
	printf("After : x=%d y=%d",x,y);
	
}
