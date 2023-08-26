#include "src.h"
#include "pages.h"
using namespace std;

#define Version "0.5b"

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
		while(1){
			switch(selNum){
				case 1:
					selNum = playPage();
					break;
					
				case 2:
					selNum = makePage();
					break;
					
				case 3:
					selNum = manualPage();
					break;
					
				case 4:
					selNum = exitPage();
					break;
					
			}
			if(selNum == 4)
				continue;
			
			break;
		}
	}
}

int initGame(){
	SetConsoleTitle("Maze Maker "Version);
	cls;
	srand(time(NULL));
	cursorVisible(false);
}


