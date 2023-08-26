#include "src.h"
#include "game.h"
using namespace std;

int exitPage();
void pageCls();

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
	cls;
}

int startPage(){
	int selNum = 0;
	
	char mainStr[10][51] = {
		"Welcome to Maze Maker!",
		"Please select this menu.",
		"",
		""
	};
	char menuStr[4][21] = {
		"Play",
		"Make Maze",
		"Manual",
		"Exit" 
	};
	
	// mainStr Print
	for(int i=0; i<10; i++){
		gotoxy(0, i);
		printStr(mainStr[i]);
	}
	
	// menu Select & Print
	gotoxy(0, 19);
	setColor(WHITE);
	printStr("Use the number key!");
	
	gotoxy(0, 17);
	setColor(GRAY);
	printStr("(For how to use, check the manual by pressing the [3] key.)");
	clsBack;
	setColor(WHITE);
	
	for(int i=0; i<4; i++){
		gotoxy(0, i+7);
		cout<<"["<<i+1<<"] ";
		for(int l=0; menuStr[i][l]!='\0'; l++){
			cout<<menuStr[i][l];
			delay;
		}
	}
	
	while(1){
		gotoxy(0, 19);
		setColor(WHITE);
		
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
					clsBack;
					gotoxy(0, 19);
					setColor(RED);
					printStr("Please select menu");
					
					continue;
				}
				clsBack;
				
				return selNum;
			
			default:
				selNum=0;
				clsBack;
				gotoxy(0, 19);
				setColor(RED);
				printStr("Please check your input");
				
				continue;
		}
		
		gotoxy(0, 19);
		clsBack;
		gotoxy(0, 19);
		setColor(darkWHITE);
		printStr(menuStr[selNum-1]);
		
		setColor(WHITE);
		printStr(" << Select this menu? [Enter]");
		clsBack;
	}
	
	cout<<endl<<endl<<endl;
}

int playPage(){
	gotoxy(0, 0);
	setColor(WHITE);
	printStr("In Game Page...");
	gotoxy(0, 1);
	pause;
}

int makePage(){
	int selNum = 0;
	int mzmkSelNum = 0;
	
	char menuStr[4][21] = {
		"Open created maze",
		"Maze Make",
		"Cancle"
	};
	
	gotoxy(0, 0);
	setColor(WHITE);
	printStr("MAKE GAME");
	
	// menu bottom Print
	gotoxy(0, 17);
	setColor(WHITE);
	printStr("Use the number key!");
	
	// mainStr Print
	for(int i=0; i<3; i++){
		gotoxy(0, i+7);
		cout<<"["<<i+1<<"] ";
		for(int l=0; menuStr[i][l]!='\0'; l++){
			cout<<menuStr[i][l];
			delay;
		}
	}
	
	while(1){
		gotoxy(0, 17);
		setColor(WHITE);
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
			
			case kCtrlC:
				pageCls();
				return 4;
			
			case kEnter:
				if(selNum == 0){
					clsBack;
					gotoxy(0, 17);
					setColor(RED);
					printStr("Please select menu");
					continue;
				}
				clsBack;
				
				switch(selNum){
					case 1:
						openCreatedMaze();
						return 0;
						
					case 2:
						while(1){
							mzmkSelNum = mazeMake();
							if(mzmkSelNum == 0)
								break;
							
							if(mzmkSelNum == 1)
								continue;
						}
						return 0;
					
					case 3:
						return 0;
				}
			
			default:
				selNum=0;
				clsBack;
				
				gotoxy(0, 17);
				setColor(RED);
				printStr("Please check your input");
				continue;
		}
		
		gotoxy(0, 17);
		clsBack;
		gotoxy(0, 17);
		setColor(darkWHITE);
		printStr(menuStr[selNum-1]);
		
		setColor(WHITE);
		printStr(" << Select this menu? [Enter]");
		clsBack;
	}
	
	
	pause;
}

