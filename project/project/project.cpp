// project.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<math.h>
#include<stdlib.h>
#include<GL/glut.h>
GLfloat color[10][3]={{1,1,1},{1,0,0},{0,1,0},{0,0,1},{1,1,0},{0,1,1},{1,0,1},{0,0,0},{.65,.5,0},{.75,.5,.85}};
void moumenucall(int,int,int,int);
void mourect(int,int,int,int);
void moueraser(int,int,int,int);
int i=0,j=0,evnpoly=0,clr,kx,ky,flgtxt,evnsp,r,ra=0,size=1,twopt=0,evnpt=0;
float th,thr,thrp=0,pi=3.14,isp=0;
GLint x0,m,x1,n,x2,y2;

int str,strx,stry;
void drawstring(char * s);
void drawmenu();
void drawvericon()
{
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex2f(0,0+i);
	glColor3f(1,0,1);
	glVertex2f(0,75+i);
	glColor3f(1,1,0);
	glVertex2f(75,75+i);
	glColor3f(1,0,1);
	glVertex2f(75,0+i);
	glEnd();
	i+=75;
}
void drawhoricon()
{
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex2f(75+j,625);
	glColor3f(1,0,1);
	glVertex2f(150+j,625);
	glColor3f(1,1,0);
	glVertex2f(150+j,700);
	glColor3f(1,0,1);
	glVertex2f(75+j,700);
	glEnd();
	j+=75;
}

