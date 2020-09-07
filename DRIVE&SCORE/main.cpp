 #include <iostream>
using namespace std;
#include <GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include <windows.h>
#include <mmsystem.h>
//#include "RGBPixMAP.h"

int score, exit1 = 0;
int menu;
float x, y;
float x1 = 390, y1 = 1000, x2 = 230, y2 = 1500;
int time = 0;
typedef struct lines
{
	int x, y;
}linet;
linet line[5];

void car(float a, float b)
{
	glPushMatrix();
	glTranslated(230, 30, 0);
	//BODY
	glBegin(GL_POLYGON);


	glColor3f(0, 0.6, 0.6);

	glVertex2f(0 + a, 8 + b);
	glVertex2f(1 + a, 5 + b);
	glVertex2f(2 + a, 2 + b);
	glVertex2f(3 + a, 1 + b);
	glVertex2f(5 + a, 0 + b);
	glVertex2f(75 + a, 0 + b);
	glVertex2f(78 + a, 1 + b);
	glColor3f(0, 0.4, 0.4);
	glVertex2f(79 + a, 2 + b);
	glVertex2f(80 + a, 5 + b);

	glVertex2f(81 + a, 8 + b);
	glVertex2f(81 + a, 75 + b);
	glVertex2f(79 + a, 77 + b);
	glVertex2f(78 + a, 78 + b);

	glVertex2f(75 + a, 81 + b);
	glVertex2f(72 + a, 84 + b);
	glVertex2f(71 + a, 85 + b);
	glVertex2f(69 + a, 86 + b);
	glVertex2f(68 + a, 87 + b);
	glColor3f(0.1, 0.3, 0.3);
	//
	glVertex2f(60 + a, 88 + b);
	glVertex2f(21 + a, 88 + b);
	//
	glVertex2f(13 + a, 87 + b);

	glVertex2f(12 + a, 86 + b);
	glVertex2f(10 + a, 85 + b);
	glVertex2f(9 + a, 84 + b);
	glVertex2f(6 + a, 81 + b);
	glVertex2f(3 + a, 78 + b);
	glVertex2f(2 + a, 77 + b);
	glVertex2f(0 + a, 75 + b);

	glEnd();

	//red bump
	glBegin(GL_POLYGON);
	glColor3f(1, 0.2, 0.2);
	glVertex2f(5 + a, 0 + b);
	glVertex2f(25 + a, 0 + b);
	glVertex2f(25 + a, 2 + b);
	glVertex2f(5 + a, 2 + b);
    glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0.2, 0.2);
	glVertex2f(55 + a, 0 + b);
	glVertex2f(75 + a, 0 + b);
	glVertex2f(75 + a, 2 + b);
	glVertex2f(55 + a, 2 + b);
	glEnd();

	//BACK GLASS
	glBegin(GL_POLYGON);

	glColor3f(0.6f, 0.6f, 0.6f);

	glVertex2f(13 + a, 12 + b);
	glVertex2f(15 + a, 11 + b);
	glVertex2f(17 + a, 8 + b);
	glVertex2f(40.5 + a, 6 + b);
	glVertex2f(64 + a, 8 + b);
	glVertex2f(66 + a, 11 + b);
	glVertex2f(68 + a, 12 + b);

	glVertex2f(68 + a, 22 + b);
	glVertex2f(65 + a, 20 + b);
	glVertex2f(64 + a, 18 + b);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(17 + a, 18 + b);
	glVertex2f(15 + a, 20 + b);
	glVertex2f(13 + a, 22 + b);

	glEnd();

	//FRONT GLASS
	glBegin(GL_POLYGON);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex2f(13 + a, 59 + b);
	glVertex2f(15 + a, 60 + b);
	glVertex2f(17 + a, 63 + b);
	glVertex2f(40.5 + a, 65 + b);
	glVertex2f(64 + a, 63 + b);
	glVertex2f(66 + a, 60 + b);
	glVertex2f(68 + a, 59 + b);

	glVertex2f(68 + a, 49 + b);
	glVertex2f(66 + a, 49.5 + b);


	glVertex2f(64 + a, 51 + b);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(40.5 + a, 45 + b);
	glVertex2f(17 + a, 51 + b);
	glVertex2f(15 + a, 50 + b);
	glVertex2f(13 + a, 49 + b);
	glEnd();

	//RIGHT LOOKING GLASS
	glBegin(GL_POLYGON);
	glColor3f(0, 0.3, 0.3);
	glVertex2f(81 + a, 50 + b);
	glVertex2f(86 + a, 50 + b);
	glVertex2f(81 + a, 56 + b);
	glEnd();

	//LEFT LOOKING GLASS
	glBegin(GL_POLYGON);
	glColor3f(0, 0.3, 0.3);
	glVertex2f(0 + a, 50 + b);
	glVertex2f(-5 + a, 50 + b);
	glVertex2f(0 + a, 56 + b);
	glEnd();


	//LEFT GLASS
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(6 + a, 22 + b);
	glVertex2f(8 + a, 23 + b);
	glVertex2f(13 + a, 24 + b);
	glVertex2f(13 + a, 44 + b);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2f(8 + a, 45 + b);
	glVertex2f(6 + a, 46 + b);
	glEnd();

	//RIGHT GLASS
	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(75 + a, 22 + b);
	glVertex2f(73 + a, 23 + b);
	glVertex2f(68 + a, 24 + b);
	glVertex2f(68 + a, 44 + b);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2f(73 + a, 45 + b);
	glVertex2f(75 + a, 46 + b);
	glEnd();



	glPopMatrix();
	glFlush();
}