int manualPage(){
	int pageMax=3;
	int pageNum=0;
	
	char manualStr[pageMax][14][100]{
		{
			// page 1
			{"How to use / caution"},
			{""},
			{"You can enter by entering the number in the list in the menu window with the key."},
			{""},
			{"In the 'Play' window, you can play the basic maze."},
			{"In the 'Make maze' window, you can make and play your own maze."},
			{"In the 'Manual' window, you can see various explanations as you do now."},
			{"In the 'Quit' window, you can go to the quit page  the program."},
			{"You can go to the Quit page by pressing Ctrl + C."},
			{""},
			{"Always after all the animations are over, press the key."},
			{""},
			{"Have a good time. good bye!"},
			{"Made by suzukaotto. [https://github.com/suzukaotto]"}
		},
		{
			// page 2
			{"How to play?"},
			{""},
			{"It is a game to clear the maze and make it."},
			{".."},
			{".."},
			{".."},
			{".."},
			{".."},
			{".."},
			{".."},
			{".."},
			{".."},
			{".."}
		},
		{
			// page 3
			{"Key operation"},
			{"..."},
			{"..."},
			{"..."},
			{"..."},
			{"..."},
			{"..."},
			{"..."},
			{"..."},
			{"..."},
			{"..."},
			{"..."},
			{"..."}
		}
	};
	
	// manual print & page change
	gotoxy(0, 0);
	printStr("MANUAL");
	
	gotoxy(0, 23);
	printStr("Z [Back] : X [Quit] : C [Next]");
	while(1){
		gotoxy(20, 21);
		clsBack;
		
		gotoxy(0, 21);
		cout<<pageNum+1<<"/"<<pageMax;
		
		// 설명 부분 재출력 
		for(int i=0; i<14; i++){
			gotoxy(0, i+3);
			for(int l=0; l<100; l++)
				cout<<" ";
			gotoxy(0, i+3);
			cout<<manualStr[pageNum][i];
		}
		
		while(1){
			switch(getch()){
				case kx:
					return 0;
				case kX:
					return 0;
				
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
					return 4;
			}
			
			if(pageNum < 0 || pageNum >= pageMax){
				gotoxy(20, 21);
				clsBack;
				gotoxy(20, 21);
				setColor(RED);
				
				if(pageNum < 0){
					pageNum=0;
					printStr("There are no pages below!");
				} else {
					pageNum=(pageMax-1);
					printStr("There is no next page!");
					clsBack;
				}
				setColor(WHITE);
				continue;
			}
			break;
		}
		
	}
	pause;
}

int exitPage(){
	int time_val;
	
	gotoxy(0, 0);
	setColor(WHITE);
	printStr("Are you sure you want to quit?");
	
	gotoxy(0, 1);
	setColor(RED);
	printStr("All data using will be deleted.");
	
	gotoxy(0, 2);
	setColor(WHITE);
	printStr("To exit, press the [ESC] key.");
	
	gotoxy(0, 3);
	setColor(GRAY);
	printStr("(Pressing any other key cancels the quit.)");
	
	gotoxy(0, 4);
	setColor(WHITE);
	printStr("> ");
	
	cursorVisible(true);
	int key = getch();
	cursorVisible(false);
	
	switch(key){
		case kEsc:
			cout<<"ESC";
			
			gotoxy(0, 7);
			printStr("It will automatically shut down after the time below.");
			
			// shutdown cancle
			time_val = clock()+10000;
			while(time_val-clock() >= 0){
				gotoxy(0, 8);
				cout<<"To cancel shutdown, press [ESC] within "<<time_val-clock()<<" seconds.    ";
			}
			
			gotoxy(0, 10);
			printStr("It's over. Good Bye!");
			
			Sleep(1000);
			pageCls();
			cls;
			exit(0);
			
		default:
			cout<<static_cast<char>(key);
			
			gotoxy(0, 7);
			printStr("Quit canceled.");
			
			gotoxy(0, 8);
			printStr("Press any key to return . . .");
			
			pauseNUL;
			return 0;
	}
}
