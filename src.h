#pragma once

#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

#define MAX_X 100
#define MAX_Y 24

#define pause system("pause")
#define pauseNUL system("pause > nul")
#define cls system("cls")
#define clsBack cout<<"                                                    "
#define delay Sleep(1)

//색깔코드
enum colorType{
	BLACK,       //0
	darkBLUE, 	 //1
	darkGREEN,	 //2
	darkSKYBLUE, //3
	darkRED,     //4
	darkPURPLE,  //5
	darkYELLOW,	 //6
	WHITE,	     //7
	GRAY,        //8
	BLUE,	     //9
	GREEN,	     //10
	SKYBlue,     //11
	RED,	     //12
	PURPLE,	     //13
	YELLOW,	     //14
	darkWHITE    //15
};

//일반키 
enum {k0=48, k1, k2, k3, k4, k5, k6, k7, k8, k9};
enum {kA=65, kB, kC, kD, kE, kF, kG, kH, kI, kJ, kK, kL, kM, kN, kO, kP, kQ, kR, kS , kT, kU, kV, kW, kX, kY, kZ};
enum {ka=97, kb, kc, kd, ke, kf, kg, kh, ki, kj, kk, kl, km, kn, ko, kp, kq, kr, ks , kt, ku, kv, kw, kx, ky, kz};
//특수키 
enum {kCtrlC=3, kEnter=13, kEsc=27, kSpace=32};

void printStr(char Str[]);
void *printStr(char* Str[]);
void SetColor(int color);
void CursorVisible(int Visible);
void gotoxy(int x, int y);
void gotoxy_normal(int x, int y);
