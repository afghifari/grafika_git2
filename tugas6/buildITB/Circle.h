#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "color.h"
#include "bufferMem.h"
/*
radius	: jari-jari lingkaran
P	: titik asal lingkaran
*/

class Circle {
public:
  Circle(const Point& coor, int radius, int borderSize, color c);
  void setCoordinate(const Point& coor);
  void draw(bufferMem& buf);
  
private:
  void plot8pixel(bufferMem& buf, Point P, int p, int q, int W, color C);

  Point coordinate;
  int radius;
  int borderSize;
  color myColor;
};

#endif