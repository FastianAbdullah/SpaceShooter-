#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>


int const row = 800;
int const column = 800;
int SCORES = 0;
int lives = 3;

int getRand(int start, int end);
void getUniqueTwoRands(int end, int results[]);
void swap(int& a, int& b);
void gamestart();
void gameover();
void Game_win();
int Level2(int SCORES, int lives_r[]);
int Level3(int SCORES, int lives_r[]);
int Level4(int SCORES, int lives_r[]);
int Level5(int SCORES, int lives_r[]);

main()
{
	initwindow(row,column);


	int x=400; 
	
	int bul=0;
	int bulx;
	int buly = 650;

	bool enemy1Fire = true;
	int firingEnemy1;
	int enemy1Count = 4;
	int enemy2Count = 5;
	bool enemy2Fire  = true;
	int firingEnemy2;
	int enemy_y = 100;
	int enemy_x[4] = {150,300,450,600};
	int enemy_y2 = 200;
	int enemy_x2[5] = {90,230,370,520,650};
	
	int enemy_1_bul[4] ={150,300,450,600};
	int enemy_2_bul[5] ={90,230,370,520,650};
	int enemy_y1 = 100;
	int enemy_bul_y = 200;
	int radius_enemy_x[4] = {5,5,5,5};
	int radius_enemy_x2[5] = {5,5,5,5,5};


	int radius1[4] = {20, 20, 20, 20};
	int radius2[5] = {25,25,25,25,25};
	
	int lives_x[3] = {350, 400, 450};
	int lives_r[3] = {10, 10, 10};


	gamestart();
		
	cleardevice();
	
	line(0, 200, 800, 200);
	
	setcolor(BLUE);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 7);
	outtextxy(170, 300, "LEVEL 1");
	settextstyle(SMALL_FONT, HORIZ_DIR, 10);
	outtextxy(170, 370, "SCORE = 0");
	
	line(0, 500, 800, 500);
	
	delay(2000);
	
	for(; ;)
    {

//   	int spaceship_radius =20;
   	
   	setcolor(BLUE);
   	setfillstyle(SOLID_FILL, BLUE);
   	
   	rectangle(x, 710, x+ 80, 730);   // down 
    rectangle(x + 30, 670, x + 50, 710);  //up
	floodfill(x + 1, 711 , BLUE);
	floodfill(x + 31, 671, BLUE);

	if(GetAsyncKeyState(VK_RIGHT) && x <= 700)
	{
		x +=10;
	}
	if(GetAsyncKeyState(VK_LEFT) && x >= 10)
	{
		x -=10;
	}
	if(GetAsyncKeyState(' ') && bul==0 )
	{
		bul = 1;
		bulx=x+40;
	}
	if(bul == 1)
	{
		setcolor(CYAN);
		setfillstyle(SOLID_FILL, CYAN);
		circle(bulx,buly,10);
		floodfill(bulx, buly, CYAN);
		buly = buly - 10;
	}
	if(buly == 0)
	{
		bul=0;
		buly=700;
	}
	

	for(int i=0; i<4; i++)
	{	

		setcolor(MAGENTA);
		setfillstyle(SOLID_FILL, MAGENTA);
	
		circle(enemy_x[i], enemy_y,radius1[i]);
		if(radius1[i] != 0)
		{
			floodfill(enemy_x[i], enemy_y, MAGENTA);
		}
		
		if(buly==enemy_y && bulx>enemy_x[i]-40 && bulx<enemy_x[i]+40 && radius1[i] != 0)
		{
			radius1[i] = 0;
			bul=0;  
			buly=700;
			SCORES += 20;
			enemy1Count -= 1;
		}
	}
	
		
	for(int i=0; i<5; i++)
	{	
		setcolor(LIGHTMAGENTA);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	
		circle(enemy_x2[i], enemy_y2,radius2[i]);
		if(radius2[i] != 0)
		{
			floodfill(enemy_x2[i], enemy_y2, LIGHTMAGENTA);
		}
		
		if(buly==enemy_y2 && bulx>enemy_x2[i]-40 && bulx<enemy_x2[i]+40 && radius2[i] != 0)
			{
				radius2[i] = 0;
				bul=0;  
				buly=700;
				SCORES += 20;
				enemy2Count -= 1;
			}
	}
	

	if (enemy1Fire){
		int maxRand = enemy1Count;
		for (int i = 0 ; i < 4 ; i++){
			
			if (radius1[i]!=0){
				
				int random = getRand(0,maxRand);
				if (random==0){
					firingEnemy1 = i;
					break;
				}
				maxRand--;				
			}
				
		}
		enemy1Fire = false;
	}
	
	
	if (enemy2Fire){
		int maxRand = enemy2Count;
		for (int i = 0 ; i < 5 ; i++){
			
			if (radius2[i]!=0){
				
				int random = getRand(0,maxRand);
				if (random==0){
					firingEnemy2 = i;
					break;
				}
				maxRand--;				
			}
				
		}
		enemy2Fire = false;
	}
	
	
		setcolor(YELLOW);
		circle(enemy_1_bul[firingEnemy1], enemy_y1, radius_enemy_x[firingEnemy1]);
		
		enemy_y1 = enemy_y1+5;
		if (enemy_y1>=690 && enemy1Count > 0){
		if(enemy_1_bul[firingEnemy1] > x -10 && enemy_1_bul[firingEnemy1] < x + 80)
			{
				lives_r[lives-1] = 0;
				lives--;
			}
			enemy_y1=100;
			enemy1Fire = true;
		}
		
		
		
		setcolor(LIGHTBLUE);
		circle(enemy_2_bul[firingEnemy2], enemy_bul_y, radius_enemy_x2[firingEnemy2]);
		enemy_bul_y = enemy_bul_y+3;
		
		if (enemy_bul_y>=690 && enemy2Count > 0) {
			if(enemy_2_bul[firingEnemy2] > x -10 && enemy_2_bul[firingEnemy2] < x + 80)
			{
				lives_r[lives-1] = 0;
				lives--;
			}
			enemy_bul_y=200;
			enemy2Fire = true;
		}
	
	
		for(int i = 2; i >= 0; i--)
		{
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			circle(lives_x[i], 760, lives_r[i]);
			if(lives_r[i] != 0)
			{
				floodfill(lives_x[i], 760, RED);
			}
		}
		
		if(lives_r[0] == 0 && lives_r[1] == 0 && lives_r[2] == 0)
		{
			gameover();
			break;
		}
		
		
		if(SCORES == 180)
		{	
			SCORES = Level2(SCORES, lives_r);
		}
		
		if(SCORES == 360)
		{
			SCORES = Level3(SCORES, lives_r);
		}
		
		if(SCORES == 540)
		{
			SCORES = Level4(SCORES, lives_r);
		}
		
		if(SCORES == 720)
		{
			SCORES = Level5(SCORES, lives_r);
		}
		
		if(SCORES == 900)
		{
			Game_win();
			break;
		}
		
		
	
	delay(30);
	cleardevice();
	

    }
}


