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

//�Ϲ�Ű 
enum {k0=48, k1, k2, k3, k4, k5, k6, k7, k8, k9};
enum {kA=65, kB, kC, kD, kE, kF, kG, kH, kI, kJ, kK, kL, kM, kN, kO, kP, kQ, kR, kS , kT, kU, kV, kW, kX, kY, kZ};
enum {ka=97, kb, kc, kd, ke, kf, kg, kh, ki, kj, kk, kl, km, kn, ko, kp, kq, kr, ks , kt, ku, kv, kw, kx, ky, kz};
//Ư��Ű 
enum {kCtrlC=3, kEnter=13, kEsc=27, kSpace=32};

void printStr(char Str[]);
void *printStr(char* Str[]);
void SetColor(int color);
void CursorVisible(int Visible);
void gotoxy(int x, int y);
void gotoxy_normal(int x, int y);
