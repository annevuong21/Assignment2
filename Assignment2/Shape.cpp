
#include "Shape.hpp"
#include <math.h>

#define PI 3.14159265358979323846;

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


Shape::Shape() {
	x = y = z = 0.0;
	rotation = 0.0;
	red = green = blue = 1.0;
};

Shape::Shape(double x_, double y_, double z_) {
	x = x_;
	y = y_;
	z = z_;

	rotation = 0.0;
	red = green = blue = 1.0;
};

Shape::Shape(double x_, double y_, double z_, double rotation_) {

	x = x_;
	y = y_;
	z = z_;

	rotation = rotation_;
	red = green = blue = 1.0;
};

Shape::~Shape() {
}

double Shape::getX() {
	return x;
};

double Shape::getY() {
	return y;
};

double Shape::getZ() {
	return z;
};

double Shape::getRotation() {
	return rotation;
};

void Shape::setX(double x_) {
	x = x_;
};

void Shape::setY(double y_) {
	y = y_;
};

void Shape::setZ(double z_) {
	z = z_;
};

void Shape::setRotation(double rotation_) {
	rotation = rotation_;
};


void Shape::setPosition(double x_, double y_, double z_) {
	x = x_;
	y = y_;
	z = z_;
};

void Shape::positionInGL() {
	glTranslated(x, y, z);
	glRotated(-rotation, 0, 1, 0);
};

void Shape::setColorInGL() {
	glColor3f(red, green, blue);
};

double Shape::getRed() {
	return red;
};

double Shape::getGreen() {
	return green;
};

double Shape::getBlue() {
	return blue;
};

void Shape::setColor(float red_, float green_, float blue_) {
	red = red_;
	green = green_;
	blue = blue_;
};

// Rectangular prism class definition

Rectangular::Rectangular()
{
	Setlength(10.0, 10.0, 10.0);
}

Rectangular::Rectangular(double x_len, double y_len, double z_len)
{
	Setlength(x_len, y_len, z_len);
}

Rectangular::Rectangular(double x_len, double y_len, double z_len, double rotation) {
	Setlength(x_len, y_len, z_len);
	this->rotation = rotation;
}

double Rectangular::Getx_length()
{
	return x_length;
}

double Rectangular::Gety_length()
{
	return y_length;
}

double Rectangular::Getz_length()
{
	return z_length;
}

void Rectangular::Setx_length(double x_len)
{
	x_length = x_len;
}

void Rectangular::Sety_length(double y_len)
{
	y_length = y_len;
}

void Rectangular::Setz_length(double z_len)
{
	z_length = z_len;
}

void Rectangular::Setlength(double x_len, double y_len, double z_len)
{
	x_length = x_len;
	y_length = y_len;
	z_length = z_len;
}

void Rectangular::draw()
{
	glColor3d(red, green, blue);
	glPushMatrix();
	glTranslated(x, y, z);
	glRotated(rotation, 0, 1, 0);
	glBegin(GL_QUADS);

	// First plane paralell to YZ plane
	glVertex3d(x_length / 2, y_length / 2, z_length / 2);
	glVertex3d(x_length / 2, -y_length / 2, z_length / 2);
	glVertex3d(x_length / 2, -y_length / 2, -z_length / 2);
	glVertex3d(x_length / 2, y_length / 2, -z_length / 2);
	//Second plane paralell to YZ plane
	glVertex3d(-x_length / 2, y_length / 2, z_length / 2);
	glVertex3d(-x_length / 2, -y_length / 2, z_length / 2);
	glVertex3d(-x_length / 2, -y_length / 2, -z_length / 2);
	glVertex3d(-x_length / 2, y_length / 2, -z_length / 2);

	//First plane paralell to XZ plane
	glVertex3d(x_length / 2, y_length / 2, z_length / 2);
	glVertex3d(-x_length / 2, y_length / 2, z_length / 2);
	glVertex3d(-x_length / 2, y_length / 2, -z_length / 2);
	glVertex3d(x_length / 2, y_length / 2, -z_length / 2);
	//Second plane paralell to XZ plane
	glVertex3d(x_length / 2, -y_length / 2, z_length / 2);
	glVertex3d(-x_length / 2, -y_length / 2, z_length / 2);
	glVertex3d(-x_length / 2, -y_length / 2, -z_length / 2);
	glVertex3d(x_length / 2, -y_length / 2, -z_length / 2);

	// First plane paralell to XY plane
	glVertex3d(x_length / 2, y_length / 2, z_length / 2);
	glVertex3d(-x_length / 2, y_length / 2, z_length / 2);
	glVertex3d(-x_length / 2, -y_length / 2, z_length / 2);
	glVertex3d(x_length / 2, -y_length / 2, z_length / 2);
	// Second plane paralell to XY plane
	glVertex3d(x_length / 2, y_length / 2, -z_length / 2);
	glVertex3d(-x_length / 2, y_length / 2, -z_length / 2);
	glVertex3d(-x_length / 2, -y_length / 2, -z_length / 2);
	glVertex3d(x_length / 2, -y_length / 2, -z_length / 2);

	glEnd();
	glPopMatrix();
}


