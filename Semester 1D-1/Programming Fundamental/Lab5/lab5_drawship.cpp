#include <stdio.h>
#include <windows.h>
#include <conio.h>
void draw_ship(int,int);
void erase_ship(int,int);
int main(){
	char ch=' ';
	int x=38,y=20;
	draw_ship(x,y);
	do {
		if(_kbhit()){
			ch=_getch();
			if(ch=='a'){
				--x;
				if(x>0)draw_ship(x,y);
				else x=1;
			}
			if(ch=='d') {
				++x;
				if(x<81)draw_ship(x,y);
				else x=80;
			}
			if(ch=='w'){
				if(y>0){
					erase_ship(x,y);
					draw_ship(x,--y);
				}
				else y=0;
			}
			if(ch=='s') {
				
				if(y<24){
					erase_ship(x,y);
					draw_ship(x,++y);
				}
				else y=24;
			}
			fflush(stdin);
		}
		Sleep(100);
	} while(ch!='x');
	return 0;
}
void draw_ship(int x, int y){
	COORD c = { x, y };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , c);
	printf(" <-0-> ");
}
void erase_ship(int x, int y){
	COORD c = { x, y };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , c);
	printf("       ");
}

