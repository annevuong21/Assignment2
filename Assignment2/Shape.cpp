
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
	Set_length(10.0, 10.0, 10.0);
}

Rectangular::Rectangular(double x_len, double y_len, double z_len)
{
	Set_length(x_len, y_len, z_len);
}

Rectangular::Rectangular(double x_len, double y_len, double z_len, double rotation) {
	Set_length(x_len, y_len, z_len);
	this->rotation = rotation;
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
	// glRotate must be called first and OUTSIDE glBegin()-glEnd()
	glRotated(rotation, 0, 1, 0);

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


// Triangular prism class definition

Triangular::Triangular()
{
	Set_side(10.0, 10.0, 10.0);
}

Triangular::Triangular(double sideA_len, double sideB_len)
{
	sideA = sideA_len;
	sideB = sideB_len;
	Set_angle(60);
}

Triangular::Triangular(double sideA_len, double sideB_len, double sideC_len)
{
	Set_side(sideA_len, sideB_len, sideC_len);
}

Triangular::Triangular(double sideA_len, double sideB_len, double sideC_len, double rotation) {
	Set_side(sideA_len, sideB_len, sideC_len);
	this->rotation = rotation;
}

double Triangular::Get_sideA()
{
	return sideA;
}

double Triangular::Get_sideB()
{
	return sideB;
}

double Triangular::Get_sideC()
{
	return sideC;
}

double Triangular::Get_depth()
{
	return depth;
}

double Triangular::Get_angle()
{
	return angle * 180 / PI;
}

void Triangular::Set_sideA(double sideA_len)
{
	sideA = sideA_len;
	UpdateSideC();
}

void Triangular::Set_sideB(double sideB_len)
{
	sideB = sideB_len;
	UpdateSideC();
}

void Triangular::Set_sideC(double sideC_len)
{
	sideC = sideC_len;
	UpdateAngle();
}

void Triangular::Set_side(double sideA_len, double sideB_len, double sideC_len)
{
	sideA = sideA_len;
	sideB = sideB_len;
	sideC = sideC_len;
	UpdateAngle();
}

void Triangular::Set_depth(double len)
{
	depth = len;
}

void Triangular::Set_angle(double degree)
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
	glRotated(rotation, 0, 1, 0);

	glColor3d(red, green, blue);
	glBegin(GL_QUADS);

	// The plane(base) parallel to XZ plane
	glVertex3d(x - (sideB * cos (angle) - 2 * sideA) / 3, y - sideB * sin(angle) / 3, z + (depth / 2));
	glVertex3d(x - (sideB * cos(angle) + sideA) / 3, y - sideB * sin(angle) / 3, z + (depth / 2));
	glVertex3d(x - (sideB * cos(angle) + sideA) / 3, y - sideB * sin(angle) / 3, z - (depth / 2));
	glVertex3d(x - (sideB * cos(angle) - 2 * sideA) / 3, y - sideB * sin(angle) / 3, z - (depth / 2));

	// The rectangular plane containing sideB
	glVertex3d(x - (sideB * cos(angle) + sideA) / 3, y - sideB * sin(angle) / 3, z + (depth / 2));
	glVertex3d(x - (sideB * cos(angle) + sideA) / 3, y - sideB * sin(angle) / 3, z - (depth / 2));
	glVertex3d(x - (sideA - 2 * sideB * cos(angle)) / 3, y + 2 * sideB * sin(angle) / 3, z - (depth / 2));
	glVertex3d(x - (sideA - 2 * sideB * cos(angle)) / 3, y + 2 * sideB * sin(angle) / 3, z + (depth / 2));

	// The rectangular plane containing sideC
	glVertex3d(x - (sideB * cos(angle) - 2 * sideA) / 3, y - sideB * sin(angle) / 3, z + (depth / 2));
	glVertex3d(x - (sideB * cos(angle) - 2 * sideA) / 3, y - sideB * sin(angle) / 3, z - (depth / 2));
	glVertex3d(x - (sideA - 2 * sideB * cos(angle)) / 3, y + 2 * sideB * sin(angle) / 3, z - (depth / 2));
	glVertex3d(x - (sideA - 2 * sideB * cos(angle)) / 3, y + 2 * sideB * sin(angle) / 3, z + (depth / 2));

	glEnd();

	// Two trangle plane
	glBegin(GL_TRIANGLES);
	glVertex3d(x - (sideB * cos(angle) + sideA) / 3, y - sideB * sin(angle) / 3, z + (depth / 2));
	glVertex3d(x - (sideB * cos(angle) - 2 * sideA) / 3, y - sideB * sin(angle) / 3, z + (depth / 2));
	glVertex3d(x - (sideA - 2 * sideB * cos(angle)) / 3, y + 2 * sideB * sin(angle) / 3, z + (depth / 2));

	glVertex3d(x - (sideB * cos(angle) + sideA) / 3, y - sideB * sin(angle) / 3, z - (depth / 2));
	glVertex3d(x - (sideB * cos(angle) - 2 * sideA) / 3, y - sideB * sin(angle) / 3, z - (depth / 2));
	glVertex3d(x - (sideA - 2 * sideB * cos(angle)) / 3, y + 2 * sideB * sin(angle) / 3, z - (depth / 2));
	glEnd();
}