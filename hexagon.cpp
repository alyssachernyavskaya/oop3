#include "hexagon.h"
#include <math.h>

const int verticeCount = 6;// Количество вершин

/// // Конструктор с инициализацией по вершинам
Hexagon::Hexagon(const std::array<std::pair<double, double>, 6>& vertices) : _vertices(vertices)
{}

/// Центр шестиугольника
std::pair<double, double> Hexagon::center() const
{
	double x = 0, y = 0;
	std::pair<double, double> v0 = _vertices[0];
	std::pair<double, double> v1 = _vertices[verticeCount / 2];
	x = (v0.first + v1.first) / 2;
	y = (v0.second + v1.second) / 2;
	return { x, y };
}

/// Площадь
double Hexagon::square() const
{
	double side = std::sqrt(std::pow(_vertices[1].first - _vertices[0].first, 2) +
		std::pow(_vertices[1].second - _vertices[0].second, 2));
	return std::pow(side, 2) * std::sqrt(3) * 3 / 2;
}

/// Вывод
void Hexagon::print(std::ostream& stream) const
{
	stream << "Hexagon: ";
	for (const auto& v : _vertices)
	{
		stream << "(" << v.first << ", " << v.second << ")";
	}
}

/// Ввод
void Hexagon::read(std::istream& stream)
{
	for (int i = 0; i < verticeCount; i++)
	{
		double x, y;
		if (!(stream >> x >> y))
			throw std::runtime_error("Hexagon: input error");
		_vertices[i] = { x, y };
	}
}

/// Конструктор с инициализацией из другого объекта (копированием)
Hexagon::Hexagon(const Hexagon& other) : _vertices(other._vertices)
{}

/// Перегрузка оператора присваивания - конструктор
Hexagon& Hexagon::operator = (const Hexagon& other)
{
	if (this != &other)
		_vertices = other._vertices;
	return *this;
}

/// Конструктор с инициализацией из другого объекта (пееремещением)
Hexagon::Hexagon(Hexagon&& other) noexcept : _vertices(std::move(other._vertices))
{}

/// Перегрузка оператора присваивания - конструктор
Hexagon& Hexagon::operator = (Hexagon&& other) noexcept
{
	if (this != &other)
		_vertices = std::move(other._vertices);
	return *this;
}

/// Перегрузка оператора сравнения
bool Hexagon::operator == (const Figure& other) const
{
	const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
	if (!otherHexagon)
		return false;
	return _vertices == otherHexagon->_vertices;
}

/// Скоприовать
Figure* Hexagon::copy() const
{
	return new Hexagon(*this);
}

