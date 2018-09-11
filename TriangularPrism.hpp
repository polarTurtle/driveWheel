#include "Shape.hpp"

class TriangularPrism : public Shape {

private:
	double xLenth, zLenth, theta;

public:
	TriangularPrism(double x_, double y_, double z_, double xlenth_, double zLenth_, double theta_);
	void draw();
};
