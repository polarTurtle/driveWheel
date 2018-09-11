


#include "Shape.hpp"

class RectangularPrism : public Shape {

private:
	double xLenth, yLenth, zLenth;

public:
	RectangularPrism(double x_, double y_, double z_, double xlenth_, double yLenth_, double zLenth_);
	void draw();
};
