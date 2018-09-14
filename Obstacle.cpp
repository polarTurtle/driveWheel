
#include "Obstacle.hpp"
#include <cmath>

#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Obstacle::Obstacle(double x_, double z_, double radius_)
	: Shape(x_, 0, z_) {
		blue = .5;
		green = .5;

		radius = radius_;
};

void Obstacle::draw() {
	// student section
	static GLUquadric * myQuadric = gluNewQuadric();
	glPushMatrix();
	positionInGL();
	//void DrawAxis();
	//DrawAxis();
	setColorInGL();
	glRotatef(-90, 1, 0, 0);
	glScalef(radius, radius, radius);	
	gluCylinder(myQuadric, 1, 0, 1, 5, 1);
	glPopMatrix();
};

bool Obstacle::equals(Obstacle & other) {

	double threshold = 0.001;

	return 
		(fabs(other.getX() - x) < threshold) &&
		(fabs(other.getZ() - z) < threshold);

};

double Obstacle::getRadius() {
	return radius;
}
