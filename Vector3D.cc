#include <iostream>
#include <math.h>
#include "Vector3D.h"
using namespace std;


int Vector3D::counter_=0;

//constructors
Vector3D::Vector3D(){
    counter_++;
  }

Vector3D::Vector3D(const double& x, const double& y, const double& z){
    x_=x;
    y_=y;
    z_=z;
    counter_++;
  }


//destructors    
Vector3D::~Vector3D(){counter_--;}

//getters
double Vector3D::getX() const{return x_;}
double Vector3D::getY() const{return y_;}
double Vector3D::getZ() const{return z_;}

//setters
void Vector3D::setCoor(const double& x, const double& y, const double& z){
  x_=x;
  y_=y;
  z_=z;
}

//member functions
double Vector3D::r() const{return x_*x_+y_*y_+z_*z_;}
double Vector3D::theta() const{
  if(( x_*x_+y_*y_+z_*z_)!=0){return acos(z_/( x_*x_+y_*y_+z_*z_));}
  else{return 0;}
}
double Vector3D::phi() const{
  if(x_==0 && y_==0){return 0;}
  else{return atan(y_/x_);}
}

double Vector3D::ScalarProd(const Vector3D& v1) const{
  return(v1.x_*x_+v1.y_*y_+v1.z_*z_);
}

Vector3D Vector3D::VectorProd(const Vector3D& rhs) const{
  double x=(y_*rhs.z_-rhs.y_*z_);
  double y=(z_*rhs.x_-rhs.z_*x_);
  double z=(x_*rhs.y_-rhs.x_*y_);
  return(Vector3D(x,y,z));
}


double Vector3D::angle(const Vector3D& v1) const{
  Vector3D v=Vector3D(x_,y_,z_);
  return acos(v.ScalarProd(v1)/(sqrt(v.ScalarProd(v))*sqrt(v1.ScalarProd(v1))));
}



void Vector3D::printSph(){
  cout<<"Vector (spherical): "<<"("<<r()<<", "<<theta()<<", "<<phi()<<")"<<endl;
}

//overloaded operators
Vector3D Vector3D::operator+(const Vector3D& rhs) const{
  double x=x_+rhs.x_;
  double y=y_+rhs.y_;
  double z=z_+rhs.z_;
  return Vector3D(x, y,z);
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const{
  double x=x_-rhs.x_;
  double y=y_-rhs.y_;
  double z=z_-rhs.z_;
  return Vector3D(x, y,z);
}

Vector3D Vector3D::operator=(const Vector3D& rhs) const{
  double x=rhs.x_;
  double y=rhs.y_;
  double z=rhs.z_;
  return *this;
}


Vector3D Vector3D::operator*(const double& lhs) const{
  return Vector3D(x_*lhs, y_*lhs, z_*lhs);
  }

Vector3D Vector3D::operator/(const double& lhs) const{
  if(lhs!=0){return Vector3D(x_/lhs, y_/lhs, z_/lhs);}
  else{
    cout<<"NON PUOI DIVIDERE PER 0!"<<endl;
    return Vector3D(0, 0, 0);}
}


//global functions
ostream& operator<<(ostream& os, const Vector3D& vec){
  os<<"Vector: "<<"("<<vec.x_<<", "<<vec.y_<<", "<<vec.z_<<")";
  return os;
}

Vector3D operator*(const double& lhs, const Vector3D& rhs){
  return Vector3D(lhs*rhs.getX(), lhs*rhs.getY(), lhs*rhs.getZ());
}
