/*
 * #644 Squares on the line
 * Game(eliminate bad strategies) + Probability
 *
 * If Sam place the first square in the middle of the line segment,
 * Sam will definitely win by copying Tom's move.
 * e(L) = L * (p_s(L) + p_d(L)) / 2
 *      = Integral(0, L) {(p(x, L-1-x) + p(x, L-sqrt(2)-x)) * dx / L}
 * where p(x, y) represents the probability of winning when the segment is divided in to two parts
 * whose length is x and y respectively and Tom goes first.
 * This problem is converted to solving p.
 * Obviously, p(x, y) = p(x, 0) = 0 if y < 1 && x >= 1. Similarly, p(x, y) = 0 if x < 1 && y >= 1.
 * p(x, y) = 1 if x < 1 && y < 1.
 * Then the domain is restricted to x >= 1 && y >= 1.
 * For the symmetricity, assume x <= y without loss of generality.
 * If 1 <= x < 2, the x part can hold only 1 square. So clever Tom will choose the y part.
 * Tom won't choose the middle obviously.
 * Consider 1 <= y < 2, Sam wins.
 * If 2 <= y < 4, Tom wins.