//MENU DISPLAY
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,1);
	drawmenu();
}
void drawmenu()
{
	i=0;j=0;
	glLineWidth(1);
	drawvericon();
	//RECTANGLE
	glBegin(GL_POLYGON);
	glColor3f(0,0,0); glVertex2f(18.75,18.75);
	glVertex2f(56.25,18.75); glVertex2f(56.25,56.25);
	glVertex2f(18.75,56.25);
	glEnd();

	drawvericon();
	//POLYGON
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(18.75,93.75); glVertex2f(56.25,93.75);
	glVertex2f(56.21,105); glVertex2f(36,105);
	glVertex2f(48.75,131.25); glVertex2f(37.5,131.25);
	glEnd();

	drawvericon();
	//LINES
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(18.75,168.75); glVertex2f(56.25,206.25);
	glEnd();

	drawvericon();
	//PENCIL
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(22.5,255); glVertex2f(30,247.5);
	glVertex2f(60,277.5); glVertex2f(52.5,285);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(22.5,255); glVertex2f(18.75,243.75);
	glVertex2f(30,247.5);
	glEnd();
	glColor3f(.75,.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(22.5,255); glVertex2f(18.75,243.75); 
	glVertex2f(30,247.5);
	glEnd();

	drawvericon();
	//ERASER
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(18.75,322.5); glVertex2f(18.75,330);
	glVertex2f(33.75,345); glVertex2f(48.75,345);
	glVertex2f(48.75,337.5); glVertex2f(33.75,322.5);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(18.75,322.5); glVertex2f(18.75,330);
	glVertex2f(33.75,330); glVertex2f(33.75,322.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(18.75,330); glVertex2f(33.75,330);
	glVertex2f(48.75,345); glVertex2f(33.75,345);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(33.75,322.5); glVertex2f(33.75,330);
	glVertex2f(48.75,345); glVertex2f(48.75,337.5);
	glEnd();

	drawvericon();
	//CIRCLE
	float th,thr,pi=3.14;
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	for(th=0;th<360;th+=20)
	{
		thr=pi*th/180;
		glVertex2f(36+18.75*cos(thr),412+18.75*sin(thr));
	}
	glEnd();


	drawhoricon();
	//PAINT
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(108,690); glVertex2f(117,690);
	glVertex2f(117,660); glVertex2f(108,660);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(108,660); glVertex2f(100,650);
	glVertex2f(100,630); glVertex2f(125,630);
	glVertex2f(125,650); glVertex2f(117,660);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(100,650); glVertex2f(125,650);
	glVertex2f(105,640); glVertex2f(105,630);
	glVertex2f(110,640); glVertex2f(110,630);
	glVertex2f(115,640); glVertex2f(115,630);
	glVertex2f(120,640); glVertex2f(120,630);
	glEnd();
	

	
	drawvericon();
	//POINT
	glColor3f(0,0,0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(37.5,487.5);
	glEnd();

	drawhoricon();
	//CLEARSCREEN
	glColor3f(0,0,0);
	strx=165;stry=657;
	glRasterPos2d(strx,stry);
	drawstring("CLEAR");

	drawvericon();
	//SPRAY
	glColor3f(0,0,0);
	glPointSize(1.4);
	glBegin(GL_POINTS);
	for(int k=1;k<18.75;k+=2)
	for(th=0;th<360;th+=5)
	{
		thr=pi*th/180;
		glVertex2f(36+k*cos(thr),562+k*sin(thr));
	}
	glEnd();
	drawvericon();
	//TEXT
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(10,613); glVertex2f(10,663);
	glVertex2f(60,663); glVertex2f(60,613);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20,623); glVertex2f(35,658);
	glVertex2f(35,648); glVertex2f(25,623);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(50,623); glVertex2f(45,623);
	glVertex2f(35,648); glVertex2f(35,658);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(30,633); glVertex2f(30,638);
	glVertex2f(42,638); glVertex2f(42,633);
	glEnd();

	drawhoricon();
	//SPIRAL
	glColor3f(0,0,0);
	strx=233;stry=657;
	glRasterPos2d(strx,stry);
	drawstring("MORE..");
	
	drawhoricon();
	//SIZE SET
	glColor3f(0,0,0);
	strx=318;stry=657;
	glRasterPos2d(strx,stry);
	drawstring("SIZE");

	//COLOR PALLETE
	//white
	glColor3fv(color[0]);
	glBegin(GL_POLYGON);
	glVertex2f(1050,700); glVertex2f(1050,650);
	glVertex2f(1100,650); glVertex2f(1100,700);
	glEnd();
	//black
	glColor3fv(color[7]);
	glBegin(GL_POLYGON);
	glVertex2f(1100,700); glVertex2f(1100,650);
	glVertex2f(11500,650); glVertex2f(1150,700);
	glEnd();
	//green
	glColor3fv(color[2]);
	glBegin(GL_POLYGON);
	glVertex2f(1150,700); glVertex2f(1150,650);
	glVertex2f(1200,650); glVertex2f(1200,700);
	glEnd();
	//yellow
	glColor3fv(color[4]);
	glBegin(GL_POLYGON);
	glVertex2f(1200,700); glVertex2f(1200,650);
	glVertex2f(1250,650); glVertex2f(1250,700);
	glEnd();
	//purple
	glColor3fv(color[9]);
	glBegin(GL_POLYGON);
	glVertex2f(1200,600); glVertex2f(1200,650);
	glVertex2f(1250,650); glVertex2f(1250,600);
	glEnd();
	//red
	glColor3fv(color[1]);
	glBegin(GL_POLYGON);
	glVertex2f(1150,600); glVertex2f(1150,650);
	glVertex2f(1200,650); glVertex2f(1200,600);
	glEnd();
	//cyan
	glColor3fv(color[5]);
	glBegin(GL_POLYGON);
	glVertex2f(1100,600); glVertex2f(1100,650);
	glVertex2f(1150,650); glVertex2f(1150,600);
	glEnd();
	//pink
	glColor3fv(color[6]);
	glBegin(GL_POLYGON);
	glVertex2f(1050,600); glVertex2f(1050,650);
	glVertex2f(1100,650); glVertex2f(1100,600);
	glEnd();
	//blue
	glColor3fv(color[3]);
	glBegin(GL_POLYGON);
	glVertex2f(1000,600); glVertex2f(1000,650);
	glVertex2f(1050,650); glVertex2f(1050,600);
	glEnd();
	//brown
	glColor3fv(color[8]);
	glBegin(GL_POLYGON);
	glVertex2f(1000,700); glVertex2f(1000,650);
	glVertex2f(1050,650); glVertex2f(1050,700);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(1000,650); glVertex2f(1250,650);
	glVertex2f(1050,700); glVertex2f(1050,600);
	glVertex2f(1100,700); glVertex2f(1100,600);
	glVertex2f(1150,700); glVertex2f(1150,600);
	glVertex2f(1200,700); glVertex2f(1200,600);
	glEnd();

	//2 POINT OPTION
	glBegin(GL_POLYGON);
	glColor3f(0,1,1);
	glVertex2f(990,675);
	glColor3f(0,1,0);
	glVertex2f(990,610);
	glColor3f(0,1,1);
	glVertex2f(925,610);
	glColor3f(0,1,0);
	glVertex2f(925,675);
	glEnd();
		glColor3f(0,0,0);
		strx=942;stry=657;
		glRasterPos2d(strx,stry);
		drawstring("TWO");
		strx=935;stry=637;
		glRasterPos2d(strx,stry);
		drawstring("POINT");
	if(twopt==0)
	{
		strx=947;stry=617;
		glRasterPos2d(strx,stry);
		drawstring("ON");
	}
	else if(twopt==1)
	{
		strx=945;stry=617;
		glRasterPos2d(strx,stry);
		drawstring("OFF");
	}

	glFlush();
	glLineWidth(size);
}

//COLOR SET
void clrset(int x,int y)
{
		if(y<50)
		{
			if(x<1050&&x>1000)
				clr=8;
			else if(x<1100&&x>1050)
				clr=0;
			else if(x<1150&&x>1100)
				clr=7;
			else if(x<1200&&x>1150)
				clr=2;
			else if(x<1250&&x>1200)
				clr=4;
		}
		else if(y>50&&y<100)
		{
			if(x<1050&&x>1000)
				clr=3;
			else if(x<1100&&x>1050)
				clr=6;
			else if(x<1150&&x>1100)
				clr=5;
			else if(x<1200&&x>1150)
				clr=1;
			else if(x<1250&&x>1200)
				clr=9;
		}
}
//RECTANGLE FUNCTIONS
int wire=0;
void motrect(int x,int y)
{
	x2=x;
	y2=y;
	glEnable(GL_COLOR_LOGIC_OP);
	glLogicOp(GL_XOR);
	glColor3fv(color[clr]);
	if(wire==1)
		glBegin(GL_LINE_LOOP);
	else if(wire=0)
		glBegin(GL_POLYGON);
	else
		glBegin(GL_POLYGON);
	glVertex2f(x0,700-m); glVertex2f(x0,700-n);
	glVertex2f(x1,700-n); glVertex2f(x1,700-m);
	glEnd();
	glColor3fv(color[clr]);
	glLogicOp(GL_COPY);
	if(wire==1)
		glBegin(GL_LINE_LOOP);
	else if(wire=0)
		glBegin(GL_POLYGON);
	else
		glBegin(GL_POLYGON);
	glVertex2f(x0,700-m); glVertex2f(x0,700-y2);
	glVertex2f(x2,700-y2); glVertex2f(x2,700-m);
	glEnd();
	x1=x2;
	n=y2;
	glFlush();
}
void mourect(int b,int s,int x,int y)
{
	glLineWidth(size);
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&x>75&&y>100)
	{
	if(twopt==0)
	{
		x0=x1=x;
		m=n=y;
		glutMotionFunc(motrect);
	glColor3fv(color[clr]);
	if(wire==1)
		glBegin(GL_LINE_LOOP);
	else if(wire=0)
		glBegin(GL_POLYGON);
	else
		glBegin(GL_POLYGON);
	glVertex2f(x0,m); glVertex2f(x0,n);
	glVertex2f(x1,n); glVertex2f(x1,m);
	glEnd();
	glFlush();
	}
	else if(twopt==1)
	{
		glColor3fv(color[clr]);
		if(evnpt==0)
		{
			x0=x; m=y;
			evnpt=1;
		}
		else if(evnpt==1)
		{
		if(wire==1)
			glBegin(GL_LINE_LOOP);
		else if(wire=0)
			glBegin(GL_POLYGON);
		else
			glBegin(GL_POLYGON);
		glVertex2f(x0,700-m); glVertex2f(x0,700-y);
		glVertex2f(x,700-y); glVertex2f(x,700-m);
		glEnd();
		glFlush();
		evnpt=0;
		}
	}
	}
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
	{
		if(x<600&&x>475&&y<100)
			wire=1;
		else if(x<825&&x>700&&y<100)
			wire=0;
		else if(x>1000&&y<100)
			clrset(x,y);
		else
		glutMouseFunc(moumenucall);
	}
}

//ERASER FUNCTIONS
int esize=10;
void draw(int m,int n)
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(esize+m,700-(esize+n)); glVertex2f(m+esize,700-(n-esize));
	glVertex2f(m-esize,700-(n-esize)); glVertex2f(m-esize,700-(n+esize));
	glEnd();
	glFlush();
}
void moteraser(int x,int y)
{
	if(esize==5&&x>80&&y>105)
			draw(x,y);
	if(esize==10&&x>85&&y>110)
			draw(x,y);
	if(esize==15&&x>90&&y>115)
			draw(x,y);
}
void donthng(int x,int y)
{}
void moueraser(int b,int s,int x,int y)
{
if(x>75&&y>75)
{
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN)
	{
		draw(x,y);
		glutMotionFunc(moteraser);
	}
	if(b==GLUT_MIDDLE_BUTTON||b==GLUT_RIGHT_BUTTON)
		glutMotionFunc(donthng);
}
if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
{
	if(x<513&&x>388&&y<100)
		esize=5;
	else if(x<713&&x>588&&y<100)
		esize=10;
	else if(x<913&&x>788&&y<100)
		esize=15;
	else
	{
	glutMotionFunc(donthng);
	glutMouseFunc(moumenucall);
	}
}
}