int Level2(int SCORES, int lives_r[])
{
	int x=400; 
	int bul=0;
	int bulx;
	int buly = 650;

	bool enemy1Fire = true;
	int firingEnemy1;
	int enemy1Count = 4;
	int enemy2Count = 5;
	bool enemy2Fire  = true;
	int firingEnemy2;
	int enemy_y = 100;
	int enemy_x[4] = {150,300,450,600};
	int enemy_y2 = 200;
	int enemy_x2[5] = {90,230,370,520,650};
	int enemy_1_bul[4] ={150,300,450,600};
	int enemy_2_bul[5] ={90,230,370,520,650};
	int enemy_y1 = 100;
	int enemy_bul_y = 200;
	int radius_enemy_x[4] = {5,5,5,5};
	int radius_enemy_x2[5] = {5,5,5,5,5};


	int radius1[4] = {20, 20, 20, 20};
	int radius2[5] = {25,25,25,25,25};
	
	int lives_x[3] = {350, 400, 450};
//	int lives_r[3] = {10, 10, 10};
	SCORES = 180;
	
	cleardevice();
	
	line(0, 200, 800, 200);
	
	setcolor(BLUE);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 7);
	outtextxy(170, 300, "LEVEL 2");
	settextstyle(SMALL_FONT, HORIZ_DIR, 10);
	outtextxy(170, 370, "SCORE = 180");
	
	line(0, 500, 800, 500);
	
	delay(2000);
	

	for(; ;)
    {

    	setcolor(BLUE);
   	setfillstyle(SOLID_FILL, BLUE);
   	
   	rectangle(x, 710, x+ 80, 730);   // down 
    rectangle(x + 30, 670, x + 50, 710);  //up
	floodfill(x + 1, 711 , BLUE);
	floodfill(x + 31, 671, BLUE);

	if(GetAsyncKeyState(VK_RIGHT) && x <= 700)
	{
		x +=10;
	}
	if(GetAsyncKeyState(VK_LEFT) && x >= 10)
	{
		x -=10 ;
	}
	if(GetAsyncKeyState(' ') && bul==0 )
	{
		bul = 600;
		bul = 1;
		bulx=x+40;
	}
	if(bul == 1)
	{	
			setcolor(CYAN);
		setfillstyle(SOLID_FILL, CYAN);
		circle(bulx,buly,10);
		floodfill(bulx, buly, CYAN);
		buly = buly - 10;
	}
	if(buly == 0)
	{
		bul=0;
		buly=700;
	}
	

	for(int i=0; i<4; i++)
	{	

		setcolor(MAGENTA);
		setfillstyle(SOLID_FILL, MAGENTA);
	
		circle(enemy_x[i], enemy_y,radius1[i]);
		if(radius1[i] != 0)
		{
			floodfill(enemy_x[i], enemy_y, MAGENTA);
		}

		if(buly==enemy_y && bulx>enemy_x[i]-40 && bulx<enemy_x[i]+40 && radius1[i] != 0)
		{
			radius1[i] = 0;
			bul=0;  
			buly=700;
			SCORES += 20;
			enemy1Count -= 1;
		}
	}
	
		
	for(int i=0; i<5; i++)
	{	
		setcolor(LIGHTMAGENTA);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	
		circle(enemy_x2[i], enemy_y2,radius2[i]);
		if(radius2[i] != 0)
		{
			floodfill(enemy_x2[i], enemy_y2, LIGHTMAGENTA);
		}
		
		if(buly==enemy_y2 && bulx>enemy_x2[i]-40 && bulx<enemy_x2[i]+40 && radius2[i] != 0)
			{
			radius2[i] = 0;
			bul=0;  
			buly=700;
			SCORES += 20;
			enemy2Count -= 1;
			}
	}
	

	if (enemy1Fire){
		int maxRand = enemy1Count;
		for (int i = 0 ; i < 4 ; i++){
			
			if (radius1[i]!=0){
				
				int random = getRand(0,maxRand);
				if (random==0){
					firingEnemy1 = i;
					break;
				}
				maxRand--;				
			}
				
		}
		enemy1Fire = false;
	}
	
	
	if (enemy2Fire){
		int maxRand = enemy2Count;
		for (int i = 0 ; i < 5 ; i++){
			
			if (radius2[i]!=0){
				
				int random = getRand(0,maxRand);
				if (random==0){
					firingEnemy2 = i;
					break;
				}
				maxRand--;				
			}
				
		}
		enemy2Fire = false;
	}
	
	
		setcolor(YELLOW);
		circle(enemy_1_bul[firingEnemy1], enemy_y1, radius_enemy_x[firingEnemy1]);
		
		enemy_y1 = enemy_y1+10;
		if (enemy_y1>=700 && enemy1Count > 0){
				if(enemy_1_bul[firingEnemy1] > x -10 && enemy_1_bul[firingEnemy1] < x + 80)
			{
				lives_r[lives-1] = 0;
				lives--;
			}
			enemy_y1=100;
			enemy1Fire = true;
		}

		
		
		setcolor(LIGHTBLUE);
		circle(enemy_2_bul[firingEnemy2], enemy_bul_y, radius_enemy_x2[firingEnemy2]);
		enemy_bul_y = enemy_bul_y+7;
		if (enemy_bul_y>=700 && enemy2Count > 0) {
			if(enemy_2_bul[firingEnemy2] > x -10 && enemy_2_bul[firingEnemy2] < x + 80)
			{
				lives_r[lives-1] = 0;
				lives--;
			}
			enemy_bul_y=200;
			enemy2Fire = true;
		}
	
		for(int i = 2; i >= 0; i--)
		{
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			circle(lives_x[i], 760, lives_r[i]);
			if(lives_r[i] != 0)
			{
				floodfill(lives_x[i], 760, RED);
			}
		}
		
		if(lives_r[0] == 0 && lives_r[1] == 0 && lives_r[2] == 0)
		{
			gameover();
			break;
		}
		
		
		if(SCORES == 360)
		{
			return SCORES;
		}
		delay(20);
		cleardevice();
	

    }
}
//					Logic For Multiple ALIEN BULLETS

