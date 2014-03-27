// TRON REBORN
#include "graphics.h"
#include<math.h>
//defines
#define STEP 50;
#define KEY_ENTER 13
#define CHAR_SIZE 5
#define VOID_GAME 1
#define CODE_EXIT 0
// consts

void game();void init();int menu();
void init()
{
	initwindow(getmaxwidth(),getmaxwidth(),"TRON REBORN BETA");
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
}
int menu()
{
	char key_pressed='a';
	int x=getmaxwidth()/3,y1=getmaxheight()/4,y2=y1+STEP;
	const int MAX_SIZE_OPTIONS=1,MIN_SIZE_OPTIONS=0;
	int cursor=0,cursor_dest=y1;
	char names_options[BUFSIZ][BUFSIZ]={0};
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