#include <iostream>
using namespace std;

class Vector3D{
 public:
  //constructors and destructors
  Vector3D();
  Vector3D(const double& x, const double& y, const double& z);
  ~Vector3D();

  //getters
  double getX() const;
  double getY() const;
  double getZ() const;

  //setters
  void setCoor(const double& x, const double& y, const double& z);

  //member functions
  double r() const;
  double theta() const;
  double phi() const;
  double ScalarProd(const Vector3D& v1) const;
  Vector3D VectorProd(const Vector3D& rhs) const;
  double angle(const Vector3D& v1) const;
  void printSph();

  //overloaded operators
  Vector3D operator+(const Vector3D& rhs) const;
  Vector3D operator-(const Vector3D& rhs) const;
  Vector3D operator=(const Vector3D& rhs) const;
  Vector3D operator*(const double& lhs) const;
  Vector3D operator/(const double& lhs) const;
  

  //global functions
  friend ostream& operator<<(ostream& os, const Vector3D& vec);
  friend Vector3D operator*(const double& lhs, const Vector3D& rhs);
  
  static int counter_;

 private:
  double x_, y_, z_, r_, theta_, phi_;
};
