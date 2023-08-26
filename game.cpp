#include "src.h"
#include "pages.h"

#define MAP_COUNT 100

#define MAP_Y 20
#define MAP_X 50

#define MAX_MAPNAME 40
#define MIN_MAPNAME 3

struct Map{
	string name;
	int map[MAP_Y][MAP_X];
	int start_x;
	int start_y;
};

struct Player{
	int pos_x;
	int pos_y;
	
	int key;
}mainPlayer;

Map mainMap[MAP_COUNT];

int openCreatedMaze(){
	pageCls(); 
	gotoxy(0, 0);
	printStr("OPEN CREATED MAZE");
	
	
	pauseNUL;
}

int mazeMake(){
	pageCls();
	Map tempMap;
	int step = 1;
	
while(1){
	// page name print 
	cls;
	gotoxy(0, 0);
	setColor(WHITE);
	printStr("MAZE MAKE");
	
	// page step print
	gotoxy(0, 2);
	printStr("STEP ");
	cout<<step;
	printStr("/3");
	
	switch(step){
		case 1:
			while(1){
				gotoxy(0, 3);
				printStr("Enter the name of the map to create.");
				gotoxy(0, 4);
				setColor(GRAY);
				cout<<"Please enter at least "<<MIN_MAPNAME<<" characters and at least "<<MAX_MAPNAME<<" characters (English standard).";
				setColor(WHITE);
				
				// 맵 이름 입력 
				gotoxy(0, 6);
				setColor(WHITE);
				printStr("> ");
					
				cursorVisible(true);
				getline(cin, tempMap.name);
				cursorVisible(false);
				
				if(!(tempMap.name.size() >= MIN_MAPNAME)){
					setColor(RED);
					gotoxy(0, 8);
					clsBack;
					gotoxy(0, 8); 
					printStr("Enter at least ");
					cout<<MIN_MAPNAME;
					printStr(" characters. Please enter again.");
					
					gotoxy(0, 9);
					setColor(WHITE);
					pause;
					
					break;
				}
				if (!(tempMap.name.size() <= MAX_MAPNAME)) { // 길이 검사
			        setColor(RED);
					gotoxy(0, 8);
					printStr("Enter at least ");
					cout<<MAX_MAPNAME;
					printStr(" characters. Please enter again.");
					
					gotoxy(0, 9);
					setColor(WHITE);
					pause;
					
					break;
			    }
			    
			    setColor(WHITE);
				gotoxy(0, 9);
				cout<<"["<<tempMap.name<<"] ";
				gotoxy(0, 10);
				printStr("Would you like to use this name?");
				
				step++;
				pause;
				break;
			}
			break;
			
		case 2:
			gotoxy(0, 3);
			printStr("draw a maze");
			
			step++;
			pause;
			break;
			
		case 3:
			gotoxy(0, 3);
			printStr("Would you like to make a maze like this?");
			
			step++;
			pause;
			break;
			
	}
	if(step==4)
		return 0;
}
	
	
	
	
	
	
	
	
	gotoxy(8, 0);
	cout<<"";
	
	
	pauseNUL;
}