//          Alive1 [0, 1, 3, 2];
//          Alive2 [0, 1, 2, 3, 4];
//          first rand calculate from 0 to size
//			second rand calulate from 0 to size - 1 AND swap the index given by the first rand with the last value which is size - 1
//			if an enemy dies then the index of that enemy will be swaped with the size - 1 index and decrement in size i.e size--

int Level3(int SCORES, int lives_r[])
{	

	
	int x=400; 
	int bul=0;
	int bulx;
	int buly = 650;

	bool enemy1Fire = true;
	int firingEnemy1;

	int enemy1Count = 4;
	int enemy2Count = 5;
	bool enemy2Fire  = true;
	int firingEnemy2;
	int enemy_y = 100;
	int enemy_x[4] = {150,300,450,600};
	int enemy_y2 = 200;
	int enemy_x2[5] = {90,230,370,520,650};
	int enemy_1_bul[4] ={150,300,450,600};
	int enemy_2_bul[5] ={90,230,370,520,650};
	int enemy_y1 = 100;
	int enemy_bul_y = 200;
	int radius_enemy_x[4] = {5,5,5,5};
	int radius_enemy_x2[5] = {5,5,5,5,5};
//	   				FOR 3RD ENEMY BULLET
	bool enemy3Fire = true;
	int enemy_y3 = 100;
	int enemy_3_bul[4] ={150,300,450,600};
	int firingEnemy3;
	int size = 4;
	int ALIVE[size] = {0,1,2,3};
	int temp;
	

	int radius1[4] = {20, 20, 20, 20};
	int radius2[5] = {25,25,25,25,25};
	
	int lives_x[3] = {350, 400, 450};
	

	
	
	cleardevice();
	
	line(0, 200, 800, 200);
	
	setcolor(BLUE);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 7);
	outtextxy(170, 300, "LEVEL 3");
	settextstyle(SMALL_FONT, HORIZ_DIR, 10);
	outtextxy(170, 370, "SCORE = 360");
	
	line(0, 500, 800, 500);
	
	delay(2000);

	for(; ;)
    {

   	int spaceship_radius =20;
   	
   	setcolor(BLUE);
   	setfillstyle(SOLID_FILL, BLUE);
   	
   	rectangle(x, 710, x+ 80, 730);   // down 
    rectangle(x + 30, 670, x + 50, 710);  //up
	floodfill(x + 1, 711 , BLUE);
	floodfill(x + 31, 671, BLUE);

	if(GetAsyncKeyState(VK_RIGHT) && x <= 700)
	{
		x +=10;
	}
	if(GetAsyncKeyState(VK_LEFT) && x >= 10)
	{
		x -=10;
	}
	if(GetAsyncKeyState(' ') && bul==0 )
	{
		bul = 600;
		bul = 1;
		bulx=x+40;
	}
	if(bul == 1)
	{	
		setcolor(CYAN);
		setfillstyle(SOLID_FILL, CYAN);
		circle(bulx,buly,10);
		floodfill(bulx, buly, CYAN);
		buly = buly - 10;	
	}
	if(buly == 0)
	{
		bul=0;
		buly=700;
	}
	

	for(int i=0; i<4; i++)
	{	

		setcolor(MAGENTA);
		setfillstyle(SOLID_FILL, MAGENTA);
	
		circle(enemy_x[i], enemy_y,radius1[i]);
		if(radius1[i] != 0)
		{
			floodfill(enemy_x[i], enemy_y, MAGENTA);
		}

		if(buly==enemy_y && bulx>enemy_x[i]-40 && bulx<enemy_x[i]+40 && radius1[i] != 0)
		{
			radius1[i] = 0;
			
			enemy1Count = size;
			swap(ALIVE[i], ALIVE[size - 1]);
			size--;
			temp = size - 1;
			
			bul=0;  
			buly=700;
			SCORES += 20;
			enemy1Count -= 1;
		}
	}
	
		
	for(int i=0; i<5; i++)
	{	
		setcolor(LIGHTMAGENTA);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	
		circle(enemy_x2[i], enemy_y2,radius2[i]);
		if(radius2[i] != 0)
		{
			floodfill(enemy_x2[i], enemy_y2, LIGHTMAGENTA);
		}
		
		if(buly==enemy_y2 && bulx>enemy_x2[i]-40 && bulx<enemy_x2[i]+40 && radius2[i] != 0)
			{
			radius2[i] = 0;
			bul=0;  
			buly=700;
			SCORES += 20;
			enemy2Count -= 1;
			}
	}	
		
	bool fireOnlyOnce = false;		
	if (enemy1Fire && enemy3Fire)
	{
		int rands[2];
		getUniqueTwoRands(size, rands);
		
		firingEnemy1 = ALIVE[rands[0]];
		firingEnemy3 = ALIVE[rands[1]];

		enemy1Fire = false;
		enemy3Fire = false;
	}
	
	//----------
	if (size == 1)
	fireOnlyOnce = true;
		
	
	
	if (enemy2Fire){
		int maxRand = enemy2Count;
		for (int i = 0 ; i < 5 ; i++){
			
			if (radius2[i]!=0){
				
				int random = getRand(0,maxRand);
				if (random==0){
					firingEnemy2 = i;
					break;
				}
				maxRand--;				
			}
				
		}
		enemy2Fire = false;
	}
	
	
		setcolor(YELLOW);
		circle(enemy_1_bul[firingEnemy1], enemy_y1, radius_enemy_x[firingEnemy1]);
		
		enemy_y1 = enemy_y1+7;
		if (enemy_y1>=700 && enemy1Count > 0){
			if(enemy_1_bul[firingEnemy1] > x -10 && enemy_1_bul[firingEnemy1] < x + 80)
			{
				lives_r[lives-1] = 0;
				lives--;
			}
			enemy_y1=100;
			enemy1Fire = true;
		}
		
//		----------------THIRD BULLET-------------------
		if (!fireOnlyOnce)
		{
	
			setcolor(YELLOW);
			circle(enemy_3_bul[firingEnemy3], enemy_y3, radius_enemy_x[firingEnemy3]);
		
			enemy_y3 = enemy_y3+7;
			if (enemy_y3>=700 && enemy1Count > 0){
				if(enemy_3_bul[firingEnemy3] > x -10 && enemy_3_bul[firingEnemy3] < x + 80)
				{
					lives_r[lives-1] = 0;
					lives--;
				}
				enemy_y3=100;
				enemy3Fire = true;
			}
		}
//		------------------------------------

		setcolor(LIGHTBLUE);
		circle(enemy_2_bul[firingEnemy2], enemy_bul_y, radius_enemy_x2[firingEnemy2]);
		enemy_bul_y = enemy_bul_y+5;
		if (enemy_bul_y>=700 && enemy2Count > 0) {
			if(enemy_2_bul[firingEnemy2] > x -10 && enemy_2_bul[firingEnemy2] < x + 80)
			{
				lives_r[lives-1] = 0;
				lives--;
			}
			enemy_bul_y=200;
			enemy2Fire = true;
		}
	
		for(int i = 2; i >= 0; i--)
		{
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			circle(lives_x[i], 760, lives_r[i]);
			if(lives_r[i] != 0)
			{
				floodfill(lives_x[i], 760, RED);
			}
		}
		
		if(lives_r[0] == 0 && lives_r[1] == 0 && lives_r[2] == 0)
		{
			gameover();
			break;
		}
		
		if(SCORES == 540)
		{
			return SCORES;
		}
		delay(20);
		cleardevice();
	

    }
}

