#include "Transform.hpp"

#include "Vec.hpp"

Transform::Transform(Vec pos=Vec(0, 0), float rot=0, float scale=1) {
    this->pos=pos;
    this->rot=rot;
    this->scale=scale;
};

Transform::Transform(float x=0, float y=0, float rot=0, float scale=1) {
    this->pos=Vec(x, y);
    this->rot=rot;
    this->scale=scale;
};

Transform::Transform() {
    this->pos=Vec(0, 0);
    this->rot=0;
    this->scale=0;
};
