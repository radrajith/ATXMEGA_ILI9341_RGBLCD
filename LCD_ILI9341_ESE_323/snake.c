#include "ili9341.h"
#include "snake.h"
#include "gfx.h"
//unsigned int oldSnake[1000];
unsigned int newSnake[1000];
unsigned int width; 
unsigned int height;
int oldHead = 0;
int newHead = 0;
int tail = 0;
int size = 2;
int points = 0;
int food;
int speed = 500;			//ms
int direction = 0;			//0 -  top, 1 - bottom, 2 - left, 3 - right
bool gameOver = false;
void snake_init(){
	width = getWidth();
	height = getHeight();
	snake_setup();
	clear(ILI9341_WHITESMOKE);
}

void snake_setup(){
	for(int i = 0; i<1000; i++){
		//oldSnake[i] = -1;
		newSnake[i] = -1;
	}
	int startPoint = srand(76800);
	snake_putDot(startPoint, ILI9341_BLACK);
	newHead = startPoint;
	newSnake[0] = startPoint;
	direction = 0;
	generateFood();
	
}
void snake_run(){
	//oldHead = newHead;
	switch(direction){
		case 0:	//top
		if((newHead - height)<0){
			newHead += (width -1) * height;			//checking if the snake has reached the end
		}
		else{
			newHead -= height;
		}
		break;
		case 1:	//down
		if ((newHead + height) > ((width * height - 1)))
		{
			newHead = newHead % height;
		}
		else {
			newHead += height;
		}
		break;
		case 2:	//left
		if (newHead == 0)
		{
			// exception for topleft, pixel 0
			newHead += (height - 1);
		}
		else if ((newHead - (newHead % height)) == (((newHead-1) - (newHead-1) % height)))
		{
			newHead -= 1;
		}
		else {
			newHead += (height - 1); // end of row
		}
		break;
		case 3:	//right	
		  if ((newHead - (newHead % height)) == (((newHead+1) - (newHead+1) % height)))
		  {
			  newHead += 1;
		  }
		  else
		  {
			  newHead = newHead - (height - 1); // to start of row
		  }
		  break;
		  
	}
	if(newHead == food){
		generateFood();
		points += 1;
	}
	//check if the snake hit onto itself
	for(int i = 1; i < 1000; i++){
		if(newSnake[i] == newHead){
			snake_endGame();
		}
	}
	//create a new tail
	for(int i = 0; i<999; i++){
		newSnake[999 - i] = newSnake[998 -i];
	}
	newSnake[0] = newHead;
	//oldSnake = newSnake;
	snake_updateDisp();
}
void snake_updateDisp(){
	for(int i = 0; i<1000; i++){
		snake_putDot(newSnake[i], ILI9341_BLACK);
	}
}
void snake_endGame(){
	clear(ILI9341_BLACK);
	gfx_print("GAME OVER");
}
void snake_putDot(int location, int color){
	int x = ceil(location/width);
	int y = location%width;
	gfx_drawChar(x, y, ' ', ILI9341_WHITE, color, size);
}
void generateFood(){
	food = srand(76800);
	snake_putDot(food, ILI9341_RED);
}
