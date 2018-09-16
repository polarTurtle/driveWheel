#include "Vehicle.hpp"
#include "Messages.hpp"

class OtherVehicle : public Vehicle {
private:
	VehicleModel vm;
	void drawRectangle(int i);
	void drawTriangle(int i);
	void drawTrapezoid(int i);
	void drawCircle(int i);

public:
	OtherVehicle(VehicleModel vm_);
	void draw();
};