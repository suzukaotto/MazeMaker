#include <iostream>
#include <windows.h>
using namespace std;

#define pause system("pause")
#define pauseNUL system("pause > nul")
#define cls system("cls")

#define delay Sleep(1)

void SetColor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorVisible(int Visible) {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = (Visible == 1) ? TRUE : FALSE;      //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y){
	COORD pos = { x+10, y+3 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxy_normal(int x, int y){
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// �ε巴�� ���� ���
void printStr(char Str[]){
	for(int i=0; Str[i]!='\0'; i++){
		cout<<Str[i];
		delay;
	}
}
void* printStr(char* Str[]){
	for(int i=0; Str[i]!='\0'; i++){
		cout<<Str[i];
		delay;
	}
}
