#include "MyVehicle.hpp"
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"

void MyVehicle::draw()
{
	RectangularPrism rectangle = RectangularPrism(x+10, y+10, z+10, 5, 5, 5);
	rectangle.setColor(1, 1, 0);
	rectangle.draw();

	TriangularPrism triangle = TriangularPrism(x-10, y-10, z-10, 5, 5, 0.5);
	triangle.setColor(1, 0, 1);
	triangle.draw();

	TrapezoidalPrism trapezoid = TrapezoidalPrism(x+10, y-10, z+10, 10, 10, 3, 3, 3);
	trapezoid.setColor(0, 1, 1);
	trapezoid.draw();

	Cylinder circle = Cylinder(x+10, y+10, z-10, 5, 10);
	circle.setColor(0.5, 1, 0.5);
	circle.draw();
};
