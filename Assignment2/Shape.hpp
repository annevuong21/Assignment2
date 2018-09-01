
#ifndef MTRN3500_SHAPE_H
#define MTRN3500_SHAPE_H

// Abstract class
class Shape {

public:
	Shape();
	Shape(double x_, double y_, double z_);
	Shape(double x_, double y_, double z_, double rotation_);
	virtual ~Shape();

	virtual void draw() = 0;

	double getX();
	double getY();
	double getZ();
	double getRotation();

	void setX(double x_);
	void setY(double y_);
	void setZ(double z_);
	void setRotation(double rotation_);

	void setPosition(double x_, double y_, double z_);

	void positionInGL();
	void setColorInGL();

	double getRed();
	double getGreen();
	double getBlue();
	void setColor(float red_, float green_, float blue_);

protected:
	double x, y, z;               // position
	double rotation;              // heading of the object in the horizontal plane (degrees)
	float red, green, blue;       // colour of object

};


// Rectangular prism class

class Rectangular : public Shape
{
public:
	Rectangular();
	Rectangular(double x_len, double y_len, double z_len);
	Rectangular(double x_len, double y_len, double z_len, double rotation);

	double Getx_length();
	double Gety_length();
	double Getz_length();

	void Setx_length(double x_len);
	void Sety_length(double y_len);
	void Setz_length(double z_len);
	void Setlength(double x_len, double y_len, double z_len);

	void draw();

protected:
	double x_length, y_length, z_length;
};


// Triangular prism class

class Triangular : public Shape
{
public:
	Triangular();
	Triangular(double sideA_len, double sideB_len);
	Triangular(double sideA_len, double sideB_len, double sideC_len);
	Triangular(double sideA_len, double sideB_len, double sideC_len, double depth);
	Triangular(double sideA_len, double sideB_len, double sideC_len, double depth, double rotation);

	double GetsideA();
	double GetsideB();
	double GetsideC();
	double Getdepth();
	double Getangle();

	void SetsideA(double sideA_len);
	void SetsideB(double sideB_len);
	void SetsideC(double sideC_len);
	void Setside(double sideA_len, double sideB_len, double sideC_len);
	void Setdepth(double len);
	void Setangle(double degree);

	// When SideC changes, Use it
	void UpdateAngle(); 
	// When SideA, SideB and angle change, Use it
	void UpdateSideC(); 

	void draw();

protected:
	double sideA = 0;
	double sideB = 0;
	double sideC = 0;
	double depth = 10;
	double angle = 0; // The angle between sideA and sideB


};


// Trapezoidal Prism class

class Trapezoidal : public Shape
{
public:
	Trapezoidal();
	Trapezoidal(double longside, double offset, double height);
	Trapezoidal(double longside, double offset, double height, double depth);
	Trapezoidal(double longside, double offset, double height, double depth, double rotation);

	double Getlong();
	double Getoffset();
	double Getheight();
	double Getdepth();

	void Setlong(double longside);
	void Setoffset(double offset);
	void Setheight(double height);
	void Setdepth(double depth);
	void SetTrapezium(double longside, double offset, double height);

	void draw();

protected:
	double longside;
	double offset;
	double height;
	double depth;

};


// Culinder prism class

class Cylinder : public Shape {
public:
	Cylinder();
	Cylinder(double radius, double length);
	Cylinder(double radius, double length, double rotation);

	double Getradius();
	double Getlength();

	void Setradius(double size);
	void Setlength(double size);

	void draw();

protected:
	double radius;
	double length;
};
#endif // for MTRN3500_SHAPE_H

