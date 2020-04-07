#include <stdio.h>
#include <windows.h> 

//키보드 값
#define UP 0
#define DOWN 1
#define SUBMIT 3 //선택 
/* 함수 선언 */
int keyControl();
void init();
int menuDraw();
void gotoxy(int, int);

int main() {
	init();
	menuDraw();
	
	return 0;
}

int keyControl(){
	char temp = getch();
	
	if(temp == 'w'){
		return UP;
	}else if(temp == 's'){
		return DOWN;
	}else if(temp == ' '){
		return SUBMIT;
	}
}

void init(){
	system("title Contact Managment System");
}

int menuDraw(){
	int x = 20;
	int y = 6;
	gotoxy(12, 1);
	printf("**** Welcome to Contact Management System ****");
	gotoxy(27, 4);
	printf("MAIN MENU");
	gotoxy(x, 5);
	printf("======================");
	gotoxy(x-2, y);
	printf("> [1] Add a new Contact");
	gotoxy(x, y+1);
	printf("[2] List all Contacts");
	gotoxy(x, y+2);
	printf("[3] Search for contact");
	gotoxy(x, y+3);
	printf("[4] Edit a Contact");
	gotoxy(x, y+4);
	printf("[5] Delete a Contact");
	gotoxy(x, y+5);
	printf("[6] Easter Egg");
	gotoxy(x, y+6);
	printf("[0] Exit");
	gotoxy(x, 13);
	printf("======================");
	gotoxy(x, 14);
	printf("Enter the choice:");
	
	while(1){
		int n = keyControl();
		switch(n){
			case UP: {
				if(y > 6){
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, --y);
					printf(">");
				}
				break;
			}
			
			case DOWN: {
				if(y < 12){
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y-6;
			}
		}
	}
}

//커서 위치 이동 함수
void gotoxy(int x, int y){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
} 

