#pragma once
#include <iostream>

class Cubo {
public:
	Cubo(double x = 0, double y = 0, double z =0) : x(x), y(y) , z(z){}
	double getX() const { return x; }
	double getY() const { return y; }
	double getZ() const { return z; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void setZ(double z) { this->z = z; }
private:
	double x;
	double y;
	double z;
};

Cubo operator+(Cubo p1, Cubo p2);
std::ostream &operator << (std::ostream &ausgabestrom, Cubo &cubo);