// Triangular prism class definition

Triangular::Triangular()
{
	Setside(10.0, 10.0, 10.0);
}

Triangular::Triangular(double sideA_len, double sideB_len)
{
	sideA = sideA_len;
	sideB = sideB_len;
	Setangle(60);
}

Triangular::Triangular(double sideA_len, double sideB_len, double sideC_len)
{
	Setside(sideA_len, sideB_len, sideC_len);
}

Triangular::Triangular(double sideA_len, double sideB_len, double sideC_len, double depth) 
{
	Setside(sideA_len, sideB_len, sideC_len);
	this->depth = depth;
}

Triangular::Triangular(double sideA_len, double sideB_len, double sideC_len, double depth, double rotation)
{
	Setside(sideA_len, sideB_len, sideC_len);
	this->depth = depth;
	this->rotation = rotation;
}
double Triangular::GetsideA()
{
	return sideA;
}

double Triangular::GetsideB()
{
	return sideB;
}

double Triangular::GetsideC()
{
	return sideC;
}

double Triangular::Getdepth()
{
	return depth;
}

double Triangular::Getangle()
{
	return angle * 180 / PI;
}

void Triangular::SetsideA(double sideA_len)
{
	sideA = sideA_len;
	UpdateSideC();
}

void Triangular::SetsideB(double sideB_len)
{
	sideB = sideB_len;
	UpdateSideC();
}

void Triangular::SetsideC(double sideC_len)
{
	sideC = sideC_len;
	UpdateAngle();
}

void Triangular::Setside(double sideA_len, double sideB_len, double sideC_len)
{
	sideA = sideA_len;
	sideB = sideB_len;
	sideC = sideC_len;
	UpdateAngle();
}

void Triangular::Setdepth(double len)
{
	depth = len;
}

void Triangular::Setangle(double degree)
{
	angle = degree / 180 * PI;
	UpdateSideC();
}

void Triangular::UpdateAngle()
{
	double ratio = (pow(sideA, 2) + pow(sideB, 2) - pow(sideC, 2)) / (2 * sideA * sideB);
	angle = acos(ratio);
}

void Triangular::UpdateSideC()
{
	sideC = sqrt(pow(sideA, 2) + pow(sideB, 2) - 2 * sideA * sideB * cos(angle));
}

