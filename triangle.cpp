#include "triangle.h"
#include <math.h>

const int verticeCount = 3;// Количество вершин

/// // Конструктор с инициализацией по вершинам
Triangle::Triangle(const std::array<std::pair<double, double>, 3>& vertices) : _vertices(vertices)
{}

/// Центр треугольника
std::pair<double, double> Triangle::center() const
{
	double x = 0, y = 0;
	for (const auto& v : _vertices)
	{
		x += v.first;
		y += v.second;
	}
	return { x / verticeCount, y / verticeCount };
}

/// Площадь
double Triangle::square() const
{
	double side = std::sqrt(std::pow(_vertices[1].first - _vertices[0].first, 2) +
		std::pow(_vertices[1].second - _vertices[0].second, 2));
	return std::pow(side, 2) * std::sqrt(3) / 4;
}

/// Вывод
void Triangle::print(std::ostream& stream) const
{
	stream << "Triangle: ";
	for (const auto& v : _vertices)
	{
		stream << "(" << v.first << ", " << v.second << ")";
	}
}

/// Ввод
void Triangle::read(std::istream& stream)
{
	for (int i = 0; i < verticeCount; i++)
	{
		double x, y;
		if (!(stream >> x >> y))
			throw std::runtime_error("Triangle: input error");
		_vertices[i] = { x, y };
	}
}

/// Конструктор с инициализацией из другого объекта (копированием)
Triangle::Triangle(const Triangle& other) : _vertices(other._vertices)
{}

/// Перегрузка оператора присваивания - конструктор
Triangle& Triangle::operator = (const Triangle& other)
{
	if (this != &other)
		_vertices = other._vertices;
	return *this;
}

/// Конструктор с инициализацией из другого объекта (пееремещением)
Triangle::Triangle(Triangle&& other) noexcept : _vertices(std::move(other._vertices))
{}

/// Перегрузка оператора присваивания - конструктор
Triangle& Triangle::operator = (Triangle&& other) noexcept
{
	if (this != &other)
		_vertices = std::move(other._vertices);
	return *this;
}

/// Перегрузка оператора сравнения
bool Triangle::operator == (const Figure& other) const
{
	const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
	if (!otherTriangle)
		return false;
	return _vertices == otherTriangle->_vertices;
}

/// Скоприовать
Figure* Triangle::copy() const
{
	return new Triangle(*this);
}
