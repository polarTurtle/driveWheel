#include "TriangularPrism.hpp"

#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h> 

#define PI 3.14159265

TriangularPrism::TriangularPrism(double x_, double y_, double z_, double xlenth_, double zLenth_, double theta_) : Shape(x_, y_, z_) {
	xLenth = xlenth_;
	zLenth = zLenth_;
	theta = theta_*PI;
}

void TriangularPrism::draw()
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

	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(cos(theta)*xLenth - (xLenth / 2), sin(theta)*xLenth, -zLenth / 2);
	glVertex3f(cos(theta)*xLenth - (xLenth / 2), sin(theta)*xLenth, zLenth / 2);

	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(-xLenth / 2, 0, -zLenth / 2);
	glVertex3f(cos(theta)*xLenth - (xLenth / 2), sin(theta)*xLenth, -zLenth / 2);
	glVertex3f(cos(theta)*xLenth - (xLenth / 2), sin(theta)*xLenth, zLenth / 2);

	glVertex3f(cos(theta)*xLenth - (xLenth / 2), sin(theta)*xLenth, -zLenth / 2);
	glVertex3f(xLenth / 2, 0, -zLenth / 2);
	glVertex3f(-xLenth / 2, 0, -zLenth / 2);
	glVertex3f(cos(theta)*xLenth - (xLenth / 2), sin(theta)*xLenth, -zLenth / 2);


	glVertex3f(cos(theta)*xLenth - (xLenth / 2), sin(theta)*xLenth, zLenth / 2);
	glVertex3f(-xLenth / 2, 0, zLenth / 2);
	glVertex3f(xLenth / 2, 0, zLenth / 2);
	glVertex3f(cos(theta)*xLenth - (xLenth / 2), sin(theta)*xLenth, zLenth / 2);

	glEnd();
};