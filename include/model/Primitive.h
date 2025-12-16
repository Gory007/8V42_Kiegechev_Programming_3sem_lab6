#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <memory>
#include <string>
#include <iostream>

/**
 * @class Primitive
 * @brief Абстрактный базовый класс для графического примитива
 * 
 * Использует полиморфизм для поддержки различных типов примитивов
 */
class Primitive {
public:
    virtual ~Primitive() = default;

    /**
     * @brief Получить уникальный идентификатор примитива
     */
    virtual int getId() const = 0;

    /**
     * @brief Получить тип примитива
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Отрисовать примитив (log-информация)
     */
    virtual void draw() const = 0;

    /**
     * @brief Получить информацию о примитиве
     */
    virtual std::string getInfo() const = 0;
};

/**
 * @class Circle
 * @brief Конкретная реализация круга
 */
class Circle : public Primitive {
private:
    int id;
    double radius;

public:
    Circle(int id, double radius);
    ~Circle() override = default;

    int getId() const override;
    std::string getType() const override;
    void draw() const override;
    std::string getInfo() const override;

    void setRadius(double r);
    double getRadius() const;
};

/**
 * @class Rectangle
 * @brief Конкретная реализация прямоугольника
 */
class Rectangle : public Primitive {
private:
    int id;
    double width;
    double height;

public:
    Rectangle(int id, double width, double height);
    ~Rectangle() override = default;

    int getId() const override;
    std::string getType() const override;
    void draw() const override;
    std::string getInfo() const override;

    void setDimensions(double w, double h);
    double getWidth() const;
    double getHeight() const;
};

/**
 * @class Line
 * @brief Конкретная реализация линии
 */
class Line : public Primitive {
private:
    int id;
    double x1, y1, x2, y2;

public:
    Line(int id, double x1, double y1, double x2, double y2);
    ~Line() override = default;

    int getId() const override;
    std::string getType() const override;
    void draw() const override;
    std::string getInfo() const override;

    void setCoordinates(double x1, double y1, double x2, double y2);
};

#endif // PRIMITIVE_H