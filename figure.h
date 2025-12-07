#pragma once

#include <utility>
#include <iostream>

class Figure
{
public:
	virtual ~Figure() = default;										// Деструктор

	virtual std::pair<double, double> center() const = 0;				// Центр

	virtual double square() const = 0;									// Площадь

	virtual void print(std::ostream& stream) const = 0;					// Вывод
	virtual void read(std::istream& stream) = 0;						// Ввод

	virtual operator double() const { return square(); }				// Площадь через перегрузку оператора приведения к типу double

	virtual Figure* copy() const = 0;									// Скопировать

	virtual bool operator == (const Figure& other) const = 0;			// Перегрузка оператора сравнения
};

std::ostream& operator << (std::ostream& stream, const Figure& figure);// Перегрузка оператора вывода
std::istream& operator >> (std::istream& stream, Figure& figure);		// Перегрузка оператора ввода

