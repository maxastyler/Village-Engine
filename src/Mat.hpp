#ifndef _MAT_HPP
#define _MAT_HPP

#include "Vec.hpp"

//Members are denoted by aa, ab, ba, bb

struct Mat {

    float aa, ab, ba, bb;
    Mat(float, float, float, float);

    Mat operator*(Mat&);
    Vec operator*(Vec&);
    Mat operator*(float);
    void operator*=(Mat&);
    void operator*=(float);

    Mat operator/(float);
    void operator/=(float);

    Mat operator+(Mat&);
    void operator+=(Mat&);

    Mat operator-(Mat&);
    void operator-=(Mat&);

};

#endif
