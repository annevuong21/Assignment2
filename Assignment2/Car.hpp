#include "Vehicle.hpp"
#include "Messages.hpp"

class Car : public Vehicle
{
public:
	Car(); // local model
	Car(VehicleModel vm);

	void draw();

protected:
	VehicleState vstate;
	ShapeType stype;
	ShapeParameter sparameter;
	ShapeInit sinit;
	VehicleModel vmodel;
};
