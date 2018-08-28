
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

	double Get_x_length();
	double Get_y_length();
	double Get_z_length();

	void Set_x_length(double x_len);
	void Set_y_length(double y_len);
	void Set_z_length(double z_len);
	void Set_length(double x_len, double y_len, double z_len);

	void draw();

protected:
	double x_length, y_length, z_length;
};


// Triangular prism class definition

class Triangular : public Shape
{
public:
	Triangular();
	Triangular(double sideA_len, double sideB_len);
	Triangular(double sideA_len, double sideB_len, double sideC_len);

	double Get_sideA();
	double Get_sideB();
	double Get_sideC();
	double Get_depth();
	double Get_angle();

	void Set_sideA(double sideA_len);
	void Set_sideB(double sideB_len);
	void Set_sideC(double sideC_len);
	void Set_side(double sideA_len, double sideB_len, double sideC_len);
	void Set_depth(double len);
	void Set_angle(double degree);

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
#endif // for MTRN3500_SHAPE_H

