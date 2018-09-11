#include "TrapezoidalPrism.hpp"

#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

TrapezoidalPrism::TrapezoidalPrism(double x_, double y_, double z_, double xlenth_, double yLenth_, double zLenth_, double fXLenth_, double bXLenth_) : Shape(x_, y_, z_) {
	xLenth = xlenth_;
	yLenth = yLenth_;
	zLenth = zLenth_;
	fXLenth = fXLenth_;
	bXLenth = bXLenth_;
}

void TrapezoidalPrism::draw()
{
	//glPolygonMode(GL_FRONT, GL_LINE); // draw wireframe polygons
	glColor3f(red, green, blue); // set color green
	//glCullFace(GL_BACK); // don't draw back faces
	//glEnable(GL_CULL_FACE); // don't draw back faces
	//glTranslatef(-10, 1, 0); // position
	glTranslatef(x, y, z);
	glBegin(GL_QUADS);

	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(-xLenth / 2, 0, -zLenth / 2);

	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(fXLenth / 2, yLenth, zLenth / 2);
	glVertex3f(-bXLenth / 2, yLenth, zLenth / 2);

	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(fXLenth / 2, yLenth, -zLenth / 2);
	glVertex3f(fXLenth / 2, yLenth, zLenth / 2);

	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(-xLenth / 2, 0, -zLenth / 2);
	glVertex3f(-bXLenth / 2, yLenth, -zLenth / 2);
	glVertex3f(fXLenth / 2, yLenth, -zLenth / 2);

	glVertex3f(-xLenth / 2, 0, -zLenth / 2);
	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(-bXLenth / 2, yLenth, zLenth / 2);
	glVertex3f(-bXLenth / 2, yLenth, -zLenth / 2);

	glVertex3f(-bXLenth / 2, yLenth, zLenth / 2);
	glVertex3f(fXLenth / 2, yLenth, zLenth / 2);
	glVertex3f(fXLenth / 2, yLenth, -zLenth / 2);
	glVertex3f(-bXLenth / 2, yLenth, -zLenth / 2);

	glEnd();
}
