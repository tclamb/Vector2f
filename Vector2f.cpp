#include "Vector2f.h"

#include <algorithm> //for std::swap
#include <cmath>     //for std::sqrt
#include <stdexcept> //for std::out_of_range

/*
Vector2f& Vector2f::operator=(Vector2f const& other) {
    if(this != &other) {
        x = other.x;
        y = other.y;
    }

    return *this;
}

void swap(Vector2f& first, Vector2f& second) {
    using std::swap;

    swap(first.x, second.x);
    swap(first.y, second.y);
}
*/

float Vector2f::getMagnitudeSquared() const {
    return x*x + y*y;
}

float Vector2f::getMagnitude() const {
    using std::sqrt;

    return sqrt(getMagnitudeSquared());
}

Vector2f& Vector2f::toUnit() {
    auto magnitude = getMagnitude();

    x /= magnitude;
    y /= magnitude;

    return *this;
}

Vector2f& Vector2f::toRightNormal() {
    using std::swap;
    
    swap(x, y);
    y *= -1;

    return *this;
}

Vector2f& Vector2f::toLeftNormal() {
    using std::swap;

    swap(x, y);
    x *= -1;

    return *this;
}

Vector2f& Vector2f::operator+=(Vector2f const& v) {
    x += v.x;
    y += v.y;

    return *this;
}

Vector2f& Vector2f::operator-=(Vector2f const& v) {
    x -= v.x;
    y -= v.y;

    return *this;
}

Vector2f& Vector2f::operator*=(float const& s) {
    x *= s;
    y *= s;

    return *this;
}

float Vector2f::operator*(Vector2f const& v) const {
    return x*v.x + y*v.y;
}

float Vector2f::operator^(Vector2f const& v) const {
    return x*v.y - v.x*y;
}

float& Vector2f::operator[](int idx) {
    using std::out_of_range;

    if(idx > 1 || idx < 0)
        throw out_of_range("Vector2f::operator[]");
    
    if(idx == 0)   return x;
  /*if(idx == 1)*/ return y;
}

