#pragma once
#pragma once
#include <iostream>

class Punkt {
public:
	Punkt(double x = 0, double y = 0) : x(x), y(y) {}
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }

private:
	double x;
	double y;
};

Punkt operator+(Punkt p1, Punkt p2);
std::ostream &operator << (std::ostream &ausgabestrom, Punkt &punkt);