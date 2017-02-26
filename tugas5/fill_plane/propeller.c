#include "propeller.h"

void buildBlade(int x, int y, color line_color, color fill_color, color background_color){
  Point* PointList = (Point*) malloc(sizeof(Point)*4);

  PointList[0].x = x;
  PointList[0].y = y;

  PointList[1].x = x + 20;
  PointList[1].y = y + 5;

  PointList[2].x = x + 40;
  PointList[2].y = y;

  drawPolygon(3, PointList, line_color, 2);
  // fill disini
}

// center of rotation cx, cy
// start of iterator sx, sy
// width and height
// rotation angle in radian

void copyRotate(int cx, int cy, int sx, int sy, int width, int height, float angle){
  float s = sin(angle);
  float c = cos(angle);
  int x,y;

  for( x = sx; x < sx + width; ++ x ){
    for( y = sy; y < sy + height; ++ y ){
      int rx = x - cx;
      int ry = y - cy;
      int nx = cx + rx * c - ry * s;
      int ny = cy + rx * s + ry * c;
      copyPixel(nx,ny, x,y);
    }
  }
}

void buildFourBlade(int cx, int cy, color line_color, color fill_color, color background_color, float angle){
  printSquare(80, cx-40, cy-40, background_color);
  buildBlade(cx,cy,line_color,fill_color, background_color);
  copyRotate(cx,cy, cx,cy, 40, 5, 3.14 + angle);
  copyRotate(cx,cy, cx,cy, 40, 5, 1.57 + angle);
  copyRotate(cx,cy, cx,cy, 40, 5, 3.14 + 1.57 + angle);
  copyRotate(cx,cy, cx,cy, 40, 5, angle);
}

void cleanFourBlade( int cx, int cy, color background_color){
  printSquare(90, cx-40, cy-40, background_color);
}
