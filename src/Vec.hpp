#ifndef _VEC_HPP
#define _VEC_HPP

struct Vec { 

    float x, y;
    Vec(float, float);
    Vec();
    
    void normalise();
    Vec normalised();
    float magnitude_sq();
    float magnitude();

    Vec operator-(Vec&);
    void operator-=(Vec&);

    Vec operator+(Vec&);
    void operator+=(Vec&);

    float operator*(Vec&);
    Vec operator*(float);
    void operator*=(float);

    Vec operator/(float);
    void operator/=(float);

};

#endif
