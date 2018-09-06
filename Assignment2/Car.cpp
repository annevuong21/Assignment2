#include "Car.hpp"
#include "Rectangular.hpp"
#include "Triangluar.hpp"
#include "Trapezoidal.hpp"
#include "Cylinder.hpp"
#include "Wheel.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

Car::Car()
{
	// Default model
	vm.remoteID = 0;
	/**/
	// Rectangular Prism (Body)
	ShapeInit body;
	body.type = RECTANGULAR_PRISM;
	body.params.rect.xlen = 6;
	body.params.rect.ylen = 2;
	body.params.rect.zlen = 5;
	body.rotation = 0;
	body.xyz[0] = 0;
	body.xyz[1] = 2;
	body.xyz[2] = 0;
	body.rgb[0] = 1;
	body.rgb[1] = 1;
	body.rgb[2] = 1;
	vm.shapes.push_back(body);

	// Triangular Prism (Front)
	ShapeInit front;
	front.type = TRIANGULAR_PRISM;
	front.params.tri.alen = 2;
	front.params.tri.angle = 90;
	front.params.tri.blen = 2;
	front.params.tri.depth = 5;
	front.rotation = 0;
	front.xyz[0] = 4;
	front.xyz[1] = 1;
	front.xyz[2] = 0;
	front.rgb[0] = 0;
	front.rgb[1] = 1;
	front.rgb[2] = 0;
	vm.shapes.push_back(front);

	// Triangular Prism (Back)
	ShapeInit back;
	back.type = TRIANGULAR_PRISM;
	back.params.tri.alen = 1;
	back.params.tri.angle = 90;
	back.params.tri.blen = 2;
	back.params.tri.depth = 5;
	back.rotation = 180;
	back.xyz[0] = -3.5;
	back.xyz[1] = 1;
	back.xyz[2] = 0;
	back.rgb[0] = 0;
	back.rgb[1] = 1;
	back.rgb[2] = 0;
	vm.shapes.push_back(back);

	// Trapezodial (Cabin)
	ShapeInit cabin;
	cabin.type = TRAPEZOIDAL_PRISM;
	cabin.params.trap.alen = 5;
	cabin.params.trap.blen = 3;
	cabin.params.trap.aoff = 1;
	cabin.params.trap.depth = 5;
	cabin.params.trap.height = 1;
	cabin.rotation = 0;
	cabin.xyz[0] = 0;
	cabin.xyz[1] = 3.5;
	cabin.xyz[2] = 0;
	cabin.rgb[0] = 0;
	cabin.rgb[1] = 0;
	cabin.rgb[2] = 1;
	vm.shapes.push_back(cabin);

	// Wheel 1 (Front Right)
	ShapeInit wheel1;
	wheel1.type = CYLINDER;
	wheel1.params.cyl.radius = 1;
	wheel1.params.cyl.depth = 0.5;
	wheel1.params.cyl.isRolling = true;
	wheel1.params.cyl.isSteering = true;
	wheel1.rotation = 0;
	wheel1.xyz[0] = 3;
	wheel1.xyz[1] = 1;
	wheel1.xyz[2] = 2.5;
	wheel1.rgb[0] = 1;
	wheel1.rgb[1] = 1;
	wheel1.rgb[2] = 0;
	vm.shapes.push_back(wheel1);

	// Wheel 2 (Back Right)
	ShapeInit wheel2;
	wheel2.type = CYLINDER;
	wheel2.params.cyl.radius = 1;
	wheel2.params.cyl.depth = 0.5;
	wheel2.params.cyl.isRolling = true;
	wheel2.params.cyl.isSteering = false;
	wheel2.rotation = 0;
	wheel2.xyz[0] = -3;
	wheel2.xyz[1] = 1;
	wheel2.xyz[2] = 2.5;
	wheel2.rgb[0] = 1;
	wheel2.rgb[1] = 0;
	wheel2.rgb[2] = 1;
	vm.shapes.push_back(wheel2);

	// Wheel 3 (Back Left)
	ShapeInit wheel3;
	wheel3.type = CYLINDER;
	wheel3.params.cyl.radius = 1;
	wheel3.params.cyl.depth = 0.5;
	wheel3.params.cyl.isRolling = true;
	wheel3.params.cyl.isSteering = false;
	wheel3.rotation = 0;
	wheel3.xyz[0] = -3;
	wheel3.xyz[1] = 1;
	wheel3.xyz[2] = -2.5;
	wheel3.rgb[0] = 1;
	wheel3.rgb[1] = 0;
	wheel3.rgb[2] = 0;
	vm.shapes.push_back(wheel3);

	// Wheel 4 (Front Left)
	ShapeInit wheel4;
	wheel4.type = CYLINDER;
	wheel4.params.cyl.radius = 1;
	wheel4.params.cyl.depth = 0.5;
	wheel4.params.cyl.isRolling = true;
	wheel4.params.cyl.isSteering = true;
	wheel4.rotation = 0;
	wheel4.xyz[0] = 3;
	wheel4.xyz[1] = 1;
	wheel4.xyz[2] = -2.5;
	wheel4.rgb[0] = 0;
	wheel4.rgb[1] = 0;
	wheel4.rgb[2] = 1;
	vm.shapes.push_back(wheel4);

	Initialization();
	//////////////////////  old  way   ////////////////////////////
	/*
	addShape(new Rectangular(6, 2, 5)); //Body
	addShape(new Triangular(2, 2, sqrt(8), 5)); // Front
	addShape(new Triangular(1, 2, sqrt(5), 5, 180)); // Back
	addShape(new Trapezoidal(5, 1, 1, 5));
	addShape(new Wheel(1, 0.5)); // Wheel 1
	addShape(new Wheel(1, 0.5)); // Wheel 2
	addShape(new Wheel(1, 0.5)); // Wheel 3
	addShape(new Wheel(1, 0.5)); // Wheel 4
	
	shapes[0]->setPosition(0, 2, 0);
	shapes[0]->setColor(1, 1, 1);

	shapes[1]->setPosition(4, 1, 0);
	shapes[1]->setColor(0, 1, 0);

	shapes[2]->setPosition(-3.5, 1, 0);
	shapes[2]->setColor(0, 1, 0);

	shapes[3]->setPosition(0, 3.5, 0); 
	shapes[3]->setColor(0, 0, 1);

	shapes[4]->setPosition(3, 1, 2.5); // Front Right Wheel
	shapes[4]->setColor(1, 1, 0);

	shapes[5]->setPosition(-3, 1, 2.5); // Back Right Wheel
	shapes[5]->setColor(1, 0, 1);

	shapes[6]->setPosition(-3, 1, -2.5); // Back Left Wheel
	shapes[6]->setColor(1, 0, 0);

	shapes[7]->setPosition(3, 1, -2.5); // Front Left Wheel
	shapes[7]->setColor(0, 0, 1); 
	*/
}

