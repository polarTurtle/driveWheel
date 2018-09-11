#include "Shape.hpp"

class TrapezoidalPrism : public Shape {

private:
	double xLenth, yLenth, zLenth, fXLenth, bXLenth;

public:
	TrapezoidalPrism(double x_, double y_, double z_, double xlenth_, double yLenth_, double zLenth_, double fXLenth_, double bXLenth_);
	void draw();
};