//PENCIL FUNCTIONS
void motpencil(int x,int y)
{
	glBegin(GL_LINE_STRIP);
	glVertex2f(x0,700-m);
	glVertex2f(x,700-y);
	glEnd();
	glFlush();
	x0=x;
	m=y;
}
void moupencil(int b,int s,int x,int y)
{
	glLineWidth(size);
	if(x>75&&y>100)
	{
		x0=x;
		m=y;
		glColor3fv(color[clr]);
		glPointSize(1);
		glBegin(GL_POINTS);
		glVertex2f(x,700-y);
		glEnd();
		glFlush();
		glutMotionFunc(motpencil);
	}
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
	{
		if(x>1000&&y<100)
			clrset(x,y);
		else
		glutMouseFunc(moumenucall);
	}
}

//LINE FUNCTIONS
int linflg=1;
void motlines(int x,int y)
{
	x2=x;
	y2=y;
	glEnable(GL_COLOR_LOGIC_OP);
	glColor3fv(color[clr]);
	glLogicOp(GL_XOR);
	glBegin(GL_LINES);
	glVertex2f(x0,700-m);
	glVertex2f(x1,700-n);
	glEnd();
	glColor3fv(color[clr]);
	glLogicOp(GL_COPY);
	glBegin(GL_LINES);
	glVertex2f(x0,700-m);
	glVertex2f(x2,700-y2);
	glEnd();
	x1=x2;
	n=y2;
	glFlush();
}
void moulines(int b,int s,int x,int y)
{
	glLineWidth(size);
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x>75&&y>100))
	{
	if(twopt==0)
	{
		glEnable(GL_LINE_STIPPLE);
		x0=x1=x;
		m=n=y;
		if(linflg==2)
			glLineStipple(1,0x0101);
		else if(linflg==3)
			glLineStipple(1,0x00FF);
		else 
			glDisable(GL_LINE_STIPPLE);
		glColor3fv(color[clr]);
		glBegin(GL_LINES);
	glVertex2f(x0,m);
	glVertex2f(x1,n);
	glEnd();
	glFlush();
	glutMotionFunc(motlines);
	}
	else if(twopt==1)
	{
		if(evnpt==0)
		{
			x0=x; m=y;
			evnpt=1;
		}
		else if(evnpt==1)
		{
			glEnable(GL_LINE_STIPPLE);
			if(linflg==2)
			glLineStipple(1,0x0101);
		else if(linflg==3)
			glLineStipple(1,0x00FF);
		else 
			glDisable(GL_LINE_STIPPLE);
		glColor3fv(color[clr]);
		glBegin(GL_LINES);
		glVertex2f(x0,700-m);
		glVertex2f(x,700-y);
		glEnd();
		glFlush();
		evnpt=0;
		}
	}
	}

	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
	{
		if(x<513&&x>388)
			linflg=1;
		else if(x<713&&x>588)
			linflg=2;
		else if(x<913&&x>788)
			linflg=3;
		else if(x>1000&&y<100)
			clrset(x,y);
		else 
		{
			glDisable(GL_LINE_STIPPLE);
		glutMouseFunc(moumenucall);
		}
	}
}

