#include "geometry.hpp"

bool isIntersect(Segment sa, Segment sb)
{
	Vector v11(sa.p1, sb.p1), v12(sa.p1, sb.p2);
	Vector v21(sb.p1, sa.p1), v22(sb.p1, sa.p2);
	Vector a(sa), b(sb);

	return (sgn(v11 * a) != sgn(v12 * b) &&
			sgn(v21 * b) != sgn(v22 * b));
}

bool isInside(Point p, ConvexHull ch)
{
	// Assume counter-clockwise storage
	for (int i = 0; i < ch.size(); ++i)
		if (Vector(ch.p[i], p) * Vector(ch.p[i], ch.p[i + 1] > 0) > 0)
			return false;
	return true;
}

bool isInside(Point p, Polygon poly)
{
	
}

#ifdef DEBUG

#include <iostream>

int main(int argc, char const *argv[])
{
	Point pa(0, 0), pb(1, 1), pc(0, 1), pd(1, 0);
	Segment sa(pa, pb), sb(pc, pd);
	if (isIntersect(sa, sb))
		std::cout << "Intersect" << std::endl;
	return 0;
}

#endif