#ifndef _TRANSFORM_HPP
#define _TRANSFORM_HPP

#include "Vec.hpp"

struct Transform {

    Vec pos;
    float rot;
    float scale;

    Transform(Vec, float, float);
    Transform(float, float, float, float);
    Transform();
};

#endif
