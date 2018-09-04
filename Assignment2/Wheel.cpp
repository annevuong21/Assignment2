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
Wheel::Wheel(double radius, double length) {
	this->radius = radius;
	this->length = length;
}
Wheel::Wheel(double radius, double length, double rotation) {
	Wheel(radius, length);
	this->rotation = rotation;
}
void Wheel::draw() {
	glColor3d(red, green, blue);

	glPushMatrix();
	positionInGL();

	// For the curved surface of the cylinder the idea is to draw 2 half cylinders either side of the origin.
	glPushMatrix();
	gluCylinder(gluNewQuadric(), radius, radius, length / 2, 25, 25);
	glRotated(180, 0, 1, 0);
	gluCylinder(gluNewQuadric(), radius, radius, length / 2, 25, 25);
	glPopMatrix();

	// This draws an inner cylinder so the wheels are not missing bits
	glPushMatrix();
	gluCylinder(gluNewQuadric(), radius / 1.5, radius / 1.5, length / 2, 25, 25);
	glRotated(180, 0, 1, 0);
	gluCylinder(gluNewQuadric(), radius / 1.5, radius / 1.5, length / 2, 25, 25);
	glPopMatrix();

	// WHEEL SPOKE CODE HERE
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), radius / 12, radius / 10, radius, 25, 25);
	glRotated(180, 0, 1, 0);
	gluCylinder(gluNewQuadric(), radius / 12, radius / 10, radius, 25, 25);
	glRotated(90, 0, 1, 0);
	gluCylinder(gluNewQuadric(), radius / 12, radius / 10, radius, 25, 25);
	glRotated(180, 0, 1, 0);
	gluCylinder(gluNewQuadric(), radius / 12, radius / 10, radius, 25, 25);
	glPopMatrix();

	// Draw a disc-
	glPushMatrix();
	glColor3d(1, 1, 1);
	glTranslated(0, 0, length / 2);
	gluDisk(gluNewQuadric(), radius / 1.5, radius, 25, 25);
	glTranslated(0, 0, -length);
	gluDisk(gluNewQuadric(), radius / 1.5, radius, 25, 25);
	glPopMatrix();

	glPopMatrix();
}