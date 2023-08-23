#include "src.h"
#include "pages.h"
using namespace std;

#define Version "1.0"

int initGame();

int main(){
	int selNum;
	initGame();
	
	while(1){
	//	1 Play
	//	2 Make ground
	//	3 Control rule
	//	4 Exit
		pageCls();
		selNum = startPage();
		pageCls();
		switch(selNum){
			case 1:
				playPage();
				break;
				
			case 2:
				makePage();
				break;
				
			case 3:
				manualPage();
				break;
				
			case 4:
				exitPage();
				break;
		}
	}
}

int initGame(){
	system("title Maze Maker "Version);
	srand(time(NULL));
	CursorVisible(false);
}