//POLYGON FUNCTIONS
float p[1000]={0},q[1000]={0}; int cnt=0;
void moupoly(int b,int s,int x,int y)
{
	glutMotionFunc(donthng);
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&x>75&&y>100)
	{
	if(wire==1)
	{
	glLineWidth(size);
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&evnpoly==1&&x>75&&y>100)
	{
		glColor3fv(color[clr]);
		glBegin(GL_LINES);
		glVertex2f(x,700-y);
		glVertex2f(x0,700-m);
		glEnd();
		glFlush();
		evnpoly=0;
	}
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&evnpoly==0&&x>75&&y>100)
	{
		x0=x;
		m=y;
		evnpoly=1;
	}}
	else if(wire==0)
	{
		if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&x>75&&y>100)
		{
		glColor3fv(color[clr]);
		p[cnt]=x;
		q[cnt]=(700-y);
		cnt++;
		glBegin(GL_POLYGON);
			for(int i=0;i<cnt;i++)
				glVertex2f(p[i],q[i]);
		glEnd();
		glFlush();
		}
	}
	}
	else if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
	{
		if(x<600&&x>475&&y<100)
			wire=1;
		else if(x<825&&x>700&&y<100)
			wire=0;
		else if(x>1000&&y<100)
			clrset(x,y);
		else
			glutMouseFunc(moumenucall);
	}
}

//POINT FUNCTIONS
void moupts(int b,int s,int x,int y)
{
	glutMotionFunc(donthng);
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&y>100&&x>75)
	{
		glColor3fv(color[clr]);
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2f(x,700-y);
		glEnd();
		glFlush();
	}
	else if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
	{
		if(x>1000&&y<100)
			clrset(x,y);
		else
		glutMouseFunc(moumenucall);
	}
}

//CLEAR SCREEN
void clear()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(75,0); glVertex2f(75,600);
	glVertex2f(1250,600); glVertex2f(1250,0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(75,600); glVertex2f(75,625);
	glVertex2f(1000,625); glVertex2f(1000,600);
	glEnd();
	glFlush();
}
void clroptns()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(375,600);
	glVertex2f(925,600);
	glVertex2f(925,700);
	glVertex2f(375,700);
	glEnd();
	glFlush();
}

//TEXT FUNCTIONS
void keybrd(unsigned char k,int x,int y)
{
	glColor3fv(color[clr]);
	if(flgtxt==0)
	{
		glRasterPos2d(kx,700-ky);
		flgtxt=1;
		i+=10;
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,int(k));
	}
	else
	{
	if(i<1245)
	{
		if((int)k==13)
		{
			i=kx;j+=17;
		glRasterPos2d(i,700-j);
		}
		else if((int)k==8)
		{
			i-=10;
			glRasterPos2d(i,700-j);
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,32);
			glFlush();
		}
		else
		{
			glRasterPos2d(i,700-j);
			i+=10;
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,int(k));
		}
	}
	else
	{
		i=110;j+=17;
		glRasterPos2d(i,700-j);
		i+=10;
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,int(k));
	}
	}
	printf("%d   ",(int)k);
	glFlush();
}
void moutext(int b,int s,int x,int y)
{
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&x>75&&y>100)
	{
		kx=i=x;
		ky=j=y;
		glutKeyboardFunc(keybrd);
	}
	else if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
	{
		if(x>1000&&y<100)
			clrset(x,y);
		else
		glutMouseFunc(moumenucall);
	}
}

//CIRCLE FUNCTIONS
void motplcrcl(int x,int y)
{
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	for(th=0;th<360;th+=2)
	{
		thr=pi*th/180;
		glVertex2f(x0+(x1-x0)*cos(thr),(700-m)+(x1-x0)*sin(thr));
	}
	glEnd();
	
	glColor3fv(color[clr]);
	glBegin(GL_LINE_LOOP);
	for(th=0;th<360;th+=2)
	{
		thr=pi*th/180;
		glVertex2f(x0+(x-x0)*cos(thr),(700-m)+(x-x0)*sin(thr));
	}
	glEnd();
	x1=x;
	n=y;
	glFlush();
}
void mouplcrcl(int b,int s,int x,int y)
{
	glLineWidth(size);
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&x>75&&y>100)
	{
	if(twopt==0)
	{
		x0=x1=x;
		m=n=y;
		glutMotionFunc(motplcrcl);
		glColor3fv(color[clr]);
			glBegin(GL_LINE_LOOP);
			for(th=0;th<360;th+=2)
			{
				thr=pi*th/180;
				glVertex2f(x+(x-x0)*cos(thr),(700-y)+(x-x0)*sin(thr));
			}
			glEnd();
		glFlush();
	}
	else if(twopt==1)
	{
		glutMotionFunc(donthng);
		if(evnpt==0)
		{
			x0=x; m=y;
			evnpt=1;
		}
		else if(evnpt==1)
		{
			glColor3fv(color[clr]);
			glBegin(GL_LINE_LOOP);
			for(th=0;th<=360;th+=2)
			{
				thr=pi*th/180;
				glVertex2f(x0+(x-x0)*cos(thr),(700-m)+(x-x0)*sin(thr));
			}
			glEnd();
			glFlush();
			evnpt=0;
		}
	}
	}
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
	{
		if(x>1000&&y<100)
			clrset(x,y);
		else
		glutMouseFunc(moumenucall);
	}
}

