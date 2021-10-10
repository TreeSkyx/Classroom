#include <stdio.h>
#include <windows.h>
#include <time.h>
#define scount 80
#define screen_x 80
#define screen_y 25
HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = {0,0,screen_x-1,screen_y-1};
COORD star[scount];
int lifepoint=10;
int color=7;
int posX; int posY;
bool play = true;
int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}
void clear_buffer()
{
	for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}
void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}
void init_star()
{
	int k;
	for(k=0;k<scount;k++){
	star[k]= {SHORT(rand()%screen_x),SHORT(rand()%screen_y)};
	}
}
void star_fall()
{
	int i;
	for (i = 0; i < scount; i++) {
		if (star[i].Y >= screen_y-1) {
			star[i] = {SHORT(rand() % screen_x),1};
		}
		else {
			star[i] = {star[i].X,SHORT(star[i].Y+1)};
		}
	}
}
void hitCheck(){
	for(int i=0;i<scount;i++){
		if((star[i].X==posX || star[i].X==posX+1 || star[i].X==posX-1) && star[i].Y==posY){
			star[i] = {SHORT(rand() % screen_x),1};
			lifepoint--;
		}
		if(lifepoint==0){
			play = false;
		}	
	}
}
void fill_star_to_buffer()
{
	for(int i=0;i<scount;i++){
		consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
		consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
	}
}
void ship_colorChange(){
	color=(rand()%255);
}
void draw_ship_to_buffer(int x, int y){
	consoleBuffer[x + screen_x * y].Char.AsciiChar = '0';
	consoleBuffer[x-1 + screen_x * y].Char.AsciiChar = '<';
	consoleBuffer[x+1 + screen_x * y].Char.AsciiChar = '>';
	consoleBuffer[x + screen_x * y].Attributes = color;
	consoleBuffer[x+1 + screen_x * y].Attributes = color;
	consoleBuffer[x-1 + screen_x * y].Attributes = color;
}
int main()
{
	setConsole(screen_x, screen_y);
	srand(time(NULL));
	setMode();
	init_star();
	int i=0;
	while (play)
	{
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) {
		INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
		ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
		for (DWORD i = 0; i < numEventsRead; ++i) {
			if (eventBuffer[i].EventType == KEY_EVENT &&
				eventBuffer[i].Event.KeyEvent.bKeyDown == true ) {
				if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
					play = false;
				}
			}
			else if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar=='C' ||
					(eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)){
				ship_colorChange();				
			}
			else if (eventBuffer[i].EventType == MOUSE_EVENT) {
			int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
			int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
				if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
					posX = posx;
					posY = posy;
				}		
				}
			}
			delete[] eventBuffer;
		}
		star_fall();
		clear_buffer();
		hitCheck();
		fill_star_to_buffer();
		draw_ship_to_buffer(posX,posY);
		fill_buffer_to_console();
		Sleep(100);
	}
return 0;
}
