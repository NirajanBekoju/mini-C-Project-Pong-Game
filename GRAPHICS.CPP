#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
char leftbar(int, int, int, int, char, int, int, int, int);

void main(){
	//Margin for the arena
	int left, top, right, bottom, margin;
	//Declaration for the left bar
	int llft, ltp, lrgt, lbtm;
	//Character Input for the left bar
	char leftChar;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	setbkcolor(3);//Set The background color;
	//Set the constraints for the arena;
	margin = 100;
	right = getmaxx() - margin;
	left = 100;
	top = 100;
	bottom = getmaxy() - margin;
	//Fill Color for arena
	setfillstyle(SOLID_FILL, WHITE);
	bar(left, top, right, bottom);//declaration of the arena;
	//Left Bar
	llft = left;
	ltp = top + (bottom-top)/2-20;
	lrgt = llft + 5;
	lbtm = top + (bottom-top)/2+20;
	//Declaration and coloring of the left bar;
	setfillstyle(SOLID_FILL, 4);
	bar(left, ltp, lrgt, lbtm);
	//Calling for the movement of the leftbar;
	while(1){
		leftChar = getch();
		while(leftChar == 'w' || leftChar == 's'){
			leftChar = leftbar(llft, ltp, lrgt, lbtm, leftChar, top, bottom, left, right);
		}
		break;
	}
	//End of the left bar movement
	setcolor(0);
	printf("GAME OVER!!!");
	getch();
	closegraph();
}

char leftbar(int llft,int ltp,int lrgt,int lbtm,char leftChar, int top, int bottom, int left, int right){
	while(leftChar == 'w' || leftChar == 's'){
		cleardevice();
		if(leftChar == 'w'){
			if(ltp > top){
				ltp-=5;
				lbtm-=5;
			}
		}
		if(leftChar == 's'){
			if(lbtm < bottom){
				ltp+=5;
				lbtm+=5;
			}
		}
		//Fill Color for arena
		setfillstyle(SOLID_FILL, WHITE);
		bar(left, top, right, bottom);//declaration of the arena;

		//Movement of the left bar
		setfillstyle(SOLID_FILL, 4);
		bar(llft, ltp, lrgt, lbtm);
		leftChar = getch();
	}
	return leftChar;
}