void motflcrcl(int x,int y)
{
	glColor3f(0,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x0,(700-m));
	glVertex2f(x0+(x1-x0)*cos(thrp),(700-m)+(x1-x0)*sin(thrp));
	for(th=0;th<=380;th+=2)
	{
		thr=pi*th/180;
		glVertex2f(x0+(x1-x0)*cos(thr),(700-m)+(x1-x0)*sin(thr));
	}
	glEnd();
	
	glColor3fv(color[clr]);
	thrp=0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x0,(700-m));
	glVertex2f(x0+(x-x0)*cos(thrp),(700-m)+(x-x0)*sin(thrp));
	for(th=0;th<=380;th+=2)
	{
		thr=pi*th/180;
		glVertex2f(x0+(x-x0)*cos(thr),(700-m)+(x-x0)*sin(thr));
	}
	glEnd();
	x1=x;
	n=y;
	thrp=thr;
	glFlush();
}
void mouflcrcl(int b,int s,int x,int y)
{
			thrp=0;
		glLineWidth(size);
		if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&x>75&&y>100)
		{
			if(twopt==0)
			{
				x0=x1=x;
				m=n=y;
				glutMotionFunc(motflcrcl);
				glColor3fv(color[clr]);
				glBegin(GL_TRIANGLE_FAN);
				glVertex2f(x,(700-y));
				glVertex2f(x+(x-x0)*cos(thrp),(700-y)+(x-x0)*sin(thrp));
				for(th=0;th<=380;th+=2)
				{
					thr=pi*th/180;
					glVertex2f(x+(x-x0)*cos(thr),(700-y)+(x-x0)*sin(thr));
				}
				glEnd();
				glFlush();
			}
			else if(twopt==1)
			{
				glutMotionFunc(donthng);
			if(evnpt==0)
			{
				x0=x; m=y;
				evnpt=1;
			}
			else if(evnpt==1)
			{
				glColor3fv(color[clr]);
				glBegin(GL_TRIANGLE_FAN);
				for(th=0;th<=380;th+=2)
				{
					thr=pi*th/180;
					glVertex2f(x0+(x-x0)*cos(thr),(700-m)+(x-x0)*sin(thr));
				}
				glEnd();
				glFlush();
				evnpt=0;
			}
			}
		}

			if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
			{
				if(x>1000&&y<100)
					clrset(x,y);
				else
				glutMouseFunc(moumenucall);
			}
}


//OTHER FUNCTIONS
int tab[2]={0},z=0,tabm=0;
void drawgraph()
{
	clear();
	drawmenu();
	glColor3fv(color[clr]); 
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(200,50); glVertex2f(200,550);
	glVertex2f(150,100); glVertex2f(1150,100);
	glEnd();
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1,0x0101);
	glLineWidth(1);
	glBegin(GL_LINES);
	for(i=250;i<=1100;i+=50)
	{
		glVertex2f(i,100);
		glVertex2f(i,550);
	}
	glEnd();
	glBegin(GL_LINES);
	for(i=150;i<=500;i+=50)
	{
		glVertex2f(200,i);
		glVertex2f(1150,i);
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	glFlush();
}
void moutab(int b,int s,int x,int y)
{
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&x>75&&y>100)
	{
		tabm=0;
		glColor3fv(color[clr]);
		glBegin(GL_LINES);
		for(i=0;i<=tab[0];i++)
		{
			glVertex2f(x,(700-y)+tabm);
			glVertex2f(x+150*tab[1],(700-y)+tabm);
			tabm+=50;
		}
		glEnd();
		tabm=0;
		glBegin(GL_LINES);
		for(i=0;i<=tab[1];i++)
		{
			glVertex2f(x+tabm,(700-y));
			glVertex2f(x+tabm,(700-y)+50*tab[0]);
			tabm+=150;
		}
		glEnd();
		glFlush();
	}
	else if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
		glutMouseFunc(moumenucall);
}

void check(unsigned char k)
{
	if(int(k)==49) p[z]=1;
	else if(int(k)==50) tab[z]=2;
	else if(int(k)==51) tab[z]=3;
	else if(int(k)==52) tab[z]=4;
	else if(int(k)==53) tab[z]=5;
	else if(int(k)==54) tab[z]=6;
	else if(int(k)==55) tab[z]=7;
	else if(int(k)==56) tab[z]=8;
	else if(int(k)==57) tab[z]=9;
}
void keybrdtab(unsigned char k,int x,int y)
{
	check(k);
	printf("%d  ",tab[z]);
	z++;
	glutMouseFunc(moutab);
}

int oth=0,rad;
void mouspiral(int b,int s,int x,int y)
{
	glutMotionFunc(donthng);
	glLineWidth(size);
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&oth==1&&x>100&&y>100)
	{
		isp=0;
		if(evnsp==0)
		{
			x0=x;
			m=y;
			evnsp=1;
		}
		else if(evnsp==1)
		{
			r=x-x0;
			r=r/9;
			glBegin(GL_LINE_STRIP);
			glColor3fv(color[clr]);
			while(ra<=r)
			{
			for(th=0;th<=360;th+=2)
			{
				thr=pi*th/180;
				glVertex2f(x0+isp*cos(thr),(700-m)+isp*sin(thr));
				isp+=.05;
			}
			ra++;
			}
		glEnd();
		glFlush();
		evnsp=0;isp=0;ra=0;
		}
	}
	else if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&oth==2&&x>100&&y>100)
	{
		if(evnsp==0)
		{
			x0=x;
			m=y;
			evnsp=1;
		}
		else if(evnsp==1)
		{
		glColor3fv(color[clr]);
		glBegin(GL_LINES);
		glVertex2f(x0+30,700-m); glVertex2f(x-30,700-m);
		glVertex2f(x,(700-m)+30); glVertex2f(x,(700-y)-30);
		glVertex2f(x-30,700-y); glVertex2f(x0+30,700-y);
		glVertex2f(x0,(700-m)+30); glVertex2f(x0,(700-y)-30);
		glEnd();
		glBegin(GL_LINE_STRIP);
		for(th=0;th<=90;th+=5)
		{ thr=pi*th/180; glVertex2f((x-30)+30*cos(thr),((700-y)-30)+30*sin(thr)); }
		glEnd();
		glBegin(GL_LINE_STRIP);
		for(th=90;th<=180;th+=5)
		{ thr=pi*th/180; glVertex2f((x0+30)+30*cos(thr),((700-y)-30)+30*sin(thr)); }
		glEnd();
		glBegin(GL_LINE_STRIP);
		for(th=180;th<=270;th+=5)
		{ thr=pi*th/180; glVertex2f((x0+30)+30*cos(thr),((700-m)+30)+30*sin(thr)); }
		glEnd();
		glBegin(GL_LINE_STRIP);
		for(th=270;th<=360;th+=5)
		{ thr=pi*th/180; glVertex2f((x-30)+30*cos(thr),((700-m)+30)+30*sin(thr)); }
		glEnd();
		glFlush();
		evnsp=0;
		}
	}
	else if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&oth==3&&x>100&&y>100)
	{
		if(evnsp==0)
		{
			x0=x;
			m=y;
			evnsp=1;
		}
		else if(evnsp==1)
		{
			rad=x-x0;
			th=90;
			thr=pi*th/180;
			glColor3fv(color[clr]);
			for(i=0;i<5;i++)
			{
				p[i]=x0+rad*cos(thr);
				q[i]=(700-m)+rad*sin(thr);
				th+=72;
				thr=pi*th/180;
			}
			glBegin(GL_LINE_LOOP);
			glVertex2f(p[0],q[0]);
			glVertex2f(p[2],q[2]);
			glVertex2f(p[4],q[4]);
			glVertex2f(p[1],q[1]);
			glVertex2f(p[3],q[3]);
			glEnd();
			glFlush();
			evnsp=0;
		}
	}
	else if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<100||y<100))
	{
		if(x>1000&&y<100)
			clrset(x,y);
		else if(x>400&&x<500)
			oth=1;
		else if(x>500&&x<600)
			oth=2;
		else if(x>600&&x<700)
			oth=3;
		else if(x>700&&x<800)
		{
			tab[0]=0;tab[1]=0;z=0;
			glutKeyboardFunc(keybrdtab);
		}
		else if(x>800&&x<900)
			drawgraph();
		else 
		{
			glLineWidth(1);
			glutMouseFunc(moumenucall);
		}
	}
}

