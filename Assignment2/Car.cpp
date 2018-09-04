#include "Car.hpp"
#include "Rectangular.hpp"
#include "Triangluar.hpp"
#include "Trapezoidal.hpp"
#include "Cylinder.hpp"

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
	addShape(new Rectangular(6, 2, 5)); //Body
	addShape(new Triangular(2, 2, sqrt(8), 5)); // Front
	addShape(new Triangular(1, 2, sqrt(5), 5, 180)); // Back
	addShape(new Trapezoidal(5, 1, 1, 5));
	addShape(new Cylinder(1, 0.5)); // Wheel 1
	addShape(new Cylinder(1, 0.5)); // Wheel 2
	addShape(new Cylinder(1, 0.5)); // Wheel 3
	addShape(new Cylinder(1, 0.5)); // Wheel 4

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

void Car::draw()
{
	glPushMatrix();
	positionInGL();

	shapes[4]->setRotation(steering);
	shapes[7]->setRotation(steering);

	for (int i = 0; i < shapes.size(); i++)
		shapes[i]->draw();
	glPopMatrix();
}