#include "Mat.hpp"
#include "Vec.hpp"

Mat::Mat(float aa, float ab, float ba, float bb) {
    this->aa=aa;
    this->ab=ab;
    this->ba=ba;
    this->bb=bb;
};

Mat Mat::operator*(Mat& other){
    return Mat((this->aa*other.aa+this->ab*other.ba), (this->aa*other.ab+this->ab*other.bb),
               (this->ba*other.aa+this->bb*other.ba), (this->ba*other.ab+this->bb*other.bb)); 
};

Vec Mat::operator*(Vec& other) {
    return Vec(this->aa*other.x+this->ab*other.y, 
            this->ba*other.x+this->bb*other.y);
};

Mat Mat::operator*(float other){
    return Mat(this->aa*other, this->ab*other, this->ba*other, this->bb*other); 
};

void Mat::operator*=(Mat& other) {
    Mat n=*(this)*other;    
    this->aa=n.aa;
    this->ab=n.ab;
    this->ba=n.ba;
    this->bb=n.bb;
};

void Mat::operator*=(float other) {
    this->aa*=other;
    this->ab*=other;
    this->ba*=other;
    this->bb*=other;
};

Mat Mat::operator/(float other) {
    return Mat(this->aa/other, this->ab/other, this->ba/other, this->bb/other);
};

void Mat::operator/=(float other) {
    this->aa/=other;
    this->ab/=other;
    this->ba/=other;
    this->bb/=other;
};

Mat Mat::operator+(Mat& other) {
    return Mat(this->aa+other.aa, this->ab+other.ab, 
            this->ba+other.ba, this->bb+other.bb);
};

void Mat::operator+=(Mat& other) {
    this->aa+=other.aa;
    this->ab+=other.ab;
    this->ba+=other.ba;
    this->bb+=other.bb;
};

Mat Mat::operator-(Mat& other) {
    return Mat(this->aa-other.aa, this->ab-other.ab,
            this->ba-other.ba, this->bb-other.bb);
};

void Mat::operator-=(Mat& other) {
    this->aa-=other.aa;
    this->ab-=other.ab;
    this->ba-=other.ba;
    this->bb-=other.bb;
};
