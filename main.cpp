#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include "figure.h"
#include <iostream>
#include <math.h>

int main()
{
    std::array < std::pair<double, double>, 3> points;
    points[0] = { 0, 0 };
    points[1] = { 0.5, std::sqrt(3) };
    points[2] = { 2, 0 };
    Triangle f1 = Triangle(points);
    std::cout << f1 << std::endl;
    std::cout << "(" << f1.center().first << ", " << f1.center().second << ")" << std::endl;
    std::cout << f1.square() << std::endl;
    std::cout << (double)f1 << std::endl;
}