void enemy(float a, float b)
{
	glPushMatrix();
	//glTranslated(390, 20, 0);

	glBegin(GL_POLYGON);


	glColor3f(0.8, 0.8, 0);
	//BODY
	glVertex2f(1 + a, 3 + b);
	glVertex2f(80 + a, 3 + b);
	glVertex2f(80 + a, 55 + b);
	glVertex2f(1 + a, 55 + b);
	glEnd();
	//BODY 2
	glBegin(GL_POLYGON);


	glColor3f(0.5, 0.5, 0);
	//BODY
	glVertex2f(5 + a, 8 + b);
	glColor3f(0.5, 0.5, 0);
	glVertex2f(75 + a, 8 + b);
	glColor3f(0.6, 0.5, 0);
	glVertex2f(75 + a, 63 + b);
	glColor3f(0.5, 0.5, 0);
	glVertex2f(5 + a, 63 + b);
	glEnd();
	//HEAD
	glBegin(GL_POLYGON);


	glColor3f(0.8, 0.8, 0);
	glVertex2f(1 + a, 55 + b);
	glVertex2f(80 + a, 55 + b);
	glVertex2f(80 + a, 83 + b);
	glVertex2f(79 + a, 84 + b);
	glVertex2f(78 + a, 85 + b);
	glVertex2f(77 + a, 86 + b);
	glVertex2f(76 + a, 87 + b);
	glVertex2f(75.5 + a, 88 + b);
	glColor3f(0.6, 0.6, 0);
	glVertex2f(6.5 + a, 88 + b);

	glVertex2f(5 + a, 87 + b);

	glVertex2f(4 + a, 86 + b);
	glVertex2f(3 + a, 85 + b);
	glVertex2f(2 + a, 84 + b);
	glVertex2f(1 + a, 83 + b);
	glEnd();
	//GLASS
	glBegin(GL_POLYGON);


	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(5 + a, 60 + b);
	glVertex2f(6 + a, 62 + b);
	glVertex2f(7 + a, 64 + b);
	glVertex2f(75 + a, 64 + b);
	glVertex2f(76 + a, 62 + b);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(77 + a, 60 + b);

	glVertex2f(77 + a, 70 + b);
	glVertex2f(75 + a, 74 + b);
	glVertex2f(7 + a, 74 + b);
	//glVertex2f(6 + a, 72 + b);
	//glColor3f(0.6, 0.6, 0.6);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(5 + a, 70 + b);

	glEnd();

    //black line
	glBegin(GL_POLYGON);


	glColor3f(0, 0, 0);
	glVertex2f(1 + a, 55 + b);
	glVertex2f(80 + a, 55 + b);
	glColor3f(1, 0.8, 0.8);
	glVertex2f(80 + a, 57 + b);
	glVertex2f(1 + a, 57 + b);

	glEnd();

	//left top tire
	glBegin(GL_POLYGON);


	glColor3f(0, 0, 0);
	glVertex2f(80 + a, 65 + b);
	glVertex2f(82 + a, 65 + b);
	glVertex2f(82 + a, 75 + b);
	glVertex2f(80 + a, 75 + b);

	glEnd();

    //right top tire
	glBegin(GL_POLYGON);


	glColor3f(0, 0, 0);
	glVertex2f(1 + a, 65 + b);
	glVertex2f(-1 + a, 65 + b);
	glVertex2f(-1 + a, 75 + b);
	glVertex2f(1 + a, 75 + b);

	glEnd();
	//left bottom tire
	glBegin(GL_POLYGON);


	glColor3f(0, 0, 0);
	glVertex2f(80 + a, 25 + b);
	glVertex2f(82 + a, 25 + b);
	glVertex2f(82 + a, 15 + b);
	glVertex2f(80 + a, 15 + b);

	glEnd();
	//right bottom tire
	glBegin(GL_POLYGON);


	glColor3f(0, 0, 0);
	glVertex2f(1 + a, 25 + b);
	glVertex2f(-1 + a, 25 + b);
	glVertex2f(-1 + a, 15 + b);
	glVertex2f(1 + a, 15 + b);

	glEnd();
	//END BODY
	glBegin(GL_POLYGON);


	glColor3f(1, 0.2, 0.2);
	glVertex2f(39.5 + a, 3 + b);
	glVertex2f(39.5 + a, 1 + b);
	glVertex2f(15 + a, 1 + b);
	//
	glVertex2f(15 + a, 0 + b);
	glVertex2f(65 + a, 0 + b);
	//
	glVertex2f(65 + a, 1 + b);
	glVertex2f(40.5 + a, 1 + b);
	glVertex2f(40.5 + a, 3 + b);
	glEnd();


	glPopMatrix();
	glFlush();
}

