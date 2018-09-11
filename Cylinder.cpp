#include "Cylinder.hpp"

#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Cylinder::Cylinder(double x_, double y_, double z_, double radius_, double lenth_) : Shape(x_, y_, z_) {
	radius = radius_;
	lenth = lenth_;
}

void Cylinder::draw()
{
	glColor3f(red, green, blue);

	glTranslatef(x, y, z);
	static GLUquadric * quad = gluNewQuadric();
	gluCylinder(quad, radius, radius, lenth, 64, 1);
	//glTranslatef(x, y, z);
	glColor3f(1, 0, 0);
	static GLUquadric * quad2 = gluNewQuadric();
	gluDisk(quad2, 0, radius, 64, 1);

	glTranslatef(-x, -y, -z + lenth);
	glColor3f(0, 0, 1);
	glTranslatef(x, y, z);
	static GLUquadric * quad3 = gluNewQuadric();
	gluDisk(quad3, 0, radius, 64, 1);
}
