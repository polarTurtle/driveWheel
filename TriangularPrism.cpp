#include "TriangularPrism.hpp"

#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h> 

#define PI 3.14159265

TriangularPrism::TriangularPrism(double x_, double y_, double z_, double xlenth_, double yLenth_, double zLenth_, double theta_) : Shape(x_, y_, z_) {
	xLenth = xlenth_;
	yLenth = yLenth_;
	zLenth = zLenth_;
	theta = theta_*PI;
}

void TriangularPrism::draw()
{
	glPushMatrix();

	glTranslatef(x, y, z);
	glRotated(rotation, 0, 1, 0);

	glColor3f(red, green, blue);
	glBegin(GL_QUADS);

	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(-xLenth / 2, 0, -zLenth / 2);

	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(cos(theta)*yLenth - (xLenth / 2), sin(theta)*yLenth, -zLenth / 2);
	glVertex3f(cos(theta)*yLenth - (xLenth / 2), sin(theta)*yLenth, zLenth / 2);

	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(-xLenth / 2, 0, -zLenth / 2);
	glVertex3f(cos(theta)*yLenth - (xLenth / 2), sin(theta)*yLenth, -zLenth / 2);
	glVertex3f(cos(theta)*yLenth - (xLenth / 2), sin(theta)*yLenth, zLenth / 2);

	glVertex3f(cos(theta)*yLenth - (xLenth / 2), sin(theta)*yLenth, -zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(-xLenth / 2, 0, -zLenth / 2);
	glVertex3f(cos(theta)*yLenth - (xLenth / 2), sin(theta)*yLenth, -zLenth / 2);


	glVertex3f(cos(theta)*yLenth - (xLenth / 2), sin(theta)*yLenth, zLenth / 2);
	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(cos(theta)*yLenth - (xLenth / 2), sin(theta)*yLenth, zLenth / 2);

	glEnd();
	glPopMatrix();
};