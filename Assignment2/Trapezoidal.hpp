#include "Shape.hpp"

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

