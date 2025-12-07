#pragma once

#include "figure.h"
#include <array>

/// Шестиугольник
class Hexagon :
    public Figure
{
private:
    std::array<std::pair<double, double>, 6> _vertices;                // Вершины

public:
    Hexagon() = default;                                               // Конструктор
    Hexagon(const std::array<std::pair<double, double>, 6>& vertices); // Конструктор с инициализацией по вершинам

    std::pair<double, double> center() const override;                 // Центр
    double square() const override;                                    // Площадь

    void print(std::ostream& stream) const override;                   // Вывод
    void read(std::istream& stream)  override;                         // Ввод

    Hexagon(const Hexagon& other);                                     // Конструктор копированием
    Hexagon& operator = (const Hexagon& other);                        // Перегрузка оператора присваивания

    Hexagon(Hexagon&& other) noexcept;                                 // Конструктор перемещением
    Hexagon& operator = (Hexagon&& other) noexcept;                    // Перегрузка оператора присваивания перемещением

    bool operator == (const Figure& other) const override;             // Перегрузка оператора сравнения
    Figure* copy() const override;                                     // Скопировать
};

