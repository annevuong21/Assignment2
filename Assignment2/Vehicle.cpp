
#include "Vehicle.hpp"
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

Vehicle::Vehicle() {
	speed = steering = 0;
};

Vehicle::~Vehicle()
{ 
	// clean-up added shapes
	for(int i = 0; i < shapes.size(); i++) {
		delete shapes[i];
	}
}

void Vehicle::update(double dt)
{
	speed = clamp(MAX_BACKWARD_SPEED_MPS, speed, MAX_FORWARD_SPEED_MPS);
	steering = clamp(MAX_LEFT_STEERING_DEGS, steering, MAX_RIGHT_STEERING_DEGS);

	// update position by integrating the speed
	x += speed * dt * cos(rotation * 3.1415926535 / 180.0);
	z += speed * dt * sin(rotation * 3.1415926535 / 180.0);

	// update heading
	rotation += dt * steering * speed;

	while (rotation > 360) rotation -= 360;
	while (rotation < 0) rotation += 360;


	if(fabs(speed) < .1)
		speed = 0;
	if(fabs(steering) < .1)
		steering = 0;

}

void Vehicle::update(double speed_, double steering_, double dt) 
{
	speed = speed + ((speed_) - speed)*dt*4;
	steering = steering + (steering_ - steering)*dt * 6;

	update(dt);
}

void Vehicle::addShape(Shape * shape) 
{
	shapes.push_back(shape);
}

double clamp(double a, double n, double b) {

	if (a < b) {
		if (n < a) n = a;
		if (n > b) n = b;
	} else {
		if (n < b) n = b;
		if (n > a) n = a;
	}

	return n;

};

Car::Car()
{
	addShape(new Rectangular(60, 20, 50)); //Body
	addShape(new Triangular(20, 20, sqrt(800), 50)); // Front
	addShape(new Triangular(10, 20, sqrt(500), 50, 180)); // Back
	addShape(new Trapezoidal(50, 10, 10, 50));
	addShape(new Cylinder(10, 5)); // Wheel 1
	addShape(new Cylinder(10, 5)); // Wheel 2
	addShape(new Cylinder(10, 5)); // Wheel 3
	addShape(new Cylinder(10, 5)); // Wheel 4

	shapes[0]->setPosition(0, 20, 0);
	shapes[0]->setColor(1, 1, 1);

	shapes[1]->setPosition(40, 10, 0);
	shapes[1]->setColor(0, 1, 0);

	shapes[2]->setPosition(-35, 10, 0);
	shapes[2]->setColor(0, 1, 0);

	shapes[3]->setPosition(0, 35, 0);
	shapes[3]->setColor(0, 0, 1);

	shapes[4]->setPosition(30, 10, 25);
	shapes[4]->setColor(1, 1, 0);

	shapes[5]->setPosition(-30, 10, 25);
	shapes[5]->setColor(1, 0, 1);

	shapes[6]->setPosition(-30, 10, -25);
	shapes[6]->setColor(1, 0, 0);

	shapes[7]->setPosition(30, 10, -25);
	shapes[7]->setColor(0, 0, 1);
}

void Car::draw()
{
	glPushMatrix();
	positionInGL();
	for (int i = 0; i < shapes.size(); i++)
		shapes[i]->draw();
	glPopMatrix();
}