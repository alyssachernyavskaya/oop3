#pragma once

#include "figure.h"
#include <array>

/// Восьмиугольник
class Octagon :
    public Figure
{
private:
    std::array<std::pair<double, double>, 8> _vertices;                     // Вершины

public:
    Octagon() = default;                                                    // Конструктор
    Octagon(const std::array<std::pair<double, double>, 8>& vertices);      // Конструктор с инициализацией по вершинам

    std::pair<double, double> center() const override;                      // Центр
    double square() const override;                                         // Площадь

    void print(std::ostream& stream) const override;                        // Вывод
    void read(std::istream& stream)  override;                              // Ввод

    Octagon(const Octagon& other);                                          // Конструктор копированием
    Octagon& operator = (const Octagon& other);                             // Перегрузка оператора присваивания

    Octagon(Octagon&& other) noexcept;                                      // Конструктор перемещением
    Octagon& operator = (Octagon&& other) noexcept;                         // Перегрузка оператора присваивания перемещением

    bool operator == (const Figure& other) const override;                  // Перегрузка оператора сравнения
    Figure* copy() const override;                                          // Скопировать
};


