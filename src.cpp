#include <iostream>
#include <windows.h>
using namespace std;

#define pause system("pause")
#define pauseNUL system("pause > nul")
#define cls system("cls")

#define delay Sleep(1)

void SetColor(int color){
	/*  0  // 검정색
		1  // 파랑색
		2  // 초록색
		3  // 옥색
		4  // 빨간색
		5  // 자주색
		6  // 노란색
		7  // 흰색
		8  // 회색
		9  // 연한 파란색
		10 // 연한 초록색
		11 // 연한 옥색
		12 // 연한 빨간색
		13 // 연한 자주색
		14 // 연한 노란색
		15 // 진한 흰색    */
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorVisible(int Visible) {
	// -1 받으면 기본값으로 
	if(Visible == -1)
		Visible = 1;
	
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = (Visible == 1) ? TRUE : FALSE;      //커서 Visible TRUE(보임) FALSE(숨김)
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

// 부드럽게 문자 출력
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