void Triangular::draw()
{
	glPushMatrix();
	glTranslated(x, y, z);
	glRotated(rotation, 0, 1, 0);
	glColor3d(red, green, blue);

	glBegin(GL_QUADS);
	// The plane(base) parallel to XZ plane
	glVertex3d( - (sideB * cos (angle) - 2 * sideA) / 3,  - sideB * sin(angle) / 3, (depth / 2));
	glVertex3d( - (sideB * cos(angle) + sideA) / 3,  - sideB * sin(angle) / 3, (depth / 2));
	glVertex3d( - (sideB * cos(angle) + sideA) / 3,  - sideB * sin(angle) / 3, - (depth / 2));
	glVertex3d( - (sideB * cos(angle) - 2 * sideA) / 3,  - sideB * sin(angle) / 3, - (depth / 2));
	
	// The rectangular plane containing sideB
	glVertex3d( - (sideB * cos(angle) + sideA) / 3, - sideB * sin(angle) / 3, - (depth / 2));
	glVertex3d( - (sideB * cos(angle) + sideA) / 3, - sideB * sin(angle) / 3, (depth / 2));
	glVertex3d( - (sideA - 2 * sideB * cos(angle)) / 3, 2 * sideB * sin(angle) / 3,  (depth / 2));
	glVertex3d( - (sideA - 2 * sideB * cos(angle)) / 3, 2 * sideB * sin(angle) / 3, - (depth / 2));

	// The rectangular plane containing sideC
	glVertex3d( - (sideB * cos(angle) - 2 * sideA) / 3, - sideB * sin(angle) / 3, (depth / 2));
	glVertex3d( - (sideB * cos(angle) - 2 * sideA) / 3, - sideB * sin(angle) / 3, - (depth / 2));
	glVertex3d( - (sideA - 2 * sideB * cos(angle)) / 3, 2 * sideB * sin(angle) / 3, - (depth / 2));
	glVertex3d( - (sideA - 2 * sideB * cos(angle)) / 3, 2 * sideB * sin(angle) / 3, (depth / 2));

	glEnd();

	// Two trangle plane
	glBegin(GL_TRIANGLES);
	glVertex3d( - (sideB * cos(angle) + sideA) / 3, - sideB * sin(angle) / 3, (depth / 2));
	glVertex3d( - (sideB * cos(angle) - 2 * sideA) / 3, - sideB * sin(angle) / 3, (depth / 2));
	glVertex3d( - (sideA - 2 * sideB * cos(angle)) / 3, 2 * sideB * sin(angle) / 3, (depth / 2));

	glVertex3d( - (sideB * cos(angle) + sideA) / 3, - sideB * sin(angle) / 3, - (depth / 2));
	glVertex3d( - (sideB * cos(angle) - 2 * sideA) / 3, - sideB * sin(angle) / 3, - (depth / 2));
	glVertex3d( - (sideA - 2 * sideB * cos(angle)) / 3, 2 * sideB * sin(angle) / 3, - (depth / 2));
	
	glEnd();
	glPopMatrix();
}


// Trapezoidal Prism class definition

Trapezoidal::Trapezoidal()
{
	longside = 10;
	offset = 2.5;
	height = 10;
	depth = 10;
}

Trapezoidal::Trapezoidal(double longside, double offset, double height)
{
	SetTrapezium(longside, offset, height);
}

Trapezoidal::Trapezoidal(double longside, double offset, double height, double depth)
{
	SetTrapezium(longside, offset, height);
	this->depth = depth;
}

Trapezoidal::Trapezoidal(double longside, double offset, double height, double depth, double rotation)
{
	SetTrapezium(longside, offset, height);
	this->depth = depth;
	this->rotation = rotation;
}

double Trapezoidal::Getlong()
{
	return longside;
}

double Trapezoidal::Getoffset()
{
	return offset;
}

double Trapezoidal::Getheight()
{
	return height;
}

double Trapezoidal::Getdepth()
{
	return depth;
}

void Trapezoidal::Setlong(double longside)
{
	this->longside = longside;
}

void Trapezoidal::Setoffset(double offset)
{
	this->offset = offset;
}

void Trapezoidal::Setheight(double height)
{
	this->height = height;
}

void Trapezoidal::Setdepth(double depth)
{
	this->depth = depth;
}

void Trapezoidal::SetTrapezium(double longside, double offset, double height)
{
	this->longside = longside;
	this->offset = offset;
	this->height = height;
}

