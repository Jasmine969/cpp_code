#ifndef _TEST_H_
#define _TEST_H_
#include <iostream>
#include <ostream>
#include <cmath>
#include <fstream>

namespace VECTOR
{
  class Vector;
  std::ostream &operator<<(std::ostream &os, const Vector &b);
  class Vector
  {
  public:
    enum Mode
    {
      RECT,
      POL
    };

  private:
    double x, y;
    double ang, mag;
    Mode mode; // RECT or POL
    void set_mag();
    void set_ang();
    void set_x();
    void set_y();

  public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    ~Vector();
    double xval() const { return x; }
    double yval() const { return y; }
    double angval() const { return ang; }
    double magval() const { return mag; }
    void polar_mode(); // set mode to POL
    void rect_mode();  // set mode to RECT
    void reset(double n1, double n2, Mode form);
    // operator overloading
    Vector operator+(const Vector &b) const;
    Vector operator-(const Vector &b) const;
    Vector operator-() const;
    Vector operator*(double n) const;
    // friends
    friend Vector operator*(double n, const Vector &b);
    friend std::ostream &operator<<(std::ostream &os, const Vector &b);
  };
  const double Rad_to_Deg = 45.0 / atan(1.0);
}
VECTOR::Vector::Vector()
{
  x = 0.0;
  y = 0.0;
  ang = 0.0;
  mag = 0.0;
  mode = RECT;
}
VECTOR::Vector::Vector(double n1, double n2, Mode form)
{
  mode = form;
  if (form == RECT)
  {
    x = n1;
    y = n2;
    set_mag();
    set_ang();
  }
  else if (form == POL)
  {
    mag = n1;
    ang = n2;
    set_x();
    set_y();
  }
  else
  {
    std::cout << "Incorrect 3rd argument to Vector()--";
    std::cout << "Vector set to 0. \n";
    x = y = mag = ang = 0.0;
    mode = RECT;
  }
}
void VECTOR::Vector::set_mag() { mag = sqrt(x * x + y * y); }
void VECTOR::Vector::set_ang()
{
  if (x == 0.0 && y == 0.0)
  {
    ang = 0.0;
  }
  else
  {
    ang = atan2(y, x);
  }
  ang = sqrt(x * x + y * y);
}
void VECTOR::Vector::set_x() { x = cos(ang); }
void VECTOR::Vector::set_y() { y = sin(ang); }
void VECTOR::Vector::polar_mode() { mode = POL; } // set mode to POL
void VECTOR::Vector::rect_mode() { mode = RECT; } // set mode to RECT
void VECTOR::Vector::reset(double n1, double n2, Mode form)
{
  if (form == RECT)
  {
    x = n1;
    y = n2;
    set_mag();
    set_ang();
  }
  else if (form == POL)
  {
    mag = n1;
    ang = n2;
    set_x();
    set_y();
  }
  else
  {
    std::cout << "Incorrect 3rd argument to Vector()--";
    std::cout << "Vector set to 0. \n";
    x = y = mag = ang = 0.0;
    mode = RECT;
  }
}
VECTOR::Vector VECTOR::Vector::operator+(const Vector &b) const
{
  return VECTOR::Vector(this->x + b.x, this->y + b.y);
}
VECTOR::Vector VECTOR::Vector::operator-(const Vector &b) const
{
  return VECTOR::Vector(this->x - b.x, this->y - b.y);
}
VECTOR::Vector VECTOR::Vector::operator-() const
{
  return VECTOR::Vector(-this->x, -this->y); // reverse the sign
}
VECTOR::Vector VECTOR::Vector::operator*(double n) const
{
  return VECTOR::Vector(this->x * n, this->y * n);
}
// friends
VECTOR::Vector operator*(double n, const VECTOR::Vector &b)
{
  return b * n; //==b.operator*(n)
}
std::ostream &VECTOR::operator<<(std::ostream &os, const VECTOR::Vector &t)
{
  return os;
}
#endif