//SPRAY FUNCTION
void motspray(int x,int y)
{
	glColor3fv(color[clr]);
	glBegin(GL_POINTS);
		glVertex2f(x,700-y); glVertex2f(x+4,700-y);
		glVertex2f(x+4,700-y+5); glVertex2f(x,700-y+6);
		glVertex2f(x+8,700-y+9); glVertex2f(x+7,700-y+5);
		glVertex2f(x+5,700-y+7); glVertex2f(x+5,700-y+9);
		glVertex2f(x+6,700-y+5); glVertex2f(x,700-y+4);
		glVertex2f(x+12,700-y+7); glVertex2f(x+12,700-y);
		glVertex2f(x+10,700-y+4);
		glEnd();
	glFlush();
}
void mouspray(int b,int s,int x,int y)
{
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&evnsp==0&&x>100&&y>100)
	{
	glutMotionFunc(motspray);
	glPointSize(1);
	}
	else if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<100||y<100))
	{
		if(x>1000&&y<100)
			clrset(x,y);
		else 
		glutMouseFunc(moumenucall);
	}
}

//PAINT FUNCTIONS
int pflg=5;
void motpaint(int x,int y)
{
	if(pflg==5)
	{
		glPointSize(10);
		glBegin(GL_POINTS);
		glVertex2f(x,700-y);
		glEnd();
	}
	else
	{
	glBegin(GL_LINES);
	if(pflg==1)
	{
	glVertex2f(x,700-y+10); glVertex2f(x,700-y-10);
	glEnd();
	}
	else if(pflg==2)
	{
		glVertex2f(x-10,700-y-10); glVertex2f(x+10,700-y+10);
		glEnd();
	}
	else if(pflg==3)
	{
		glVertex2f(x-10,700-y+10); glVertex2f(x+10,700-y-10);
		glEnd();
	}}
	glFlush();
}
void moupaint(int b,int s,int x,int y)
{
	if(x>75&&y>100)
	{
		x0=x;
		m=y;
		glColor3fv(color[clr]);
		glLineWidth(5);
		if(pflg==5)
		{
			glPointSize(10);
			glBegin(GL_POINTS);
			glVertex2f(x,700-y);
			glEnd();
		}
		else 
		{
			glBegin(GL_LINES);
			if(pflg==1)
		{
			glVertex2f(x,700-y+10); glVertex2f(x,700-y-10);
			glEnd();
		}
		else if(pflg==2)
		{
			glVertex2f(x-10,700-y-10); glVertex2f(x+10,700-y+10);
			glEnd();
		}
		else if(pflg==3)
		{
			glVertex2f(x-10,700-y+10); glVertex2f(x+10,700-y-10);
			glEnd();
		}}
		glFlush();
		glutMotionFunc(motpaint);
	}
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN&&(x<75||y<100))
	{
		if(x>1000&&y<100)
			clrset(x,y);
		else if(x>388&&x<513)
			pflg=1;
		else if(x>588&&x<713)
			pflg=2;
		else if(x>788&&x<913)
			pflg=3;
		else
		{
			glLineWidth(1);
			pflg=5;
			glutMouseFunc(moumenucall);
		}
	}
}

//STRING DRAW
void drawstring(char * s)
{
	str=0;
	while(s[str]!='\0')
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)s[str]);
		strx+=10;
		glRasterPos2d(strx,stry);
		str++;
	}
}

