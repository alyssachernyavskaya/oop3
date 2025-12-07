#include <gtest/gtest.h>
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"
#include "figure.h"
#include <memory>

TEST(TriangleTest, AreaCalculation) 
{
std::array<std::pair<double, double>, 3> vertices = 
{
    std::make_pair(0.0, 0.0),
    std::make_pair(4.0, 0.0),
    std::make_pair(0.0, 3.0)
};
Triangle triangle(vertices);
EXPECT_DOUBLE_EQ(6.0, triangle.square());
}

TEST(TriangleTest, CenterCalculation) 
{
    std::array<std::pair<double, double>, 3> vertices = 
    {
        std::make_pair(0.0, 0.0),
        std::make_pair(3.0, 0.0),
        std::make_pair(0.0, 3.0)
    };
    Triangle triangle(vertices);
    auto center = triangle.center();
    EXPECT_DOUBLE_EQ(1.0, center.first);
    EXPECT_DOUBLE_EQ(1.0, center.second);
}

TEST(HexagonTest, AreaCalculation) 
{
    std::array<std::pair<double, double>, 6> vertices = 
    {
        std::make_pair(0.0, 0.0),
        std::make_pair(2.0, 0.0),
        std::make_pair(3.0, 1.0),
        std::make_pair(2.0, 2.0),
        std::make_pair(0.0, 2.0),
        std::make_pair(-1.0, 1.0)
    };
    Hexagon hexagon(vertices);
    EXPECT_DOUBLE_EQ(6.0, hexagon.square());
}

TEST(HexagonTest, CenterCalculation) 
{
    std::array<std::pair<double, double>, 6> vertices = 
    {
        std::make_pair(0.0, 0.0),
        std::make_pair(4.0, 0.0),
        std::make_pair(6.0, 2.0),
        std::make_pair(4.0, 4.0),
        std::make_pair(0.0, 4.0),
        std::make_pair(-2.0, 2.0)
    };
    Hexagon hexagon(vertices);
    auto center = hexagon.center();
    EXPECT_DOUBLE_EQ(2.0, center.first);
    EXPECT_DOUBLE_EQ(2.0, center.second);
}

TEST(OctagonTest, AreaCalculation) 
{
    std::array<std::pair<double, double>, 8> vertices = 
    {
        std::make_pair(0.0, 0.0),
        std::make_pair(2.0, 0.0),
        std::make_pair(4.0, 0.0),
        std::make_pair(4.0, 2.0),
        std::make_pair(4.0, 4.0),
        std::make_pair(2.0, 4.0),
        std::make_pair(0.0, 4.0),
        std::make_pair(0.0, 2.0)
    };
    Octagon octagon(vertices);
    EXPECT_DOUBLE_EQ(16.0, octagon.square());
}

TEST(OctagonTest, CenterCalculation) 
{
    std::array<std::pair<double, double>, 8> vertices = 
    {
        std::make_pair(0.0, 0.0),
        std::make_pair(2.0, 0.0),
        std::make_pair(4.0, 0.0),
        std::make_pair(4.0, 2.0),
        std::make_pair(4.0, 4.0),
        std::make_pair(2.0, 4.0),
        std::make_pair(0.0, 4.0),
        std::make_pair(0.0, 2.0)
    };
    Octagon octagon(vertices);
    auto center = octagon.center();
    EXPECT_DOUBLE_EQ(2.0, center.first);
    EXPECT_DOUBLE_EQ(2.0, center.second);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}