int Level4(int SCORES, int lives_r[])
{	

	
	int x=400; 
	int bul=0;
	int bulx;
	int buly = 650;

	bool enemy1Fire = true;
	int firingEnemy1;
	int enemy1Count = 4;
	int enemy2Count = 5;
	bool enemy2Fire  = true;
	int firingEnemy2;
	int enemy_y = 100;
	int enemy_x[4] = {150,300,450,600};
	int enemy_y2 = 200;
	int enemy_x2[5] = {90,230,370,520,650};
	int enemy_1_bul[4] ={150,300,450,600};
	int enemy_2_bul[5] ={90,230,370,520,650};
	int enemy_y1 = 100;
	int enemy_bul_y = 200;
	int radius_enemy_x[4] = {5,5,5,5};
	int radius_enemy_x2[5] = {5,5,5,5,5};
//            FOR THIRD ENEMY BULLET
	int firingEnemy3;
	bool enemy3Fire = true;
	int enemy_y3 = 100;
	int enemy_3_bul[4] ={150,300,450,600};
	int size = 4;
	int ALIVE[size] = {0,1,2,3};
	int temp;
//            FOR FORTH ENEMY BULLET	
	int firingEnemy4;
	bool enemy4Fire = true;
	int enemy_y4 = 200;
	int enemy_4_bul[5] = {90,230,370,520,650};
	int size2 = 5;
	int ALIVE2[size2] = {0, 1, 2, 3, 4};
	int temp2;

	int radius1[4] = {20, 20, 20, 20};
	int radius2[5] = {25,25,25,25,25};
	
	int lives_x[3] = {350, 400, 450};
	

	
	
	cleardevice();
	
	line(0, 200, 800, 200);
	
	setcolor(BLUE);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 7);
	outtextxy(170, 300, "LEVEL 4");
	settextstyle(SMALL_FONT, HORIZ_DIR, 10);
	outtextxy(170, 370, "SCORE = 540");
	
	line(0, 500, 800, 500);
	
	delay(2000);

	for(; ;)
    {

   	int spaceship_radius =20;
   	
   	setcolor(BLUE);
   	setfillstyle(SOLID_FILL, BLUE);
   	
   	rectangle(x, 710, x+ 80, 730);   // down 
    rectangle(x + 30, 670, x + 50, 710);  //up
	floodfill(x + 1, 711 , BLUE);
	floodfill(x + 31, 671, BLUE);

	if(GetAsyncKeyState(VK_RIGHT) && x <= 700)
	{
		x +=10;
	}
	if(GetAsyncKeyState(VK_LEFT) && x >= 10)
	{
		x -=10;
	}
	if(GetAsyncKeyState(' ') && bul==0 )
	{
		bul = 600;
		bul = 1;
		bulx=x+40;
	}
	if(bul == 1)
	{	
		setcolor(CYAN);
		setfillstyle(SOLID_FILL, CYAN);
		circle(bulx,buly,10);
		floodfill(bulx, buly, CYAN);
		buly = buly - 10;
	}
	if(buly == 0)
	{
		bul=0;
		buly=700;
	}
	

	for(int i=0; i<4; i++)
	{	

		setcolor(MAGENTA);
		setfillstyle(SOLID_FILL, MAGENTA);
	
		circle(enemy_x[i], enemy_y,radius1[i]);
		if(radius1[i] != 0)
		{
			floodfill(enemy_x[i], enemy_y, MAGENTA);
		}

		if(buly==enemy_y && bulx>enemy_x[i]-40 && bulx<enemy_x[i]+40 && radius1[i] != 0)
		{
			radius1[i] = 0;
			
			enemy1Count = size;
			swap(ALIVE[i], ALIVE[size - 1]);
			size--;
			temp = size - 1;
			
			bul=0;  
			buly=700;
			SCORES += 20;
			enemy1Count -= 1;
		}
	}
	
		
	for(int i=0; i<5; i++)
	{	
		setcolor(LIGHTMAGENTA);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	
		circle(enemy_x2[i], enemy_y2,radius2[i]);
		if(radius2[i] != 0)
		{
			floodfill(enemy_x2[i], enemy_y2, LIGHTMAGENTA);
		}
		
		if(buly==enemy_y2 && bulx>enemy_x2[i]-40 && bulx<enemy_x2[i]+40 && radius2[i] != 0)
			{
			radius2[i] = 0;
			
			enemy2Count = size2;
			swap(ALIVE2[i], ALIVE2[size2 - 1]);
			size2--;
			temp2 = size2 - 1;
			
			bul=0;  
			buly=700;
			SCORES += 20;
			enemy2Count -= 1;
			}
	}	
		
	bool fireOnlyOnce = false;		
	if (enemy1Fire && enemy3Fire)
	{
		int rands[2];
		getUniqueTwoRands(size, rands);
		
		firingEnemy1 = ALIVE[rands[0]];
		firingEnemy3 = ALIVE[rands[1]];

		enemy1Fire = false;
		enemy3Fire = false;
	}
	
	//----------
	if (size == 1)
	fireOnlyOnce = true;
		
	
	
	bool fireOnlyOnce2 = false;		
	if (enemy2Fire && enemy4Fire)
	{
		int rands2[2];
		getUniqueTwoRands(size2, rands2);
		
		firingEnemy2 = ALIVE2[rands2[0]];
		firingEnemy4 = ALIVE2[rands2[1]];

		enemy2Fire = false;
		enemy4Fire = false;
	}
	
	if (size2 == 1)
	fireOnlyOnce2 = true;

	
	setcolor(YELLOW);
	circle(enemy_1_bul[firingEnemy1], enemy_y1, radius_enemy_x[firingEnemy1]);
		
	enemy_y1 = enemy_y1+6;
	if (enemy_y1>=700 && enemy1Count > 0){
		if(enemy_1_bul[firingEnemy1] > x -10 && enemy_1_bul[firingEnemy1] < x + 80)
		{
			lives_r[lives-1] = 0;
			lives--;
		}
		enemy_y1=100;
		enemy1Fire = true;
	}
		
//		----------------------THIRD BULLET--------------
		if (!fireOnlyOnce)
		{
	
			setcolor(YELLOW);
			circle(enemy_3_bul[firingEnemy3], enemy_y3, radius_enemy_x[firingEnemy3]);
		
			enemy_y3 = enemy_y3+6;
			if (enemy_y3>=700 && enemy1Count > 0){
				if(enemy_3_bul[firingEnemy3] > x -10 && enemy_3_bul[firingEnemy3] < x + 80)
				{
					lives_r[lives-1] = 0;
					lives--;
				}
				enemy_y3=100;
				enemy3Fire = true;
			}
		}
//		------------------------------------------

		setcolor(LIGHTBLUE);
		circle(enemy_2_bul[firingEnemy2], enemy_bul_y, radius_enemy_x2[firingEnemy2]);
		enemy_bul_y = enemy_bul_y+5;
		if (enemy_bul_y>=700 && enemy2Count > 0) {
			if(enemy_2_bul[firingEnemy2] > x -10 && enemy_2_bul[firingEnemy2] < x + 80)
			{
				lives_r[lives-1] = 0;
				lives--;
			}
			enemy_bul_y=200;
			enemy2Fire = true;
		}
		
	
	
//		----------------------FORTH BULLET-------------
		if (!fireOnlyOnce2)
		{
	
			setcolor(LIGHTBLUE);
			circle(enemy_4_bul[firingEnemy4], enemy_y4, radius_enemy_x2[firingEnemy4]);
		
			enemy_y4 = enemy_y4+5;
			if (enemy_y4>=700 && enemy2Count > 0){
				if(enemy_4_bul[firingEnemy3] > x -10 && enemy_4_bul[firingEnemy4] < x + 80)
				{
					lives_r[lives-1] = 0;
					lives--;
				}
				enemy_y4=200;
				enemy4Fire = true;
			}
		}
//		------------------------------------------
	
		for(int i = 2; i >= 0; i--)
		{
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			circle(lives_x[i], 760, lives_r[i]);
			if(lives_r[i] != 0)
			{
				floodfill(lives_x[i], 760, RED);
			}
		}
		
		if(lives_r[0] == 0 && lives_r[1] == 0 && lives_r[2] == 0)
		{
			gameover();
			break;
		}
		
		if(SCORES == 720)
		{
			return SCORES;
		}
		delay(20);
		cleardevice();
	

    }
}

