#include "Vector.h"
#include <cmath>

//////////////////////////////////////
// Vector methods
Vector::Vector() : x(0), y(0) {}

Vector::Vector(float _x, float _y) : x(_x), y(_y) {}

Vector::Vector(const Vector &other){
	x = other.x;
	y = other.y;
}

double Vector::dist(const Vector &other) const {
    return sqrt((x - other.x)*(x - other.x)
		      + (y - other.y)*(y - other.y));
}

float Vector::getMag() const{
	return sqrt(x*x + y*y);
}

void Vector::normalize(){
	x /= getMag();
	y /= getMag();
}

void Vector::operator=(const Vector &other){
	x = other.x;
    y = other.y;
}

Vector Vector::operator+(Vector other) const {
    return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(Vector other) const {
    return Vector(x - other.x, y - other.y);
}

Vector Vector::operator*(float len) const {
    return Vector(x * len, y * len);
}

Vector Vector::operator/(float len) const {
    return Vector(x / len, y / len);
}

bool Vector::operator<(const Vector &other) const {
	return x < other.x || (x == other.x && y < other.y);
}

bool Vector::operator==(const Vector &other) const {
	return x == other.x && y == other.y;
}