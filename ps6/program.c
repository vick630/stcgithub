#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include <curses.h>

void canva(const int area, const int sizeofsmth, const int lengthofsnake, const int y, const int x);

void canva(const int area, const int sizeofsmth, const int lengthofsnake, const int y, const int x){
				if(area==0){
					attron(COLOR_PAIR(4));
					printw("   ");
					attroff(COLOR_PAIR(4));
				}
				else{
					if(area==lengthofsnake){
						attron(COLOR_PAIR(3));
						printw("   ");
						attroff(COLOR_PAIR(3));
					}
					else{
						if(area==sizeofsmth){
							attron(COLOR_PAIR(2));
							printw(" X ");
							attroff(COLOR_PAIR(2));
						}
						else{
							attron(COLOR_PAIR(1));
							printw("   ");
       			 			attroff(COLOR_PAIR(1));
						}
						}}}

void start();

void start()
{	mvprintw(5, 16, "Start: w");
	mvprintw(6, 16, "Rules: r");
	mvprintw(7, 16, "Settings: s");
	mvprintw(8, 16, "Quit: x");
	refresh();
	}


void cisti();

void cisti()
{int j;
		for ( j = 0; j < 21; ++j)
	{
		move(j,0);
		printw("                                                                                                     ");
	}
	refresh();
}

void pravidla();
void pravidla()
{
	char l;
	FILE* fp;
	fp=fopen("rules.txt", "r");
	move(0,0);
	cisti(); 
    // vycisti obrazovku
	refresh();

	move(0,0);
	while((l=getc(fp))!= EOF){
		printw("%c",l); 
        //nacitat znak a vypisat EOF end of file
	}
	refresh();
	while(getch()!='l'){
	}
	fclose(fp);
	move(0,0);
	cisti();
	refresh();
	start();
	refresh();
}


int main(int bov, char const *bovv[])
{
	initscr();
	start_color();
		struct timespec ts = {
        .tv_sec = 0,                    
        // nr of secs
        .tv_nsec = 0.9 * 1000000000L  
        // nr of nanosecs
    };
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_WHITE, COLOR_WHITE);
	nodelay(stdscr, TRUE);
	keypad(stdscr,TRUE);

	int area[15][15] = {
    {250, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 3, 2, 1, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250},
    {250, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 250}
};
	
	int i, j, r, s;
	int game=0;
	int correct_place, krok=0;
	int future=5, sizeofsmth=4, lengthofsnake=3, correctsnake=2;
	int smer = KEY_RIGHT;
	int direct_left=-1;
	char choice, level;
	char menuu=' ';
	int direct_up=0;
	
	
	float rychlost = 0.4;
	int body=0;

	srand(time(0));
