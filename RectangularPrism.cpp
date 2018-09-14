
#include "RectangularPrism.hpp"

#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

RectangularPrism::RectangularPrism(double x_, double y_, double z_, double xlenth_, double yLenth_, double zLenth_) : Shape(x_, y_, z_) {
	xLenth = xlenth_;
	yLenth = yLenth_;
	zLenth = zLenth_;
}

void RectangularPrism::draw()
{
	glPushMatrix();

	glTranslatef(x, y, z);
	glRotated(rotation, 0, 1, 0);

	glColor3f(red, green, blue);
	glBegin(GL_QUADS);

	glVertex3f(-xLenth / 2, yLenth, -zLenth / 2);
	glVertex3f(xLenth / 2, yLenth, -zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(-xLenth / 2, 0, -zLenth / 2);

	glVertex3f(-zLenth / 2, yLenth, zLenth / 2);
	glVertex3f(-zLenth / 2, yLenth, -zLenth / 2);
	glVertex3f(-zLenth / 2, 0, -zLenth / 2);
	glVertex3f(-zLenth / 2, 0, zLenth / 2);

	glVertex3f(xLenth / 2, yLenth, zLenth / 2);
	glVertex3f(-xLenth / 2, yLenth, zLenth / 2);
	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, zLenth / 2);

	glVertex3f(xLenth / 2, yLenth, -zLenth / 2);
	glVertex3f(xLenth / 2, yLenth, zLenth / 2);
	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);

	glVertex3f(-xLenth / 2, yLenth, zLenth / 2);
	glVertex3f(xLenth / 2, yLenth, zLenth / 2);
	glVertex3f(xLenth / 2, yLenth,- zLenth / 2);
	glVertex3f(-xLenth / 2, yLenth, -zLenth / 2);

	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(-xLenth / 2, 0, -zLenth / 2);

	glEnd();
	glPopMatrix();
};