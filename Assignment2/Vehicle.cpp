
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

void Car::draw() {
	// Car components
	Rectangular Body(60, 20, 50);
	Cylinder Wheel(10, 5);
	Triangular Front(20, 20);
	Triangular Back(10, 20, 25);
	Trapezoidal Top(60, 15, 10);
	glPushMatrix();
	// This functions SHOULD draw everything with respect to the centre of the car
	//Body
	glPushMatrix();
	Body.setColor(0.5, 0.5, 0.5);
	Body.setY(Wheel.getradius());
	glTranslated(0, Body.Get_y_length() / 2, 0);
	Body.draw();
	glPopMatrix();
	//Wheel1
	glPushMatrix();
	Wheel.setColor(1, 1, 0);
	glTranslated(Body.getX() + Body.Get_x_length() / 2, Body.getY(), Body.getZ() + Body.Get_z_length() / 2);
	Wheel.draw();
	glPopMatrix();
	//Wheel2 
	glPushMatrix();
	Wheel.setColor(1, 0, 1);
	glTranslated(Body.getX() - Body.Get_x_length() / 2, Body.getY(), Body.getZ() + Body.Get_z_length() / 2);
	Wheel.draw();
	glPopMatrix();
	//Wheel 3
	glPushMatrix();
	Wheel.setColor(1, 0, 0);
	glTranslated(Body.getX() + Body.Get_x_length() / 2, Body.getY(), Body.getZ() - Body.Get_z_length() / 2);
	Wheel.draw();
	glPopMatrix();
	//Wheel 4
	glPushMatrix();
	Wheel.setColor(1, 1, 1);
	glTranslated(Body.getX() - Body.Get_x_length() / 2, Body.getY(), Body.getZ() - Body.Get_z_length() / 2);
	Wheel.draw();
	glPopMatrix();
	// Front triangle
	glPushMatrix();
	Front.setColor(0, 1, 0);
	glTranslated(Body.getX() + Body.Get_x_length() / 2 + Front.Get_sideA() / 2, Body.getY(), Body.getZ());
	Front.Set_angle(90);
	Front.Set_depth(50);
	Front.draw();
	glPopMatrix();
	// Back triangle
	glPushMatrix();
	Back.setColor(0, 1, 0);
	glRotated(180, 0, 1, 0);
	glRotated(180, 1, 0, 0);
	glTranslated(Body.getX() + Body.Get_x_length() / 2 + Back.Get_sideA() / 2, -Body.getY(), Body.getZ());
	glTranslated(0, -Body.Get_y_length(), 0);
	Back.Set_angle(90);
	Back.Set_depth(50);
	Back.draw();
	glPopMatrix();
	// Cabin
	glPushMatrix();
	Top.setColor(0, 0, 1);
	glTranslated(Body.getX(), Body.getY() + Body.Get_y_length() + Top.Get_height() / 2, Body.getZ());
	Top.Set_depth(50);
	Top.draw();
	glPopMatrix();


	
	
	glPopMatrix();
}