while(menuu!='x' && choice!= 'x')
{
	if(menuu=='y'){				
        //vrati povodne hodnoty na zaciatok po opakovani hry
		menuu=' ';
		smer = KEY_RIGHT;
		direct_left=-1;
		direct_up=0;
		game=0;
		krok=0;
		future=5, sizeofsmth=4, lengthofsnake=3, correctsnake=2;
		body=0;
		choice=' ';
		for(j=1;j<14;j++){
			for (i=1;i<14;i++)
			{
				if(area[j][i]!=251 && area[j][i]!=250){
					area[j][i]=0;
				}
			}
		}
		area[8][9]=1; 
		area[8][8]=2;
		area[8][7]=3;
		area[4][5]=4;  	
	}											
    //po tade
	cisti();	
	start();
	while(choice!='w' && choice!='x'){
		move(10,1);
		choice =getch();
		switch(choice){
    		case 'r' : mvprintw(10, 10, " zadal si r"); 
			pravidla(); 
			break;
    		case 's' : {
						mvprintw(10, 10, " zadal si s");
						cisti();
						move(0,0);
						while(level!='x'){
							mvprintw(0, 0, "set the speed:");
							mvprintw(1, 0, "	level 1- a");
							mvprintw(2, 0, "	level 2- b"); 
							mvprintw(3, 0, " 	level 3- c");
							mvprintw(9, 0, "Quit: x");
							move(11,0);
							level=getch();
							switch(level){
								case 'a' : rychlost =0.9; mvprintw(11, 0,"speed 1"); 
								break;
								case 'b' : rychlost =0.4; mvprintw(11, 0,"speed 2");  
								break;
								case 'c' : rychlost =0.1; mvprintw(11, 0,"speed 3");  
								break;
							}

						}
						level=' ';
						cisti();
						start();
						break;
    					}
    		case 'x' : 
			break;
    		default  : continue;  
			break;
		}
		refresh();
	}
	cisti();

if(choice=='w')
{	
	move(0,0);
	for (i = 0; i < 15; ++i)
	{
		for ( j = 0; j < 15; ++j)
		{
			canva(area[i][j], sizeofsmth, lengthofsnake, i, j);
		}
		move(i+1,0);
	}

	while(game!=1)
	{
		mvprintw(16, 0, "body = %d", body=(sizeofsmth-4));
		move(17,0); // posuva kurzor

		ts.tv_nsec = rychlost * 1000000000L;
		
		nanosleep(&ts, NULL);

		smer=getch(); // vezmi zadany znak 
		switch(smer){
            case KEY_DOWN : direct_up=1; direct_left=0; mvprintw(16, 16, "           "); break;
    		case KEY_RIGHT : direct_up=0; direct_left=1; mvprintw(16, 16, "           "); break;
    		case KEY_UP : direct_up=-1; direct_left=0; mvprintw(16, 16, "             "); break;  // smery
    		case KEY_LEFT : direct_up=0; direct_left=-1; mvprintw(16, 16, "             "); break;
    		default  : break;
		}
		refresh();

//long snake
		for (i = 0; i < 15; ++i)
		{for ( j = 0; j < 15; ++j)
			{if (area[i][j]==lengthofsnake)
				{
					if(area[i+direct_up][j+direct_left]==sizeofsmth){
						sizeofsmth=sizeofsmth+1;
						lengthofsnake=lengthofsnake+1;
						correctsnake=correctsnake+1;
						krok=1;
						if (sizeofsmth==future)
						{
							do{
								r=rand()%12+1;
								s=rand()%12+1; 
                                // pripocitame ku tomu
								if (area[r][s]==0)
								{   area[r][s]=future;
									correct_place=0;
									future++;
								}
								else{
									correct_place=1;
								}
							}while(correct_place!=0);

						}
						break;
					}
				}
			}
		}
//short snake  
	if (krok==0)
	{for (i = 0; i < 15; ++i)
		{for ( j = 0; j < 15; ++j)
			{if(area[i][j]!=0 && area[i][j]!=250 && area[i][j]!= 251 && area[i][j]!=sizeofsmth){
					area[i][j]=area[i][j]-1;
				}}}

		for (i = 0; i < 15; ++i)
		{	for ( j = 0; j < 15; ++j)
			{if(area[i][j]==correctsnake){							//dorovna hadika
					if(area[i+direct_up][j+direct_left]==0){
						area[i+direct_up][j+direct_left]=lengthofsnake;
						break;
					}
					else{										//ak pojde do prekazky skonci hadika
						game=1;
						refresh();
						break;
					}	
				}
			}
		}
	}
	else{krok=0;
	refresh();}
			if (game==0)
		{move(0,0);
			for (i = 0; i < 15; ++i)
			{for (j = 0; j < 15; ++j)
				{canva(area[i][j], sizeofsmth, lengthofsnake, i, j);}
			printw("\n");
			refresh();
			refresh();
			}
		}}

	mvprintw(5, 10, "Lost");
	mvprintw(7, 10, "Menu: y");
	mvprintw(8, 10, "Quit: x");
	mvprintw(9, 10, "Tvoje skóre = %d", body=(sizeofsmth-4));
	move(20,0);
	refresh();
	while(menuu!= 'y' && menuu!='x' ){
		menuu=getch();
	}}}	
	endwin();
	refresh();
	return 0;
}


