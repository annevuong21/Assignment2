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
	
}

Car::Car(VehicleModel vm)
{
	this->vm = vm;
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