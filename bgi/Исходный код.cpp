// TRON REBORN
#include "graphics.h"
#include<math.h>
//defines
#define STEP 50;
#define KEY_ENTER 13
#define CHAR_SIZE 5
#define VOID_GAME 1
#define CODE_EXIT 0
#define BORDER 50
#define NULL 0
#define HEART_CHAR 3
#define MAX_X getmaxwidth()
#define MAX_Y getmaxheight()
// consts

void game();void init();int menu();
void init()
{
	initwindow(MAX_X,MAX_Y,"TRON REBORN BETA");	
}
int menu()
{
	cleardevice();
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
	char key_pressed=NULL;
	int x=MAX_X/3,y1=MAX_Y/4,y2=y1+STEP;
	const int MAX_SIZE_OPTIONS=1,MIN_SIZE_OPTIONS=0;
	int cursor=0,cursor_dest=y1;
	char names_options[BUFSIZ][BUFSIZ]={NULL};
	strcpy(names_options[0],"GAME");
	strcpy(names_options[1],"EXIT");
	setcolor(BLUE);
	outtextxy(x,y1,names_options[0]);
	setcolor(WHITE);
	outtextxy(x,y2,names_options[1]);
	fprintf(stdout,"%d %d",KEY_UP,KEY_DOWN);
	while ( TRUE )
	{
		key_pressed=getch();
		switch (key_pressed)
		{
		case KEY_ENTER:
			{
				if ( cursor == 0 )
				{
					return VOID_GAME; // game = 1
				}
				if ( cursor == 1)
				{
					return CODE_EXIT; // exit = 0
				}
				break;
			};
		case KEY_DOWN:
			{
				if ( cursor < MAX_SIZE_OPTIONS )
				{
					setcolor(WHITE);
					outtextxy(x,cursor_dest,names_options[cursor]);
					cursor++;
					cursor_dest+=STEP;
					setcolor(BLUE);
					outtextxy(x,cursor_dest,names_options[cursor]);
				}
				break;
			}
		case KEY_UP:
			{
				if ( cursor > MIN_SIZE_OPTIONS )
				{
					setcolor(WHITE);
					outtextxy(x,cursor_dest,names_options[cursor]);
					cursor--;
					cursor_dest-=STEP;
					setcolor(BLUE);
					outtextxy(x,cursor_dest,names_options[cursor]);
				}
				break;
			}
		default:
			{
				break;
			}
		}
	};
}
void game()
{
	cleardevice();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	int lifes_player1=4,lifes_player2=4;
	int player1_text_x=30,player2_text_x,player_y=30;
	int step_x=10;
	//RED PLAYER
	setcolor(RED);
	outtextxy(player1_text_x,player_y,"PLAYER 1");
	player1_text_x+=2*STEP;
	char *heart;
	heart="Nothing";
	//for ( int i=0;i<lifes_player1;i++)
	//{
	//	outtextxy(player1_text_x,player_y,heart);		
	//	player1_text_x+=2*STEP;
	//}
	getch();
	setcolor(LIGHTGRAY);
	setfillstyle(1,BLUE);
	rectangle(BORDER,BORDER,MAX_X-BORDER,MAX_Y-BORDER);
	floodfill(1,1,LIGHTGRAY);
	setfillstyle(1,BLACK);
	bar(0,0,MAX_X,BORDER-1);
	getch();
}
int main()
{
	init();
	int menu_value;
	while ( (menu_value=menu()) != 0 )
	{
		switch (menu_value)
		{
		case VOID_GAME:
			{
				game();
				break;
			}
		case CODE_EXIT:
			{
				return 0;
			}
		default:
			break;
		}
	}
	closegraph(ALL_WINDOWS);
	return 0;
}