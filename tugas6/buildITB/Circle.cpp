#include "Circle.h"

Circle::Circle(const Point& coor, int radius, int borderSize, color c) : coordinate(coor){
  this->radius = radius;
  this->borderSize = borderSize;
  myColor = c;
}

void Circle::setCoordinate(const Point& coor){
  coordinate = coor;
}

void Circle::draw(bufferMem& buf){
  int d, p, q;

  p = 0;
  q = radius;
  d = 3 - 2*radius;

  plot8pixel(buf, coordinate, p, q, borderSize, myColor);

  while (p < q) {
      p++;
      if (d<0) {
          d = d + 4*p + 6;
      }
      else {
          q--;
          d = d + 4*(p-q) + 10;
      }

      plot8pixel(buf, coordinate, p, q, borderSize, myColor);
  }
}


void Circle::plot8pixel (bufferMem& buf, Point P, int p, int q, int W, color C){
  buf.printSquare(W, P.GetAbsis()+p, P.GetOrdinat()+q, C);
  buf.printSquare(W, P.GetAbsis()-p, P.GetOrdinat()+q, C);
  buf.printSquare(W, P.GetAbsis()+p, P.GetOrdinat()-q, C);
  buf.printSquare(W, P.GetAbsis()-p, P.GetOrdinat()-q, C);

  buf.printSquare(W, P.GetAbsis()+q, P.GetOrdinat()+p, C);
  buf.printSquare(W, P.GetAbsis()-q, P.GetOrdinat()+p, C);
  buf.printSquare(W, P.GetAbsis()+q, P.GetOrdinat()-p, C);
  buf.printSquare(W, P.GetAbsis()-q, P.GetOrdinat()-p, C);
}

 
 