int Level5(int SCORES, int lives_r[])
{	

	
	int x=400; 
	int bul=0;
	int bulx;
	int buly = 650;

	bool enemy1Fire = true;
	int firingEnemy1;
	int enemy1Count = 4;
	int enemy2Count = 5;
	bool enemy2Fire  = true;
	int firingEnemy2;
	int enemy_y = 100;
	int enemy_x[4] = {150,300,450,600};
	int enemy_y2 = 200;
	int enemy_x2[5] = {90,230,370,520,650};
	int enemy_1_bul[4] ={150,300,450,600};
	int enemy_2_bul[5] ={90,230,370,520,650};
	int enemy_y1 = 100;
	int enemy_bul_y = 200;
	int radius_enemy_x[4] = {5,5,5,5};
	int radius_enemy_x2[5] = {5,5,5,5,5};
//            FOR THIRD ENEMY BULLET
	int firingEnemy3;
	bool enemy3Fire = true;
	int enemy_y3 = 100;
	int enemy_3_bul[4] ={150,300,450,600};
	int size = 4;
	int ALIVE[size] = {0,1,2,3};
	int temp;
//            FOR FORTH ENEMY BULLET	
	int firingEnemy4;
	bool enemy4Fire = true;
	int enemy_y4 = 200;
	int enemy_4_bul[5] = {90,230,370,520,650};
	int size2 = 5;
	int ALIVE2[size2] = {0, 1, 2, 3, 4};
	int temp2;

	int radius1[4] = {20, 20, 20, 20};
	int radius2[5] = {25,25,25,25,25};
	
	int lives_x[3] = {350, 400, 450};
	

	
	
	cleardevice();
	
	line(0, 200, 800, 200);
	
	setcolor(BLUE);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 7);
	outtextxy(170, 300, "LEVEL 5");
		settextstyle(SMALL_FONT, HORIZ_DIR, 10);
	outtextxy(170, 370, "SCORE = 720");
	
	line(0, 500, 800, 500);
	
	delay(2000);

	for(; ;)
    {

   	int spaceship_radius =20;
   	
   	setcolor(BLUE);
   	setfillstyle(SOLID_FILL, BLUE);
   	
   	rectangle(x, 710, x+ 80, 730);   // down 
    rectangle(x + 30, 670, x + 50, 710);  //up
	floodfill(x + 1, 711 , BLUE);
	floodfill(x + 31, 671, BLUE);

	if(GetAsyncKeyState(VK_RIGHT) && x <= 700)
	{
		x +=10;
	}
	if(GetAsyncKeyState(VK_LEFT) && x >= 10)
	{
		x -=10;
	}
	if(GetAsyncKeyState(' ') && bul==0 )
	{
		bul = 600;
		bul = 1;
		bulx=x+40;
	}
	if(bul == 1)
	{	
		setcolor(CYAN);
		setfillstyle(SOLID_FILL, CYAN);
		circle(bulx,buly,10);
		floodfill(bulx, buly, CYAN);
		buly = buly - 10;
	}
	if(buly == 0)
	{
		bul=0;
		buly=700;
	}
	

	for(int i=0; i<4; i++)
	{	

		setcolor(MAGENTA);
		setfillstyle(SOLID_FILL, MAGENTA);
	
		circle(enemy_x[i], enemy_y,radius1[i]);
		if(radius1[i] != 0)
		{
			floodfill(enemy_x[i], enemy_y, MAGENTA);
		}

		if(buly==enemy_y && bulx>enemy_x[i]-40 && bulx<enemy_x[i]+40 && radius1[i] != 0)
		{
			radius1[i] = 0;
			
			enemy1Count = size;
			swap(ALIVE[i], ALIVE[size - 1]);
			size--;
			temp = size - 1;
			
			bul=0;  
			buly=700;
			SCORES += 20;
			enemy1Count -= 1;
		}
	}
	
		
	for(int i=0; i<5; i++)
	{	
		setcolor(LIGHTMAGENTA);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	
		circle(enemy_x2[i], enemy_y2,radius2[i]);
		if(radius2[i] != 0)
		{
			floodfill(enemy_x2[i], enemy_y2, LIGHTMAGENTA);
		}
		
		if(buly==enemy_y2 && bulx>enemy_x2[i]-40 && bulx<enemy_x2[i]+40 && radius2[i] != 0)
			{
			radius2[i] = 0;
			
			enemy2Count = size2;
			swap(ALIVE2[i], ALIVE2[size2 - 1]);
			size2--;
			temp2 = size2 - 1;
			
			bul=0;  
			buly=700;
			SCORES += 20;
			enemy2Count -= 1;
			}
	}	
		
	bool fireOnlyOnce = false;		
	if (enemy1Fire && enemy3Fire)
	{
		int rands[2];
		getUniqueTwoRands(size, rands);
		
		firingEnemy1 = ALIVE[rands[0]];
		firingEnemy3 = ALIVE[rands[1]];

		enemy1Fire = false;
		enemy3Fire = false;
	}
	
	//----------
	if (size == 1)
	fireOnlyOnce = true;
		
	
	
	bool fireOnlyOnce2 = false;		
	if (enemy2Fire && enemy4Fire)
	{
		int rands2[2];
		getUniqueTwoRands(size2, rands2);
		
		firingEnemy2 = ALIVE2[rands2[0]];
		firingEnemy4 = ALIVE2[rands2[1]];

		enemy2Fire = false;
		enemy4Fire = false;
	}
	
	if (size2 == 1)
	fireOnlyOnce2 = true;

	
	setcolor(YELLOW);
	circle(enemy_1_bul[firingEnemy1], enemy_y1, radius_enemy_x[firingEnemy1]);
		
	enemy_y1 = enemy_y1+9;
	if (enemy_y1>=700 && enemy1Count > 0){
		if(enemy_1_bul[firingEnemy1] > x -10 && enemy_1_bul[firingEnemy1] < x + 80)
		{
			lives_r[lives-1] = 0;
			lives--;
		}
		enemy_y1=100;
		enemy1Fire = true;
	}
		
//		----------------------THIRD BULLET--------------
		if (!fireOnlyOnce)
		{
	
			setcolor(YELLOW);
			circle(enemy_3_bul[firingEnemy3], enemy_y3, radius_enemy_x[firingEnemy3]);
		
			enemy_y3 = enemy_y3+9;
			if (enemy_y3>=700 && enemy1Count > 0){
				if(enemy_3_bul[firingEnemy3] > x -10 && enemy_3_bul[firingEnemy3] < x + 80)
				{
					lives_r[lives-1] = 0;
					lives--;
				}
				enemy_y3=100;
				enemy3Fire = true;
			}
		}
//		------------------------------------------

		setcolor(LIGHTBLUE);
		circle(enemy_2_bul[firingEnemy2], enemy_bul_y, radius_enemy_x2[firingEnemy2]);
		enemy_bul_y = enemy_bul_y+7;
		if (enemy_bul_y>=700 && enemy2Count > 0) {
			if(enemy_2_bul[firingEnemy2] > x -10 && enemy_2_bul[firingEnemy2] < x + 80)
			{
				lives_r[lives-1] = 0;
				lives--;
			}
			enemy_bul_y=200;
			enemy2Fire = true;
		}
		
	
	
//		----------------------FORTH BULLET-------------
		if (!fireOnlyOnce2)
		{
	
			setcolor(LIGHTBLUE);
			circle(enemy_4_bul[firingEnemy4], enemy_y4, radius_enemy_x2[firingEnemy4]);
		
			enemy_y4 = enemy_y4+7;
			if (enemy_y4>=700 && enemy2Count > 0){
				if(enemy_4_bul[firingEnemy3] > x -10 && enemy_4_bul[firingEnemy4] < x + 80)
				{
					lives_r[lives-1] = 0;
					lives--;
				}
				enemy_y4=200;
				enemy4Fire = true;
			}
		}
//		------------------------------------------
	
		for(int i = 2; i >= 0; i--)
		{
			setcolor(RED);
			setfillstyle(SOLID_FILL, RED);
			circle(lives_x[i], 760, lives_r[i]);
			if(lives_r[i] != 0)
			{
				floodfill(lives_x[i], 760, RED);
			}
		}
		
		if(lives_r[0] == 0 && lives_r[1] == 0 && lives_r[2] == 0)
		{
			gameover();
			break;
		}
		
		if(SCORES == 900)
		{
			return SCORES;
		}
		delay(20);
		cleardevice();
	

    }
}