void Trapezoidal::draw()
{
	glColor3d(red, green, blue);
	glPushMatrix();
	glTranslated(x, y, z);
	glRotated(rotation, 0, 1, 0);
	glBegin(GL_QUADS);

	// Base
	glVertex3d(longside / 2, -height / 2, depth / 2);
	glVertex3d(longside / 2, -height / 2, -depth / 2);
	glVertex3d(-longside / 2, -height / 2, -depth / 2);
	glVertex3d(-longside / 2, -height / 2, depth / 2);
	// Top
	glVertex3d((longside - 2 * offset) / 2, height / 2, depth / 2);
	glVertex3d((longside - 2 * offset) / 2, height / 2, -depth / 2);
	glVertex3d(-(longside - 2 * offset) / 2, height / 2, -depth / 2);
	glVertex3d(-(longside - 2 * offset) / 2, height / 2, depth / 2);

	// First inclined plane
	glVertex3d(longside / 2, -height / 2, depth / 2);
	glVertex3d(longside / 2, -height / 2, -depth / 2);
	glVertex3d((longside - 2 * offset) / 2, height / 2, -depth / 2);
	glVertex3d((longside - 2 * offset) / 2, height / 2, depth / 2);
	// Second inclined plane
	glVertex3d(longside / 2, -height / 2, depth / 2);
	glVertex3d(-longside / 2, -height / 2, -depth / 2);
	glVertex3d(-(longside - 2 * offset) / 2, height / 2, -depth / 2);
	glVertex3d(-(longside - 2 * offset) / 2, height / 2, depth / 2);

	// First trapezium
	glVertex3d(longside / 2, -height / 2, depth / 2);
	glVertex3d(-longside / 2, -height / 2, depth / 2);
	glVertex3d(-(longside - 2 * offset) / 2, height / 2, depth / 2);
	glVertex3d((longside - 2 * offset) / 2, height / 2, depth / 2);
	// Second trapezium
	glVertex3d(longside / 2, -height / 2, -depth / 2);
	glVertex3d(-longside / 2, -height / 2, -depth / 2);
	glVertex3d(-(longside - 2 * offset) / 2, height / 2, -depth / 2);
	glVertex3d((longside - 2 * offset) / 2, height / 2, -depth / 2);

	glEnd();
	glPopMatrix();
}


// Culinder prism class definition

Cylinder::Cylinder() {
	this->radius = 10;
	this->length = 10;
}
Cylinder::Cylinder(double radius, double length) {
	this->radius = radius;
	this->length = length;
}
Cylinder::Cylinder(double radius, double length, double rotation) {
	this->radius = radius;
	this->length = length;
	this->rotation = rotation;
}
double Cylinder::Getradius() {
	return radius;
}
double Cylinder::Getlength() {
	return length;
}
void Cylinder::Setradius(double size) {
	this->radius = size;
}
void Cylinder::Setlength(double size) {
	this->length = size;
}
// Currently sets a cylinder with base at z = 0;
void Cylinder::draw() {
	glColor3d(red, green, blue);

	glPushMatrix();
	glTranslated(x, y, z);

	// For the curved surface of the cylinder the idea is to draw 2 half cylinders either side of the origin.
	glPushMatrix();
	glRotated(rotation, 0, 1, 0);
	gluCylinder(gluNewQuadric(), radius, radius, length / 2, 100, 100);
	glRotated(180, 0, 1, 0);
	gluCylinder(gluNewQuadric(), radius, radius, length / 2, 100, 100);
	glPopMatrix();

	// Draw a disc-
	glColor3d(red, green, blue);
	glPushMatrix();
	glRotated(rotation, 0, 1, 0);
	glTranslated(0, 0, length / 2);
	gluDisk(gluNewQuadric(), 0, radius, 100, 100);
	glTranslated(0, 0, -length);
	gluDisk(gluNewQuadric(), 0, radius, 100, 100);
	glPopMatrix();

	glPopMatrix();
}