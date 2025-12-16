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
    std::cout << "[LOG] Drawing circle #" << id << " with radius " << radius << std::endl;
}

std::string Circle::getInfo() const {
    return "Primitive 'Circle' #" + std::to_string(id) + " (radius: " + 
           std::to_string(radius) + ")";
}

void Circle::setRadius(double r) {
    radius = r;
    std::cout << "[LOG] Circle #" << id << " radius changed to " << radius << std::endl;
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
    std::cout << "[LOG] Drawing rectangle #" << id 
              << " (width: " << width << ", height: " << height << ")" << std::endl;
}

std::string Rectangle::getInfo() const {
    return "Primitive 'Rectangle' #" + std::to_string(id) + 
           " (width: " + std::to_string(width) + ", height: " + 
           std::to_string(height) + ")";
}

void Rectangle::setDimensions(double w, double h) {
    width = w;
    height = h;
    std::cout << "[LOG] Rectangle #" << id 
              << " dimensions changed to (" << width << " x " << height << ")" << std::endl;
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
    std::cout << "[LOG] Drawing line #" << id 
              << " from (" << x1 << ", " << y1 << ") to (" 
              << x2 << ", " << y2 << ")" << std::endl;
}

std::string Line::getInfo() const {
    return "Primitive 'Line' #" + std::to_string(id) + 
           " from (" + std::to_string(x1) + ", " + std::to_string(y1) + 
           ") to (" + std::to_string(x2) + ", " + std::to_string(y2) + ")";
}

void Line::setCoordinates(double x1, double y1, double x2, double y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    std::cout << "[LOG] Line #" << id << " coordinates changed" << std::endl;
}