void Road()
{

	glBegin(GL_POLYGON);

	glColor3f(0.5, 0.5, 0.5);

	glVertex2f(200, 0);
	glVertex2f(200, 700);
	glVertex2f(500, 700);
	glVertex2f(500, 0);


	glEnd();


	glFlush();
}

void sc(int a)
{
	int i, j, k;
	i = a / 100;
	j = a / 10 - i * 10;
	k = a - j * 10 - i * 100;

	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(-220, 170, 0);
	glScaled(0.1, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'c');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'e');

	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)':');

	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)i + 48);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)j + 48);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)k + 48);

	glPopMatrix();
}
void Menu1(int a) {

	glutIdleFunc(NULL);

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(160, 330, 0);
	glScaled(.2, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'->');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'R');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'a');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'t');

	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(190, 270, 0);
	glScaled(.2, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'->');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'E');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'x');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'i');
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'t');


	glPopMatrix();
	glFlush();
}


void myDisplay()
{
	//glPushAttrib(GL_ALL_ATTRIB_BITS);
	if (exit1 == 0)
	{
		if (score < 10)
		{
			y1 -= .2;
			y2 -= .2;

		}
		if (score >= 10 && score <20)
		{
			y1 -= .5;
			y2 -= .5;

		}
		if (score >= 20 && score < 50)
		{
			y1 -= 1;
			y2 -= 1;

		}
		if (score >=50)
		{
			y1 -= 1.5;
			y2 -= 1.5;

		}
		if (y1<-5)
		{

			score += 2;
			y1 = 1000;

		}
		if (y2<-5)
		{
			score += 2;
			y2 = 2000;

		}


		//sides of road
		//Left
		glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		glVertex2f(0, 0);
		glVertex2f(150, 0);
		glVertex2f(150, 700);
		glVertex2f(0, 700);
		//sndPlaySound("CARRO2.WAV",SND_ASYNC); //display sound
		glEnd();

        //Right
		glBegin(GL_POLYGON);
		glColor3f(0, 1, 0);
		glVertex2f(550, 0);
		glVertex2f(550, 700);
		glVertex2f(750, 700);
		glVertex2f(750, 0);
		glEnd();

        //Left2
        glBegin(GL_POLYGON);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2f(150, 0);
		glVertex2f(200, 0);
		glVertex2f(200, 700);
		glVertex2f(150, 700);
		glEnd();

		//Priht2
		glBegin(GL_POLYGON);
		glColor3f(0.7, 0.7, 0.7);
		glVertex2f(500, 0);
		glVertex2f(500, 700);
		glVertex2f(550, 700);
		glVertex2f(550, 0);
		glEnd();
		 //Hill 1
        glColor3f(0.235, 0.702, 0.443);
        glBegin(GL_TRIANGLES);
        glVertex2f(20,55+10);
        glVertex2f(20+7,55);
        glVertex2f(0,55);
        glEnd();

        //Hill 2
        glColor3f(0.000, 0.502, 0.000);
        glBegin(GL_TRIANGLES);
        glVertex2f(20+15,55+12);
        glVertex2f(20+20+10,55);
        glVertex2f(0+10,55);
        glEnd();

        //Hill 4
        glColor3f(0.235, 0.702, 0.443);
        glBegin(GL_TRIANGLES);
        glVertex2f(87,55+10);
        glVertex2f(100,55);
        glVertex2f(60,55);
        glEnd();

         //Hill 3
        glColor3f(0.000, 0.502, 0.000);
        glBegin(GL_TRIANGLES);
        glVertex2f(70,70);
        glVertex2f(90,55);
        glVertex2f(50,55);
        glEnd();


        //Tree Left
            //Bottom
        glColor3f(0.871, 0.722, 0.529);
        glBegin(GL_TRIANGLES);
        glVertex2f(11,55);
        glVertex2f(12,55-10);
        glVertex2f(10,55-10);
        glEnd();
            //Up
      glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_TRIANGLES);
        glVertex2f(11,55+3);
        glVertex2f(12+3,55-3);
        glVertex2f(10-3,55-3);
        glEnd();




 //Hill 1
        glColor3f(0.235, 0.702, 0.443);
        glBegin(GL_TRIANGLES);
        glVertex2f(20,55+10);
        glVertex2f(20+7,55);
        glVertex2f(0,55);
        glEnd();

        //Hill 2
        glColor3f(0.000, 0.502, 0.000);
        glBegin(GL_TRIANGLES);
        glVertex2f(20+15,55+12);
        glVertex2f(20+20+10,55);
        glVertex2f(0+10,55);
        glEnd();

        //Hill 4
        glColor3f(0.235, 0.702, 0.443);
        glBegin(GL_TRIANGLES);
        glVertex2f(87,55+10);
        glVertex2f(100,55);
        glVertex2f(60,55);
        glEnd();

         //Hill 3
        glColor3f(0.000, 0.502, 0.000);
        glBegin(GL_TRIANGLES);
        glVertex2f(70,70);
        glVertex2f(90,55);
        glVertex2f(50,55);
        glEnd();


        //Tree Left
            //Bottom
        glColor3f(0.871, 0.722, 0.529);
        glBegin(GL_TRIANGLES);
        glVertex2f(11,55);
        glVertex2f(12,55-10);
        glVertex2f(10,55-10);
        glEnd();
            //Up
      glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_TRIANGLES);
        glVertex2f(11,55+3);
        glVertex2f(12+3,55-3);
        glVertex2f(10-3,55-3);
        glEnd();








		Road();

		//road divider & coming down
		glPushMatrix();
		glTranslated(340, 0, 0);
		glColor3f(1.0, 1.0, 1.0);
		for (int i = 0; i < 5; i++)
		{
			line[i].y += -2;
			if (line[i].y < -200)
			{
				line[i].y += 800;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			glBegin(GL_POLYGON);
			glVertex2f(line[i].x, line[i].y + 10);
			glVertex2f(line[i].x, line[i].y + 110);
			glVertex2f(line[i].x + 20, line[i].y + 110);
			glVertex2f(line[i].x + 20, line[i].y + 10);
			glEnd();

		}


		glPopMatrix();

		glFlush();

		glPushMatrix();
		glTranslated(520, 300, 0);
		sc(score);
		glPopMatrix();

		//Menu(menu);
		car(x, y);
		enemy(x1, y1);
		enemy(x2, y2);



		//collision
		//if (x <-30 || x > 270)exit1 = 1;
		if (x <-30)
		{
			x = 0;

		}
		if (x >270)
		{
			x = 160;
			//glutPostRedisplay();
		}

		if (0 + x>150 && 88 + x<300)
			if (88 + y>-25 + y1 && 88 + y1 > 0 + y)
			{
				Menu1(menu);

			}

		if (0 + x>-1 && 88 + x<150)
			if (88 + y>-25 + y2 && 88 + y2>0 + y)
			{

				Menu1(menu);
			}
		//exit1 = 1;


		glutSwapBuffers();


	}
	else
	{

		glLineWidth(5);
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();
		glTranslated(220, 300, 0);
		sc(score);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 0.5, 0.0);
		glTranslated(130, 350, 0);
		glScaled(.3, .2, 0);
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'G');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'A');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'M');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'E');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'O');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'V');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'E');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'R');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 1, 0);
		glTranslated(130, 150, 0);
		glScaled(.3, .2, 0);
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'T');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'H');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'A');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'N');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'K');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'Y');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'O');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'U');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
	sndPlaySound("collison.WAV",SND_ASYNC); //display sound

		glFlush();
		glutSwapBuffers();
	}
}



