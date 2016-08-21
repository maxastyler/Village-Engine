#include "Vec.hpp"
#include <math.h>

Vec::Vec(float x, float y) {
    this->x=x;
    this->y=y;
};

Vec::Vec() {
    this->x=0;
    this->y=0;
};

void Vec::normalise() {
    float mag=this->magnitude(); 
    if (mag!=0) {
        this->x/=mag;
        this->y/=mag;
    } else {
        this->x=1;
        this->y=0;
    };
};

Vec Vec::normalised() {
    float mag=this->magnitude();
    if (mag!=0) 
        return Vec(this->x/mag, this->y/mag);
    else
        return Vec(1, 0);
};

float Vec::magnitude_sq() {
    return (this->x*this->x+this->y*this->y); 
};

float Vec::magnitude() {
    return sqrt(this->magnitude_sq());
};

Vec Vec::operator+(Vec& other) {
    return Vec(this->x+other.x, this->y+other.y);
};

void Vec::operator+=(Vec& other) {
    this->x+=other.x;
    this->y+=other.y;
};

Vec Vec::operator-(Vec& other) {
    return Vec(this->x-other.x, this->y-other.y);
};

void Vec::operator-=(Vec& other) {
    this->x-=other.x;
    this->y-=other.y;
};

float Vec::operator*(Vec& other) {
    return (this->x*other.x+this->y*other.y);    
};

Vec Vec::operator*(float other) {
    return Vec(this->x*other, this->y*other);
};

void Vec::operator*=(float other) {
    this->x*=other;
    this->y*=other;
};

Vec Vec::operator/(float other) {
    return Vec(this->x/other, this->y/other);
};

void Vec::operator/=(float other) {
    this->x/=other;
    this->y/=other;
};