//OPTIONS DRAW
int o;
void drawoptns(int n)
{
	if(n==2)
		o=475;
	else if(n==3)
		o=388;
	while(o<=800)
	{
			glColor3f(.5,.5,.5);
			glBegin(GL_POLYGON);
			glVertex2f(o,625); glVertex2f(o,675);
			glVertex2f(o+125,675); glVertex2f(o+125,625);
			glEnd();
			glColor3f(.75,.75,.75);
			glBegin(GL_POLYGON);
			glVertex2f(o+10,635); glVertex2f(o+10,665);
			glVertex2f(o+115,665); glVertex2f(o+115,635);
			glEnd();
			if(n==2)
			o+=225;
			else if(n==3)
				o+=200;
	}
	glFlush();
}
int no=0;
void drawothers()
{
	no=0;isp=0;
	glLineWidth(1);
	glColor3f(.9,0,1.7);
	glBegin(GL_POLYGON);
	glVertex2f(400,690); glVertex2f(500,690);
	glVertex2f(500,625); glVertex2f(400,625);
	glEnd(); glBegin(GL_POLYGON);
	glVertex2f(500,690); glVertex2f(600,690);
	glVertex2f(600,625); glVertex2f(500,625);
	glEnd(); glBegin(GL_POLYGON);
	glVertex2f(600,690); glVertex2f(700,690);
	glVertex2f(700,625); glVertex2f(600,625);
	glEnd(); glBegin(GL_POLYGON);
	glVertex2f(700,690); glVertex2f(800,690);
	glVertex2f(800,625); glVertex2f(700,625);
	glEnd(); glBegin(GL_POLYGON);
	glVertex2f(800,690); glVertex2f(900,690);
	glVertex2f(900,625); glVertex2f(800,625);
	glEnd();
	glLineWidth(3);
	glColor3f(0,0,0); glBegin(GL_LINES);
	glVertex2f(500,690); glVertex2f(500,625);
	glVertex2f(600,625); glVertex2f(600,690);
	glEnd(); glBegin(GL_LINES);
	glVertex2f(700,690); glVertex2f(700,625);
	glVertex2f(800,625); glVertex2f(800,690);
	glEnd(); glBegin(GL_LINES);
	glVertex2f(500,690); glVertex2f(500,625);
	glVertex2f(600,625); glVertex2f(600,690);
	glEnd();
	glLineWidth(1);

	//SPIRAL
	glColor3f(0,0,0); glBegin(GL_LINE_STRIP);
	while(no<3)
	{
		for(th=0;th<=360;th+=2)
		{
			thr=pi*th/180;
			glVertex2f(450+isp*cos(thr),660+isp*sin(thr));
			isp+=.05;
		}
	no++;
	}
	glEnd();
	//ROUNDED RECT
		glBegin(GL_LINES);
		glVertex2f(520,650); glVertex2f(520,665);
		glVertex2f(530,675); glVertex2f(570,675);
		glVertex2f(580,665); glVertex2f(580,650);
		glVertex2f(530,640); glVertex2f(570,640);
		glEnd();
		glBegin(GL_LINE_STRIP);
		for(th=0;th<=90;th+=5)
		{ thr=pi*th/180; glVertex2f(570+10*cos(thr),665+10*sin(thr)); }
		glEnd();
		glBegin(GL_LINE_STRIP);
		for(th=90;th<=180;th+=5)
		{ thr=pi*th/180; glVertex2f(530+10*cos(thr),665+10*sin(thr)); }
		glEnd();
		glBegin(GL_LINE_STRIP);
		for(th=180;th<=270;th+=5)
		{ thr=pi*th/180; glVertex2f(530+10*cos(thr),650+10*sin(thr)); }
		glEnd();
		glBegin(GL_LINE_STRIP);
		for(th=270;th<=360;th+=5)
		{ thr=pi*th/180; glVertex2f(570+10*cos(thr),650+10*sin(thr)); }
		glEnd();

	//STAR
		glBegin(GL_LINE_LOOP);
		glVertex2f(650+25*cos(1.571),655+25*sin(1.571));
		glVertex2f(650+25*cos(4.0846),655+25*sin(4.0846));
		glVertex2f(650+25*cos(6.5962),655+25*sin(6.5962));
		glVertex2f(650+25*cos(2.8278),655+25*sin(2.8278));
		glVertex2f(650+25*cos(5.3414),655+25*sin(5.3414));
		glEnd();

	//TABLE
		glColor3f(0,0,0);
		strx=725;stry=653;
		glRasterPos2d(strx,stry);
		drawstring("TABLE");
	//GRAPH
		glColor3f(0,0,0);
		strx=825;stry=653;
		glRasterPos2d(strx,stry);
		drawstring("GRAPH");
	glFlush();
	glLineWidth(size);
}


