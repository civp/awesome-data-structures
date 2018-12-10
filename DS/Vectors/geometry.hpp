/*
 * Plane Geometry Library
 * Deal with the bad encapsulation
 */
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

class Point
{
public:
	double x, y;
	Point()
	{
		x = y = 0;
	}
	Point(const double &x, const double &y)
	{
		this->x = x;
		this->y = y;
	}
	Point(const Point &p)
	{
		this->x = p.x;
		this->y = p.y;
	}
};

class Segment
{
public:
	Point p1, p2;
	Segment();
	Segment(const Point &p1, const Point &p2)
	{
		this->p1.x = p1.x;
		this->p1.y = p1.y;
		this->p2.x = p2.x;
		this->p2.y = p2.y;
	}
};

class Vector
{
public:
	double x, y;
	Vector();
	Vector(const Segment &s)
	{
		this->x = s.p2.x - s.p1.x;
		this->y = s.p2.y - s.p1.y;
	}
	Vector(const Point &pa, const Point &pb)
	{
		this->x = pb.x - pa.x;
		this->y = pb.y - pa.y;
	}
	Vector operator +(const Vector &v)
	{
		Vector ret;
		ret.x = this->x + v.x;
		ret.y = this->y + v.y;
		return ret;
	}
	double operator *(const Vector &v) // cross
	{
		return this->x * v.y - this->y * v.x;
	}
};

class ConvexHull
{
public:
	std::vector<Point> p;
};

inline int sgn(const double &x)
{
	return x < 0 ? -1 : (x > 0 ? 1 : 0);
}

#endif