int getRand(int start, int end)
{
	int n;
	n = rand();
	n = n % (end - start) + start;
	return n;
}

void getUniqueTwoRands(int end, int results[])
{	
	if (end == 1)
	{
		results[0] = 0; results[1] = 0;
		return;
	}
	
	int n1 = rand() % end;
	int n2 = rand() % end;
	
	while (n2 == n1)
		n2 = rand() % end;

	results[0] = n1; results[1] = n2;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
	
}

void gameover()
{
	cleardevice();
	
	line(0, 200, 800, 200);
	
	setcolor(BLUE);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 7);
	outtextxy(130, 300, "GAME OVER");
	
	line(0, 500, 800, 500);
	
	delay(4000);
}

void Game_win()
{
	cleardevice();
	
	
	
	setcolor(RED);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 7);
	outtextxy(120, 300, "Congratulations.");
	settextstyle(SMALL_FONT, HORIZ_DIR, 8);
	outtextxy(170, 370, "There is a Winner!");
	
	line(0, 200, 800, 200);
	line(0, 500, 800, 500);
	
	delay(4000);
}

void gamestart()
{
	cleardevice();
	
	setcolor(RED);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 8);
	outtextxy(120, 300, "START....");
	settextstyle(SMALL_FONT, HORIZ_DIR, 9);
	outtextxy(170, 370, "Good Luck  :)");
	
	line(0, 200, 800, 200);
	line(0, 500, 800, 500);
	
	delay(4000);
	
}