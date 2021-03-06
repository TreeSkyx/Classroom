//LAB06
//Text Mode Game 02
#include <stdio.h>
#include <windows.h>
#include <conio.h>
void draw_ship(int,int);
void erase_ship(int,int);
void setcursor(bool);
void cursorPos(int,int);
void setcolor(int,int);
void erase_color(int,int);
void draw_bullet(int,int);
void bullet_on();
void clear_bullet(int,int);
bool bstat=0;
int bullet[5] = {0,0,0,0,0};
char direct = 'n';
int bx[5],by[5];
int count=0; 
int main(){
	setcursor(0);
	char ch='.';
	int x=38,y=20;
	draw_ship(x,y);
	do {
		do{
			if(_kbhit()){
			ch=_getch();
			if(ch=='a') direct = 'l';
			if(ch=='d') direct = 'r';
			if(ch=='s') direct = 'n';
			if(ch==' ') bstat=1;
			fflush(stdin);
			}
			if(direct=='l'){
				--x;
				if(x>0){
					draw_ship(x,y);	
					erase_color(x+7,y);
				}
				else{direct = 'n'; x=1;}
			}
			if(direct=='r') {
				++x;
				if(x<81){
					draw_ship(x,y);
					erase_color(x-1,y);
				}
				else {direct = 'n'; x=80;}
			}
			if(bullet[count]!=1 && bstat==1) {
				bullet[count]=1;
				bx[count]=x+3;
				by[count]=y-1;
				count++;
				bstat=0;
				ch='.';
			}else bstat=0;
			if(count>4){count=0;}
			bullet_on();
		Sleep(100);
		}while(direct!='n');
		fflush(stdin);
	} while(ch!='x');
	return 0;
}
void cursorPos(int x,int y){
	COORD c = { x, y };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void draw_ship(int x, int y){
	cursorPos(x,y);
	setcolor(7,4); printf(" <");
	setcolor(7,1); printf("-0-");
	setcolor(7,4); printf("> ");
}
void erase_ship(int x, int y){
	cursorPos(x,y);
	setcolor(0,0); printf("       ");
}
void erase_color(int x, int y){
	cursorPos(x,y);
	setcolor(0,0); printf(" ");
}
void draw_bullet(int x, int y){
	cursorPos(x,y);
	setcolor(1,3); printf("^");
}
void clear_bullet(int x,int y){
	cursorPos(x,y);
	setcolor(0,0); printf(" ");
}
void setcursor(bool visible){
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&lpCursor);
}
void setcolor(int fg,int bg){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg*16+fg);
}
void bullet_on(){
	for(int i=0;i<5;i++){
		if (bullet[i]==1) {
			clear_bullet(bx[i],by[i]);
			if (by[i]==0) { bullet[i]=0;}
			else { draw_bullet(bx[i],--by[i]); }
		}
	}
}