Car::Car(VehicleModel vm)
{
	this->vm = vm;
	Initialization();
}

VehicleModel Car::GetVehicleModel()
{
	return vm;
}

VehicleState Car::GetVehicleState()
{
	return vs;
}

void Car::Initialization()
{
	// Vehicle Model Initialization
	for (int i = 0; i < vm.shapes.size(); i++)
	{
		switch (vm.shapes[i].type)
		{
		case RECTANGULAR_PRISM:
		{
			double x_len = vm.shapes[i].params.rect.xlen;
			double y_len = vm.shapes[i].params.rect.ylen;
			double z_len = vm.shapes[i].params.rect.zlen;
			Rectangular* rect = new Rectangular(x_len, y_len, z_len, vm.shapes[i].rotation);
			rect->setPosition(vm.shapes[i].xyz[0], vm.shapes[i].xyz[1], vm.shapes[i].xyz[2]);
			rect->setColor(vm.shapes[i].rgb[0], vm.shapes[i].rgb[1], vm.shapes[i].rgb[2]);
			addShape(rect);
			break;
		}
		case TRIANGULAR_PRISM:
		{
			double a_len = vm.shapes[i].params.tri.alen;
			double b_len = vm.shapes[i].params.tri.blen;
			double angle = vm.shapes[i].params.tri.angle;
			Triangular* tri = new Triangular(a_len, b_len);
			tri->Setangle(angle);
			tri->Setdepth(vm.shapes[i].params.tri.depth);
			tri->setPosition(vm.shapes[i].xyz[0], vm.shapes[i].xyz[1], vm.shapes[i].xyz[2]);
			tri->setColor(vm.shapes[i].rgb[0], vm.shapes[i].rgb[1], vm.shapes[i].rgb[2]);
			tri->setRotation(vm.shapes[i].rotation);
			addShape(tri);
			break;
		}
		case TRAPEZOIDAL_PRISM:
		{
			double a_len = vm.shapes[i].params.trap.alen;
			double offset = vm.shapes[i].params.trap.aoff;
			double height = vm.shapes[i].params.trap.height;
			double depth = vm.shapes[i].params.trap.depth;
			Trapezoidal* trap = new Trapezoidal(a_len, offset, height, depth, vm.shapes[i].rotation);
			trap->setPosition(vm.shapes[i].xyz[0], vm.shapes[i].xyz[1], vm.shapes[i].xyz[2]);
			trap->setColor(vm.shapes[i].rgb[0], vm.shapes[i].rgb[1], vm.shapes[i].rgb[2]);
			addShape(trap);
			break;
		}
		case CYLINDER:
		{
			double radius = vm.shapes[i].params.cyl.radius;
			double depth = vm.shapes[i].params.cyl.depth;
			if (vm.shapes[i].params.cyl.isRolling == true)
			{
				Wheel* wheel = new Wheel(radius, depth, vm.shapes[i].rotation);
				wheel->setPosition(vm.shapes[i].xyz[0], vm.shapes[i].xyz[1], vm.shapes[i].xyz[2]);
				wheel->setColor(vm.shapes[i].rgb[0], vm.shapes[i].rgb[1], vm.shapes[i].rgb[2]);
				addShape(wheel);
			}
			else
			{
				Cylinder* cyl = new Cylinder(radius, depth, vm.shapes[i].rotation);
				cyl->setPosition(vm.shapes[i].xyz[0], vm.shapes[i].xyz[1], vm.shapes[i].xyz[2]);
				cyl->setColor(vm.shapes[i].rgb[0], vm.shapes[i].rgb[1], vm.shapes[i].rgb[2]);
				addShape(cyl);
			}
			break;
		}
		default:
		{break; }
		}
	}
 }

void Car::draw()
{
	glPushMatrix();
	positionInGL();
	if (vm.remoteID == 0)
	{
		shapes[4]->setRotation(steering);
		shapes[7]->setRotation(steering);

	}
	else
	{
		//if ()
		{

		}
	}

	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->draw();
	}
	glPopMatrix();
}