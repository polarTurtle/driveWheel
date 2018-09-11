#include "Shape.hpp"

class Cylinder : public Shape {

private:
	double radius, lenth;

public:
	Cylinder(double x_, double y_, double z_, double radius_, double lenth_);
	void draw();
};
