#include "figure.h"

/// Перегрузка оператора вывода
std::ostream& operator << (std::ostream& stream, const Figure& figure)
{
	figure.print(stream);
	return stream;
}

/// Перегрузка оператора ввода
std::istream& operator >> (std::istream& stream, Figure& figure)
{
	figure.read(stream);
	return stream;
}
