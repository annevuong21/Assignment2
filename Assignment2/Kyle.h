#pragma once
#include "Vehicle.hpp"
#include "Messages.hpp"

class Kyle : public Vehicle {
public:
	Kyle();
	void draw();
	void update(double dt);

protected:
	VehicleModel vm;
	VehicleState vs;
	void initialisation();
};
