#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
    float x{0};
	float y{0};

    Vector();
    Vector(float _x, float _y);
    Vector(const Vector &other);

    float getMag() const;
    void normalize();
    double dist(const Vector &other) const;
    void operator=(const Vector &other);
    Vector operator*(float len) const;
    Vector operator/(float len) const;
    Vector operator+(Vector other) const;
    Vector operator-(Vector other) const;
    bool operator<(const Vector &other) const;
    bool operator==(const Vector &other) const;
};

#endif // VECTOR_H