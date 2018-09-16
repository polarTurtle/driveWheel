#include "OtherVehicle.hpp"
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"
#include <math.h> 

#define PI 3.14159265

#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void OtherVehicle::drawRectangle(int i)
{
	RectangularPrism rectangle = RectangularPrism(vm.shapes[i].xyz[0], vm.shapes[i].xyz[1], vm.shapes[i].xyz[2], vm.shapes[i].params.rect.xlen, vm.shapes[i].params.rect.ylen, vm.shapes[i].params.rect.zlen);
	rectangle.setColor(vm.shapes[i].rgb[0], vm.shapes[i].rgb[1], vm.shapes[i].rgb[2]);
	rectangle.setRotation(vm.shapes[i].rotation);
	rectangle.draw();
}

void OtherVehicle::drawTriangle(int i)
{
	TriangularPrism triangle = TriangularPrism(vm.shapes[i].xyz[0], vm.shapes[i].xyz[1], vm.shapes[i].xyz[2], vm.shapes[i].params.tri.alen, vm.shapes[i].params.tri.blen, vm.shapes[i].params.tri.depth, vm.shapes[i].params.tri.angle);
	triangle.setColor(vm.shapes[i].rgb[0], vm.shapes[i].rgb[1], vm.shapes[i].rgb[2]);
	triangle.setRotation(vm.shapes[i].rotation);
	triangle.draw();
}

void OtherVehicle::drawTrapezoid(int i)
{
	TrapezoidalPrism trapezoid = TrapezoidalPrism(vm.shapes[i].xyz[0], vm.shapes[i].xyz[1], vm.shapes[i].xyz[2], vm.shapes[i].params.trap.alen, vm.shapes[i].params.trap.height, vm.shapes[i].params.trap.depth, vm.shapes[i].params.trap.alen - vm.shapes[i].params.trap.aoff - vm.shapes[i].params.trap.blen, vm.shapes[i].params.trap.aoff);
	trapezoid.setColor(vm.shapes[i].rgb[0], vm.shapes[i].rgb[1], vm.shapes[i].rgb[2]);
	trapezoid.setRotation(vm.shapes[i].rotation);
	trapezoid.draw();
}

void OtherVehicle::drawCircle(int i)
{
	Cylinder circle = Cylinder(vm.shapes[i].xyz[0], vm.shapes[i].xyz[1], vm.shapes[i].xyz[2] - (vm.shapes[i].params.cyl.depth/2), vm.shapes[i].params.cyl.radius, vm.shapes[i].params.cyl.depth);
	circle.setColor(vm.shapes[i].rgb[0], vm.shapes[i].rgb[1], vm.shapes[i].rgb[2]);
	circle.setRotation(vm.shapes[i].rotation);
	circle.draw();
}


OtherVehicle::OtherVehicle(VehicleModel vm_)
{
	vm = vm_;
}

void OtherVehicle::draw()
{
	glPushMatrix();

	glTranslatef(x, y, z);
	glRotated(-rotation, 0, 1, 0);

	for (int i = 0; i < vm.shapes.size(); i++) {
		switch (vm.shapes[i].type) {
		case RECTANGULAR_PRISM:
			drawRectangle(i);
			break;
		case TRIANGULAR_PRISM:
			drawTriangle(i);
			break;
		case TRAPEZOIDAL_PRISM:
			drawTrapezoid(i);
			break;
		case CYLINDER:
			drawCircle(i);
			break;
		}
	}


	glPopMatrix();
}

