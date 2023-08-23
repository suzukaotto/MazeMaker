#include <iostream>
#include <windows.h>
using namespace std;

#define pause system("pause")
#define pauseNUL system("pause > nul")
#define cls system("cls")

#define delay Sleep(1)

void SetColor(int color){
	/*  0  // ������
		1  // �Ķ���
		2  // �ʷϻ�
		3  // ����
		4  // ������
		5  // ���ֻ�
		6  // �����
		7  // ���
		8  // ȸ��
		9  // ���� �Ķ���
		10 // ���� �ʷϻ�
		11 // ���� ����
		12 // ���� ������
		13 // ���� ���ֻ�
		14 // ���� �����
		15 // ���� ���    */
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CursorVisible(int Visible) {
	// -1 ������ �⺻������ 
	if(Visible == -1)
		Visible = 1;
	
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
