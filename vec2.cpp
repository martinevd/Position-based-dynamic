#include "vec2.h"
#include <math.h>
#include <stdexcept>
#include <iostream>

Vec2::Vec2(float x,float y):x(x),y(y){}

float Vec2::getx() const{
    return x;
}

void Vec2::setx(float newx){
    x = newx;
}

float Vec2::gety() const{
    return y;
}

void Vec2::sety(float newy){
    y = newy;
}

Vec2::Vec2(const Vec2& other):x(other.x),y(other.y){}

Vec2 Vec2::operator+(const Vec2& other) const{
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const{
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const{
    return Vec2(x*scalar,y*scalar);
}

Vec2 Vec2::operator/(float scalar) const{
    if(scalar == 0){
        throw std::runtime_error("Division par zéro !");
    }
    return Vec2(x/scalar,y/scalar);
}

Vec2& Vec2::operator=(const Vec2& other){
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vec2& Vec2::operator+=(const Vec2& other){
    x += other.x;
    y += other.y;
    return *this;
}

bool Vec2::operator==(const Vec2& other) const{
    return x == other.x && y == other.y;
}

float Vec2::norm() const{
    return sqrt(x * x + y * y);
}

Vec2 Vec2::normalize() const{
    float length = norm();
    if (length > 0) {
        return *this / length;
    }
    throw std::runtime_error("Normalisation d'un vecteur nul !");
}

float Vec2::dot(const Vec2& other) const{
    return x * other.x + y * other.y;
}

void Vec2::print() const{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
