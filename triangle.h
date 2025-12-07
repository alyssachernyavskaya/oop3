#pragma once

#include "figure.h"
#include <array>

/// Треугольник
class Triangle :
    public Figure
{
private:
    std::array<std::pair<double, double>, 3> _vertices;                     // Вершины

public:
    Triangle() = default;                                                   // Конструктор
    Triangle(const std::array<std::pair<double, double>, 3>& vertices);     // Конструктор с инициализацией по вершинам

    std::pair<double, double> center() const override;                      // Центр
    double square() const override;                                         // Площадь

    void print(std::ostream& stream) const override;                        // Вывод
    void read(std::istream& stream)  override;                              // Ввод

    Triangle(const Triangle& other);                                        // Конструктор копированием
    Triangle& operator = (const Triangle& other);                           // Перегрузка оператора присваивания

    Triangle(Triangle&& other) noexcept;                                    // Конструктор перемещением
    Triangle& operator = (Triangle&& other) noexcept;                       // Перегрузка оператора присваивания перемещением

    bool operator == (const Figure& other) const override;                  // Перегрузка оператора сравнения
    Figure* copy() const override;                                          // Скопировать
};