//MAIN MENU
int s;
void moumenucall(int b,int s,int x,int y)
{
	glutMotionFunc(donthng);
	glLineWidth(1);
	drawmenu();
	if(x<75)
	{
		if(y>625)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-625); glVertex2f(0,700-700);
			glVertex2f(75,700-700); glVertex2f(75,700-625);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			drawoptns(2);
			glColor3f(0,0,0);
			strx=510;stry=645;
			glRasterPos2d(strx,stry);
			drawstring("PLAIN");
			glColor3f(0,0,0);
			strx=730;stry=645;
			glRasterPos2d(strx,stry);
			drawstring("FILLED");
			glFlush();
			wire=1;
			evnpt=0;
			glutMouseFunc(mourect);
		}
		else if(y<400&&y>325)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-400); glVertex2f(0,700-325);
			glVertex2f(75,700-325); glVertex2f(75,700-400);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			drawoptns(3);
			glColor3f(0,0,0);
			glBegin(GL_POLYGON);
			glVertex2f(445,645); glVertex2f(445,655);
			glVertex2f(455,655); glVertex2f(455,645);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex2f(640,640); glVertex2f(640,660);
			glVertex2f(660,660); glVertex2f(660,640);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex2f(835,635); glVertex2f(835,665);
			glVertex2f(865,665); glVertex2f(865,635);
			glEnd();
			glFlush();
			glutMouseFunc(moueraser);
		}
		else if(y<475&&y>400)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-400); glVertex2f(0,700-475);
			glVertex2f(75,700-475); glVertex2f(75,700-400);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			glutMouseFunc(moupencil);
		}
		else if(y<550&&y>475)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-550); glVertex2f(0,700-475);
			glVertex2f(75,700-475); glVertex2f(75,700-550);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			drawoptns(3);
			glColor3f(0,0,0);
			strx=423;stry=645;
			glRasterPos2d(strx,stry);
			drawstring("PLAIN");
			glColor3f(0,0,0);
			strx=623;stry=645;
			glRasterPos2d(strx,stry);
			drawstring("DOTTED");
			glColor3f(0,0,0);
			strx=823;stry=645;
			glRasterPos2d(strx,stry);
			drawstring("DASHED");
			glFlush();
			linflg=1;
			evnpt=0;
			glutMouseFunc(moulines);
		}
		else if(y<625&&y>550)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-625); glVertex2f(0,700-550);
			glVertex2f(75,700-550); glVertex2f(75,700-625);
			glEnd(); glFlush();
			glLineWidth(size);
			evnpoly=0;
			clroptns();
			drawoptns(2);
			glColor3f(0,0,0);
			strx=510;stry=645;
			glRasterPos2d(strx,stry);
			drawstring("PLAIN");
			glColor3f(0,0,0);
			strx=730;stry=645;
			glRasterPos2d(strx,stry);
			drawstring("FILLED");
			glFlush();
			wire=1;
			cnt=0;
			glutMouseFunc(moupoly);
		}
		else if(y<325&&y>250)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-325); glVertex2f(0,700-250);
			glVertex2f(75,700-250); glVertex2f(75,700-325);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			drawoptns(2);
			glColor3f(0,0,0);
			strx=510;stry=645;
			glRasterPos2d(strx,stry);
			drawstring("PLAIN");
			glColor3f(0,0,0);
			strx=730;stry=645;
			glRasterPos2d(strx,stry);
			drawstring("FILLED");
			glFlush();
			evnpt=0;
			glutMouseFunc(mouplcrcl);
		}
		else if(y<250&&y>175)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-250); glVertex2f(0,700-175);
			glVertex2f(75,700-175); glVertex2f(75,700-250);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			glutMouseFunc(moupts);
		}
		else if(y<100&&y>25)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-100); glVertex2f(0,700-25);
			glVertex2f(75,700-25); glVertex2f(75,700-100);
			glEnd(); glFlush();
			glLineWidth(size);
			flgtxt=0;
			clroptns();
			glutMouseFunc(moutext);
		}
		else if(y<175&&y>100)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-100); glVertex2f(0,700-175);
			glVertex2f(75,700-175); glVertex2f(75,700-100);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			glutMouseFunc(mouspray);
		}
	}
	else if(y<75&&x<1000)
	{
		if(x<225&&x>150)
		{
			clroptns();
			clear();
			drawmenu();
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(225,700); glVertex2f(225,625);
			glVertex2f(150,625); glVertex2f(150,700);
			glEnd(); glFlush();
			glLineWidth(size);
		}
		else if(x<150&&x>75)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(150,700); glVertex2f(150,625);
			glVertex2f(75,625); glVertex2f(75,700);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			drawoptns(3);
			glColor3f(0,0,0);
			glLineWidth(3);
			glBegin(GL_LINES); 
			glVertex2f(450,640); glVertex2f(450,660); 
			glVertex2f(640,640); glVertex2f(660,660); 
			glVertex2f(860,640); glVertex2f(840,660); 
			glEnd();
			glFlush();
			glLineWidth(1);
			glutMouseFunc(moupaint);
		}
		else if(x<300&&x>225)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(300,700); glVertex2f(300,625);
			glVertex2f(225,625); glVertex2f(225,700);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			drawothers();
			oth=0;
			glutMouseFunc(mouspiral);
		}
		else if(x<825&&x>700) 
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-325); glVertex2f(0,700-250);
			glVertex2f(75,700-250); glVertex2f(75,700-325);
			glEnd(); glFlush();
			glLineWidth(size);
			evnpt=0;
			glutMouseFunc(mouflcrcl);
		}
		else if(x<600&&x>475) 
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0,700-325); glVertex2f(0,700-250);
			glVertex2f(75,700-250); glVertex2f(75,700-325);
			glEnd(); glFlush();
			glLineWidth(size);
			evnpt=0;
			glutMouseFunc(mouplcrcl);
		}
		else if(x>300&&x<375)
		{
			glColor3f(0,0,0); glLineWidth(5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(300,700); glVertex2f(300,625);
			glVertex2f(375,625); glVertex2f(375,700);
			glEnd(); glFlush();
			glLineWidth(size);
			clroptns();
			drawoptns(3);
			glColor3f(0,0,0);
			glLineWidth(1);
			glBegin(GL_LINES); glVertex2f(420,650); 
			glVertex2f(480,650); glEnd();
			glLineWidth(3);
			glBegin(GL_LINES); glVertex2f(620,650); 
			glVertex2f(680,650); glEnd();
			glLineWidth(5);
			glBegin(GL_LINES); glVertex2f(820,650); 
			glVertex2f(880,650); glEnd();
			glFlush();
			glLineWidth(1);
		}
		else if(x<990&&x>925&&s==GLUT_DOWN&&b==GLUT_LEFT_BUTTON)
		{
			if(twopt==0)
				twopt=1;
			else if(twopt==1)
				twopt=0;
			drawmenu();
		}
		else if(y<100&&x>388&&x<913)
		{
			if(x<513&&x>388)
				size=1;
			else if(x<713&&x>588)
				size=3;
			else if(x<913&&x>788)
				size=5;
		}
	}
}
void init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1249,0,699);
	glMatrixMode(GL_MODELVIEW);
}

void nthng()
{}
void main(int argc, char * argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1250,700);
	glutCreateWindow("project");
	glutDisplayFunc(display);
	glutIdleFunc(nthng);
	glutMouseFunc(moumenucall);
	init();
	glutMainLoop();
}


