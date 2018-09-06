#pragma once
#include "Vehicle.hpp"
#include "Messages.hpp"

class Car : public Vehicle
{
public:
	Car(); // local model
	Car(VehicleModel vm);

	void Initialization();
	void draw();

protected:
	VehicleState vs;
	VehicleModel vm;
};
