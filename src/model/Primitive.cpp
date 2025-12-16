#include "include/model/Primitive.h"

// ============================================================================
// Circle Implementation
// ============================================================================

Circle::Circle(int id, double radius) 
    : id(id), radius(radius) {}

int Circle::getId() const {
    return id;
}

std::string Circle::getType() const {
    return "Circle";
}

void Circle::draw() const {
    std::cout << "[LOG] Рисуем круг №" << id << " с радиусом " << radius << std::endl;
}

std::string Circle::getInfo() const {
    return "Примитив 'Круг' №" + std::to_string(id) + " (радиус: " + 
           std::to_string(radius) + ")";
}

void Circle::setRadius(double r) {
    radius = r;
    std::cout << "[LOG] Радиус круга №" << id << " изменен на " << radius << std::endl;
}

double Circle::getRadius() const {
    return radius;
}

// ============================================================================
// Rectangle Implementation
// ============================================================================

Rectangle::Rectangle(int id, double width, double height)
    : id(id), width(width), height(height) {}

int Rectangle::getId() const {
    return id;
}

std::string Rectangle::getType() const {
    return "Rectangle";
}

void Rectangle::draw() const {
    std::cout << "[LOG] Рисуем прямоугольник №" << id 
              << " (ширина: " << width << ", высота: " << height << ")" << std::endl;
}

std::string Rectangle::getInfo() const {
    return "Примитив 'Прямоугольник' №" + std::to_string(id) + 
           " (ширина: " + std::to_string(width) + ", высота: " + 
           std::to_string(height) + ")";
}

void Rectangle::setDimensions(double w, double h) {
    width = w;
    height = h;
    std::cout << "[LOG] Размеры прямоугольника №" << id 
              << " изменены на (" << width << " x " << height << ")" << std::endl;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

// ============================================================================
// Line Implementation
// ============================================================================

Line::Line(int id, double x1, double y1, double x2, double y2)
    : id(id), x1(x1), y1(y1), x2(x2), y2(y2) {}

int Line::getId() const {
    return id;
}

std::string Line::getType() const {
    return "Line";
}

void Line::draw() const {
    std::cout << "[LOG] Рисуем линию №" << id 
              << " от (" << x1 << ", " << y1 << ") до (" 
              << x2 << ", " << y2 << ")" << std::endl;
}

std::string Line::getInfo() const {
    return "Примитив 'Линия' №" + std::to_string(id) + 
           " от (" + std::to_string(x1) + ", " + std::to_string(y1) + 
           ") до (" + std::to_string(x2) + ", " + std::to_string(y2) + ")";
}

void Line::setCoordinates(double x1, double y1, double x2, double y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    std::cout << "[LOG] Координаты линии №" << id << " изменены" << std::endl;
}