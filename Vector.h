#ifndef VECTOR_H
#define VECTOR_H

namespace dequinox
{
	struct Vector
	{
	    	float x{0};
	    	float y{0};
	    	
		Vector(float x, float y) : x(x), y(y) {}
	    	
		Vector(const Vector &other)
		{
			x = other.x;
			y = other.y;
	    	}


	    	float getMag() const
		{
			return sqrt(x*x + y*y);
	    	}

	    	void operator=(const Vector &other)
		{
			x = other.x;
			y = other.y;
	    	}
	
	    	Vector operator*(float len) const
		{
			return Vector(x * len, y * len);
	    	}

	    	Vector operator/(float len) const
		{
			return Vector(x / len, y / len);
	    	}

	    	Vector operator+(Vector other) const
		{
			return Vector(x + other.x, y + other.y);
	    	}

	    	Vector operator-(Vector other) const
		{
			return Vector(x - other.x, y - other.y);
	    	}

		bool operator<(const Vector &other) const
		{
			return x < other.x || (x == other.x && y < other.y);
	    	}

	    	bool operator==(const Vector &other) const
		{
			return x == other.x && y == other.y;
	    	}

		void normalize()
		{
			x /= getMag();
			y /= getMag();
	    	}

	    	float dist(const Vector &other) const{
			return sqrt((x - other.x)*(x - other.x)
		     		  + (y - other.y)*(y - other.y));
	    	}
	};
}

#endif // VECTOR_H
