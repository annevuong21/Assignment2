
#include "Shape.hpp"

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
	Set_length(10.0, 10.0, 10.0);
}

Rectangular::Rectangular(double x_, double y_, double z_, double x_len, double y_len, double z_len) : Shape(x_, y_, z_)
{
	Set_length(x_len, y_len, z_len);
}

double Rectangular::Get_x_length()
{
	return x_length;
}

double Rectangular::Get_y_length()
{
	return y_length;
}

double Rectangular::Get_z_length()
{
	return z_length;
}

void Rectangular::Set_x_length(double x_len)
{
	x_length = x_len;
}

void Rectangular::Set_y_length(double y_len)
{
	y_length = y_len;
}

void Rectangular::Set_z_length(double z_len)
{
	z_length = z_len;
}

void Rectangular::Set_length(double x_len, double y_len, double z_len)
{
	x_length = x_len;
	y_length = y_len;
	z_length = z_len;
}

void Rectangular::draw()
{
	glBegin(GL_QUADS);
	glColor3d(red, green, blue);

	// First plane paralell to YZ plane
	glVertex3d(x + (x_length / 2), y + (y_length / 2), z + (z_length / 2));
	glVertex3d(x + (x_length / 2), y - (y_length / 2), z + (z_length / 2));
	glVertex3d(x + (x_length / 2), y - (y_length / 2), z - (z_length / 2));
	glVertex3d(x + (x_length / 2), y + (y_length / 2), z - (z_length / 2));
	//Second plane paralell to YZ plane
	glVertex3d(x - (x_length / 2), y + (y_length / 2), z + (z_length / 2));
	glVertex3d(x - (x_length / 2), y - (y_length / 2), z + (z_length / 2));
	glVertex3d(x - (x_length / 2), y - (y_length / 2), z - (z_length / 2));
	glVertex3d(x - (x_length / 2), y + (y_length / 2), z - (z_length / 2));

	//First plane paralell to XZ plane
	glVertex3d(x + (x_length / 2), y + (y_length / 2), z + (z_length / 2));
	glVertex3d(x - (x_length / 2), y + (y_length / 2), z + (z_length / 2));
	glVertex3d(x - (x_length / 2), y + (y_length / 2), z - (z_length / 2));
	glVertex3d(x + (x_length / 2), y + (y_length / 2), z - (z_length / 2));
	//Second plane paralell to XZ plane
	glVertex3d(x + (x_length / 2), y - (y_length / 2), z + (z_length / 2));
	glVertex3d(x - (x_length / 2), y - (y_length / 2), z + (z_length / 2));
	glVertex3d(x - (x_length / 2), y - (y_length / 2), z - (z_length / 2));
	glVertex3d(x + (x_length / 2), y - (y_length / 2), z - (z_length / 2));

	// First plane paralell to XY plane
	glVertex3d(x + (x_length / 2), y + (y_length / 2), z + (z_length / 2));
	glVertex3d(x - (x_length / 2), y + (y_length / 2), z + (z_length / 2));
	glVertex3d(x - (x_length / 2), y - (y_length / 2), z + (z_length / 2));
	glVertex3d(x + (x_length / 2), y - (y_length / 2), z + (z_length / 2));
	// Second plane paralell to XY plane
	glVertex3d(x + (x_length / 2), y + (y_length / 2), z - (z_length / 2));
	glVertex3d(x - (x_length / 2), y + (y_length / 2), z - (z_length / 2));
	glVertex3d(x - (x_length / 2), y - (y_length / 2), z - (z_length / 2));
	glVertex3d(x + (x_length / 2), y - (y_length / 2), z - (z_length / 2));

	glEnd();
}