void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 750.0, 0.0, 500.0);

}

void keyboards(unsigned char keys, int x4, int y4)
{
	//start or pause or restart or exit
	if (keys == 'q' || keys == 'Q')
	{
		exit(0);
	}

	if (keys == 's' || keys == 'S')
	{
	  glutIdleFunc(myDisplay);
      sndPlaySound("CARRO2.WAV",SND_ASYNC|SND_LOOP); //display sound
	}
	if (keys == 'p' || keys == 'P')
	{

		glutIdleFunc(NULL);
	}
	if (keys == 'r' || keys == 'R')
	{
		x = 0;
		y1 = 1000;
		y2 = 1500;
		glPushMatrix();

		score = 0;

		//glutPostRedisplay();
		glutIdleFunc(myDisplay);


	}
	if (keys == 'e' || keys == 'E')
	{

		exit1 = 1;

	}
	//move
	if (keys == '4')
		x -= 160;
	if (keys == '6')
		x += 160;
	if (keys == '8')
		y += 50;
	if (keys == '2')
		y -= 50;

	glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          y += 50;
        //  update(0);
          break;
      case GLUT_KEY_DOWN:
          y -= 50;
         // update(0);
          break;
          case GLUT_KEY_RIGHT:
          x += 160;
          //update(0);
          break;
      case GLUT_KEY_LEFT:
          x -= 160;
         // update(0);
          break;


    }

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 600);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("DRIVE & SCORE");
	glClearColor(1, 1, 1, 1);//set Background



   // PlaySound(TEXT("CARRO2.WAV"),NULL,SND_SYNC); // for console sound

	glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboards);
	myInit();
	glutMainLoop();


}
