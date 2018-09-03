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