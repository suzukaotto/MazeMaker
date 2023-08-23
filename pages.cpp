#include "src.h"
using namespace std;

int exitPage();

void pageCls(){
	int x=MAX_X;
	int y=MAX_Y;
	for(int i=0; i<x; i+=5){
		for(int l=0; l<y; l++){
			gotoxy(i, l);
			cout<<"#####";
		}
		delay;
	}
	for(int i=0; i<x; i+=5){
		for(int l=0; l<y; l++){
			gotoxy(i, l);
			cout<<"     ";
		}
		delay;
	}
}

int startPage(){
	int selNum = 0;
	
	char mainStr[10][51] = {
		"Welcome to Maze Maker!",
		"Made by suzukaotto",
		"",
		"Please select this menu.",
	};
	char menuStr[4][21] = {
		"Play",
		"Make ground",
		"Manual",
		"Exit" 
	};
	
	// mainStr Print
	for(int i=0; i<10; i++){
		gotoxy(0, i);
		printStr(mainStr[i]);
	}
	
	// menu Select & Print
	gotoxy(0, 17);
	SetColor(7);
	printStr("Use the number key!");
	
	gotoxy(0, 18);
	SetColor(8);
	printStr("For how to use, check the manual by pressing the [3] key.");
	clsBack;
	SetColor(7);
	
	for(int i=0; i<4; i++){
		gotoxy(0, i+7);
		cout<<"["<<i+1<<"] ";
		for(int l=0; menuStr[i][l]!='\0'; l++){
			cout<<menuStr[i][l];
			delay;
		}
	}
	
	while(1){
		gotoxy(0, 17);
		SetColor(7);
		switch(getch()){
			case k1:
				selNum=1;
				break;
			
			case k2:
				selNum=2;
				break;
			
			case k3:
				selNum=3;
				break;
			
			case k4:
				selNum=4;
				break;
			
			case kCtrlC:
				return 4;
			
			case kEnter:
				if(selNum == 0){
					SetColor(12);
					printStr("Please select menu");
					clsBack;
					continue;
				}
				printStr("Ok!");
				clsBack;
				Sleep(1000);
				return selNum;
			
			default:
				selNum=0;
				SetColor(12);
				printStr("Please check your input");
				clsBack;
				continue;
		}
		
		gotoxy(0, 17);
		clsBack;
		gotoxy(0, 17);
		SetColor(15);
		printStr(menuStr[selNum-1]);
		
		SetColor(7);
		printStr(" << Select this menu? (Enter)");
		clsBack;
	}
	
	cout<<endl<<endl<<endl;
}

int playPage(){
	gotoxy(0, 0);
	printStr("In Game Page...");
	gotoxy(0, 1);
	pause;
}

int makePage(){
	gotoxy(0, 0);
	printStr("Make Game Page...");
	gotoxy(0, 1);
	pause;
}

void manualPage(){
	int pageMax=3;
	int pageNum=0;
	
	char manualStr[pageMax][13][100]{
		{
			// page 1
			{"How to play?"},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""}
		},
		{
			// page 2
			{"Key operation"},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{"Hello"}
		},
		{
			// page 3
			{"Credit"},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""},
			{""}
		}
	};
	
	// manual print & page change
	gotoxy(0, 0);
	printStr("MANUAL");
	
	gotoxy(0, 23);
	printStr("Z [BackPage] : X [ManualQuit] : C [NextPage]");
	while(1){
		gotoxy(20, 22);
		clsBack;
		
		// 설명 부분 삭제 
		for(int i=0; i<13; i++){
			gotoxy(0, i+3);
			for(int l=0; l<100; l++)
			 cout<<" ";
		}
		// 설명 부분 재출력 
		for(int i=0; i<13; i++){
			gotoxy(0, i+3);
			printStr(manualStr[pageNum][i]);
		}
		
		gotoxy(0, 22);
		cout<<"Now page "<<pageNum+1<<"/"<<pageMax;
		
		while(1){
			switch(getch()){
				case kx:
					return;
				case kX:
					return;
				
				case kz:
					pageNum--;
					break;
				case kZ:
					pageNum--;
					break;
				
				case kc:
					pageNum++;
					break;
				case kC:
					pageNum++;
					break;
				
				case kCtrlC:
					pageCls();
					exitPage();
					return;
			}
			
			if(pageNum < 0 || pageNum >= pageMax){
				gotoxy(20, 22);
				clsBack;
				gotoxy(20, 22);
				SetColor(12);
				
				if(pageNum < 0){
					pageNum=0;
					printStr("There are no pages below!");
				} else {
					pageNum=(pageMax-1);
					printStr("There is no next page!");
					clsBack;
				}
				SetColor(7);
				continue;
			}
			break;
		}
		
	}
	pause;
}

int exitPage(){
	gotoxy(0, 0);
	printStr("Are you sure you want to quit?");
	
	gotoxy(0, 1);
	SetColor(12);
	printStr("All data using will be deleted.");
	SetColor(7);
	
	gotoxy(0, 2);
	printStr("To exit, press the [ESC] key.");
	
	gotoxy(0, 3);
	SetColor(8);
	printStr("(Pressing any other key cancels the quit.)");
	SetColor(7);
	
	gotoxy(0, 4);
	printStr("> ");
	
	int key = getch();
	switch(key){
		case kEsc:
			cout<<"ESC";
			gotoxy(0, 7);
			printStr("It's over. Good Bye!");
			gotoxy(0, 8);
			printStr("Pressing any key closes the window . . .");
			getch();
			pageCls();
			exit(0);
			
		default:
			cout<<static_cast<char>(key);
			gotoxy(0, 7);
			printStr("Quit canceled.");
			gotoxy(0, 8);
			printStr("Press any key to return . . .");
			getch();
			return 0;
	}
}
