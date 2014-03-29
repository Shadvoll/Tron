// TRON REBORN
#include "graphics.h"
#include<math.h>
//defines
#define STEP 50;
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_ESC   27 
#define CHAR_SIZE 5
#define VOID_GAME 0
#define CODE_INSTRUCTION 1
#define CODE_CREDIT 2
#define CODE_EXIT 10
#define BORDER 50
#define NULL 0
#define HEART_CHAR 3
#define MAX_X getmaxwidth()
#define MAX_Y getmaxheight()
#define CHAR_SIZE 10
// consts

void game();void init();int menu();void instructions();void credit();


void init()
{
	initwindow(MAX_X,MAX_Y,"TRON REBORN BETA");	
}
int menu()
{
	cleardevice();
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
	char key_pressed=NULL;
	int x=MAX_X/3;
	int y[BUFSIZ];
	const int MAX_SIZE_OPTIONS=3,MIN_SIZE_OPTIONS=0;
	y[0]=MAX_Y/4;
	int i=0;
	for (  i=1;i<=MAX_SIZE_OPTIONS;i++)
	{
		y[i]=y[0]+i*STEP;
	}
	int cursor=0,cursor_dest=y[0];
	char names_options[BUFSIZ][BUFSIZ]={NULL};
	strcpy(names_options[0],"GAME");
	strcpy(names_options[1],"INSTROCTIONS");
	strcpy(names_options[2],"CREDIT");
	strcpy(names_options[3],"EXIT");
	setcolor(BLUE);
	outtextxy(x,y[0],names_options[0]);
	setcolor(WHITE);
	for ( i=1;i<=MAX_SIZE_OPTIONS;outtextxy(x,y[i],names_options[i]),i++);
	fprintf(stdout,"%d %d",KEY_UP,KEY_DOWN);
	while ( TRUE )
	{
		key_pressed=getch();
		switch (key_pressed)
		{
		case KEY_ENTER:
			{
				if ( cursor == VOID_GAME )
				{
					return VOID_GAME; // game = 0
				} else if ( cursor == CODE_INSTRUCTION)
				{
					return CODE_INSTRUCTION; // instroctions = 1
				} else if ( cursor == CODE_CREDIT )
				{
					return CODE_CREDIT; // 2
				} else if ( cursor == MAX_SIZE_OPTIONS )
				{
					return CODE_EXIT; // exit = 10
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
void instructions()
{
	cleardevice();
	int x=MAX_X/3,y=MAX_Y/4;
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
	setcolor(RED);
	outtextxy(x,y,"PLAYER 1 CONTROLS :" );
	y+=STEP;
	outtextxy(x,y," W A S D " );
	y+=STEP;
	setcolor(LIGHTBLUE);
	outtextxy(x,y,"PLAYER 2 CONTROLS : " );
	y+=STEP;
	outtextxy(x,y," ARROWS UP DOWN LEFT RIGHT " );
	setcolor(WHITE);
	y+=STEP;
	outtextxy(x,y,"PAUSE - SPACE" );
	y+=STEP;
	outtextxy(x,y,"EXIT  - ESC" );
	y=MAX_Y/8*7;
	outtextxy(x,y,"  PRESS ENTER TO CONTINUE" );
	while ( getch() != KEY_ENTER );
}
void credit()
{
	cleardevice();
	int x=MAX_X/3,y=MAX_Y/4;
	setcolor(WHITE);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
	outtextxy(x,y,"GAME WAS CREATED BY SHADVOLL" );
	y=MAX_Y/8*7;
	outtextxy(x,y,"  PRESS ENTER TO CONTINUE" );
	while ( getch() != KEY_ENTER );
	return;
}
void game()
{
	cleardevice();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	int lifes_player1=4,lifes_player2=4;
	int player1_text_x=30,player2_text_x,player_y=30;
	int step_x=10;
	do
	{
		cleardevice();
		//Game Field
		setcolor(WHITE);
		rectangle(BORDER,BORDER,MAX_X-BORDER,MAX_Y-BORDER);
		setfillstyle(1,BLUE);
		floodfill(1,1,WHITE);
		//RED PLAYER
		setfillstyle(1,BLACK);
		setcolor(WHITE);
		rectangle(0,0,BORDER*8,BORDER/3*2);
		floodfill(1,1,WHITE);
		setcolor(RED);
		outtextxy(10,10,"PLAYER 1");
		switch (lifes_player1)
		{
		case 1:
			{
				outtextxy(10+CHAR_SIZE*strlen("PLAYER 1"),10,"ONE LIFE");
				break;
			}
		case 2:
			{
				outtextxy(10+CHAR_SIZE*strlen("PLAYER 1"),10,"TWO LIFES");
				break;
			}
		case 3:
			{
				outtextxy(10+CHAR_SIZE*strlen("PLAYER 1"),10,"THREE LIFES");
				break;
			}
		case 4:
			{
				outtextxy(10+CHAR_SIZE*strlen("PLAYER 1"),10,"FULL LIFE");
				break;
			}
		default:
			break;
		}
		//(LIGHT)BLUE PLAYER
		setfillstyle(1,BLACK);
		setcolor(WHITE);
		rectangle(MAX_X-BORDER*8,0,MAX_X,BORDER/3*2);
		floodfill(MAX_X-1,1,WHITE);
		setcolor(LIGHTBLUE);
		outtextxy(MAX_X-BORDER*8+10,10,"PLAYER 2");
		switch (lifes_player2)
		{
		case 1:
			{
				outtextxy(10+MAX_X-BORDER*8+CHAR_SIZE*strlen("PLAYER 2"),10,"ONE LIFE");
				break;
			}
		case 2:
			{
				outtextxy(10+MAX_X-BORDER*8+CHAR_SIZE*strlen("PLAYER 2"),10,"TWO LIFES");
				break;
			}
		case 3:
			{
				outtextxy(10+MAX_X-BORDER*8+CHAR_SIZE*strlen("PLAYER 2"),10,"THREE LIFES");
				break;
			}
		case 4:
			{
				outtextxy(10+MAX_X-BORDER*8+CHAR_SIZE*strlen("PLAYER 2"),10,"FULL LIFE");
				break;
			}
		default:
			break;
		}
		//game starts
		int player1_x=MAX_X/2-250,player1_y=MAX_Y/2,player2_x=MAX_X/2+250,player2_y=MAX_Y/2;
		char player1_move_x=1,player1_move_y=0,player2_move_x=-1,player2_move_y=0;
		putpixel(player1_x,player1_y,RED);
		putpixel(player2_x,player2_y,LIGHTBLUE);
		while ( (getpixel(player1_x+player1_move_x,player1_y+player1_move_y) == BLACK ) && ( getpixel(player2_x+player2_move_x,player2_y+player2_move_y) == BLACK ))
		{
			delay(10);
			putpixel(player1_x,player1_y,RED);
			putpixel(player2_x,player2_y,LIGHTBLUE);
			if ( kbhit() )
			{
				switch (getch())
				{
				case KEY_DOWN:
					{
						if ( player2_move_y == 0 )
						{
							player2_move_y=1;
							player2_move_x=0;
						}
						break;
					}
				case KEY_UP:
					{
						if ( player2_move_y == 0 )
						{
							player2_move_y=-1;
							player2_move_x=0;
						}
						break;
					}
				case KEY_RIGHT:
					{
						if ( player2_move_x == 0 )
						{
							player2_move_x=1;
							player2_move_y=0;
						}
						break;
					}
				case KEY_LEFT:
					{
						if ( player2_move_x == 0 )
						{
							player2_move_x=-1;
							player2_move_y=0;
						}
						break;
					}
				case 's':
					{
						if ( player1_move_y == 0 )
						{
							player1_move_y=1;
							player1_move_x=0;
						}
						break;
					}
				case 'w':
					{
						if ( player1_move_y == 0 )
						{
							player1_move_y=-1;
							player1_move_x=0;
						}
						break;
					}
				case 'd':
					{
						if ( player1_move_x == 0 )
						{
							player1_move_x=1;
							player1_move_y=0;
						}
						break;
					}
				case 'a':
					{
						if ( player1_move_x == 0 )
						{
							player1_move_x=-1;
							player1_move_y=0;
						}
						break;
					}
				case KEY_SPACE:
					{
						while ( !kbhit() )
						{
							delay(100);
						}
						break;
					}
				case KEY_ESC:
					{
						return;
					}
				default:
					break;
				}
			}
			player1_x+=player1_move_x;
			player1_y+=player1_move_y;
			player2_x+=player2_move_x;
			player2_y+=player2_move_y;
		}
		if (getpixel(player1_x+player1_move_x,player1_y+player1_move_y) != BLACK) 
		{
			lifes_player1--;
		}
		else
		{
			lifes_player2--;
		}


		while ( !kbhit() )
		{
			delay(100);
		}
	}while( (lifes_player1 != 0 ) && ( lifes_player2 != 0 ) );
	getch();
	setcolor(WHITE);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
	outtextxy(MAX_X/4,MAX_Y/3,"GAME WAS CREATED BY SHADVOLL" );
	outtextxy(MAX_X/3,MAX_Y*8/9,"PRESS ENTER TO CONTINUE");
	while ( getch() != KEY_ENTER );
}
int main()
{
	init();
	int menu_value;
	while ( (menu_value=menu()) != CODE_EXIT )
	{
		switch (menu_value)
		{
		case VOID_GAME:
			{
				game();
				break;
			}
		case CODE_INSTRUCTION:
			{
				instructions();
				break;
			}
		case CODE_CREDIT:
			{
				credit();
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