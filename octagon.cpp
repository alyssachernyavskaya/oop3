#include "octagon.h"
#include <math.h>

const int verticeCount = 8;// Количество вершин


/// Конструктор с инициализацией по вершинам
Octagon::Octagon(const std::array<std::pair<double, double>, 8>& vertices) : _vertices(vertices)
{}

/// Центр восьмиугольника
std::pair<double, double> Octagon::center() const
{
	double x = 0, y = 0;
	std::pair<double, double> v0 = _vertices[0];
	std::pair<double, double> v1 = _vertices[verticeCount / 2];
	x = (v0.first + v1.first) / 2;
	y = (v0.second + v1.second) / 2;
	return { x, y };
}

/// Площадь
double Octagon::square() const
{
	double side = std::sqrt(std::pow(_vertices[1].first - _vertices[0].first, 2) +
		std::pow(_vertices[1].second - _vertices[0].second, 2));
	return std::pow(side, 2) * (1 + std::sqrt(2)) * 2;
}

/// Вывод
void Octagon::print(std::ostream& stream) const
{
	stream << "Octagon: ";
	for (const auto& v : _vertices)
	{
		stream << "(" << v.first << ", " << v.second << ")";
	}
}

/// Ввод
void Octagon::read(std::istream& stream)
{
	for (int i = 0; i < verticeCount; i++)
	{
		double x, y;
		if (!(stream >> x >> y))
			throw std::runtime_error("Octagon: input error");
		_vertices[i] = { x, y };
	}
}

/// Конструктор с инициализацией из другого объекта (копированием)
Octagon::Octagon(const Octagon& other) : _vertices(other._vertices)
{}

/// Перегрузка оператора присваивания - конструктор
Octagon& Octagon::operator = (const Octagon& other)
{
	if (this != &other)
		_vertices = other._vertices;
	return *this;
}

/// Конструктор с инициализацией из другого объекта (пееремещением)
Octagon::Octagon(Octagon&& other) noexcept : _vertices(std::move(other._vertices))
{}

/// Перегрузка оператора присваивания - конструктор
Octagon& Octagon::operator = (Octagon&& other) noexcept
{
	if (this != &other)
		_vertices = std::move(other._vertices);
	return *this;
}

/// Перегрузка оператора сравнения
bool Octagon::operator == (const Figure& other) const
{
	const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
	if (!otherOctagon)
		return false;
	return _vertices == otherOctagon->_vertices;
}

/// Скоприовать
Figure* Octagon::copy() const
{
	return new Octagon(*this);
}


