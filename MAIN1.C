#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define BALL 1
int main(void)
{

   	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
   	int x,y,x1,y1,x2,y2,a,b,bx1,by1,bx2,by2,flg=0,val,score=0,p,q;
   	char op[20],c[20];
	/* initialize graphics and local variables */
   	initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");

   	/* read result of initialization */
   	errorcode = graphresult();
   	/* an error occurred */
   	if (errorcode != grOk)
   	{
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   	}
   	sprintf(c,"@SwAp Corp.");
   	setcolor(getmaxcolor());
   	x = getmaxx()/2;
   	y = getmaxy()/2;
   	x1=70;
   	y1=70;
   	q=y1-60;
   	p=x;
   	x2=getmaxx()-70;
   	y2=getmaxy()-70;
   	bx2=x2+20;
   	by2=y2+10;
   	bx1=x2-50;
   	by1=y2-10;

   	/* draw a diagonal line */
   	rectangle(x1-25,y1-25,x2+25,y2+25);
   	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	sprintf(op,"Game",score);
	outtextxy(p,q,op);
	outtextxy(x2-50,y2+50,c);
   	while(1)
   	{
		flushall();
		setcolor(WHITE);
   	  	// sprintf(op,"Score : %d",score);
      	//	outtextxy(p,q,op);
		a=x;b=y;
		setcolor(WHITE);
		circle(x,y,20);
		rectangle(bx1,by1,bx2,by2);
		delay(10);
		if(flg==0)
		{
	    	x-=BALL;
	    	y-=BALL;
		}
		else
		{
	  		if(flg==1)
	  		{
	     		x-=BALL;
	     		y+=BALL;
	  		}
	  		else
	  		{
	    		if(flg==2)
	    		{
	     			x+=BALL;
	     			y+=BALL;
	    		}
	    		else
	    		{
	      			if(flg==3)
	      			{
						x+=BALL;
						y-=BALL;
	      			}
	    		}
	  		}
		}
	   	if(y==y1)
	   	{
	    	sound(500);
		  	delay(10);
		  	nosound();
	    	if(a>x)
	    		flg=1;
	   		else
	    		flg=2;
	   }
	   else
	   {
	    	if(x==x1)
	     	{
	       		sound(500);
		  		delay(10);
		  		nosound();
	       		if(b<y)
	       			flg=2;
	       		else
	       			flg=3;
	    	}
	     else
	     {
			if((y==(by1-25))&&(x>=bx1&&x<=bx2))
			{
			  	score+=10;
		  		sound(500);
		  		delay(10);
		  		nosound();
		  		if(a<x)
		    		flg=3;
		  		else
		    		flg=0;
			}
			else
			{
		   		if(y==y2)
		   		{
		     		getch();
		     		closegraph();
		     		return 0;
		   		}
		   		else
		   		{
		     		if(x==x2)
		     		{
		       			sound(500);
		  				delay(10);
		  				nosound();
		       			if(b>y)
		       				flg=0;
		       			else
		       				flg=1;
		     		}
		   		}
			}
	     }
	   }
	   flushall();

		setcolor(BLACK);
		circle(a,b,20);

      //	outtextxy(p,q,op);
	rectangle(bx1,by1,bx2,by2);
    if(kbhit())
    {
		val=getch();
		switch(val)
		{
		   case 75:
		   //left key
	   			bx1-=5;
	   			bx2-=5;
	   			if(bx1<x1)
	   			{		
	       			bx1=x1;
	       			bx2=x1+60;
	   			}
	   			break;
	   case 77:
	   //right key
	   			bx1+=5;
	   			bx2+=5;
	   			if(bx2>x2)
	   			{
	       			bx2=x2;
	       			bx1=bx2-70;
	   			}
	   			break;
	   case 27:


	   			sprintf(op,"Score :%d",score);
	   			setcolor(WHITE);
	   			outtextxy(getmaxx()/2,getmaxy()/2,op);
	   			getch();
	   			closegraph();
	 		  	return 0;

			}
    	}

   }
}
}
   /* clean up */
   getch();
   closegraph();
   return 0;
}
