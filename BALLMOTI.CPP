#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

void main(){
	//Rough char
	char ch1;
	//Margin for the arena
	int left, top, right, bottom, margin;
	//Declaration for the ball
	int h,k,radius, newh, newk;
	//Small change Decaration
	int dx, dy;
	//Initiation of the graphics
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	setbkcolor(3);//Set The background color;
	//Set the constraints for the arena;
	margin = 100;
	right = getmaxx() - margin;
	left = margin;
	top = margin;
	bottom = getmaxy() - margin;
	//Fill Color for arena
	setfillstyle(SOLID_FILL, WHITE);
	//declaration of the arena;
	bar(left, top, right, bottom);
	//Initial position of the ball;
	h = (right-left)/2 + left;
	k = (bottom-top)/2 + top;
	radius = 10;
	//Fill color for the ball;
	setcolor(6);
	setfillstyle(SOLID_FILL, 6);
	circle(h,k,radius);
	floodfill(h+1, k+1, 6);
	//Arena is ready;
	//Generating a random number among 1 and 2;
	dx = 1;
	dy = 1;
	while(1){
		//New Position Setting;
		newh = h + dx;
		newk = k + dy;
		h = newh;
		k = newk;
		delay(10);
		cleardevice();
		//Outline of the arena;
		line(left, top, right, top);//Top line
		line(left, top, left, bottom);//Vertical left line
		line(right, top, right, bottom);
		line(left, bottom, right, bottom);
		//Drawing of the new position of the ball
		setcolor(6);
		setfillstyle(SOLID_FILL, 6);
		circle(h,k,radius);
		floodfill(h+1, k+1, 6);
		//Conditions for the reflection
		if((k+radius) > bottom || (k-radius) < top)
			dy = -dy;
		if((h+radius) > right || (h-radius) < left)
			dx = -dx;
		//Exit from loop
		if(kbhit()){
			ch1 = getch();
			if(int(ch1) == 97)
				break;
		}
	}
	printf("\nGame Over");
	printf("\n%d", dx);
	printf("\n%d", dy);
	getch();

	closegraph();
}
