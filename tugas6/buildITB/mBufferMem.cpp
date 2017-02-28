#include "bufferMem.h"
#include "Circle.h"
#include "Point.h"
#include "line.h"
#include <iostream>

using namespace std;

int main() {
	bufferMem buf;
	buf.startBuffer();

	color yellowColor(255,255,10);
	color blackColor(0,0,0);
	buf.printBackground(blackColor);
	buf.printSquare (20, 234, 123, yellowColor);
	Point myPoint(100,100);
	Circle circleFactory(myPoint, 20, 2, yellowColor);
	circleFactory.draw(buf);
	circleFactory.zoom(buf, 2);

	Point P[4];
	P[0] = Point(313, 35);
	P[1] = Point(313, 41);
	P[2] = Point(317, 35);
	P[3] = Point(317, 41);
	//P[4] = Point(300, 400);
	line LineFactory;
	
	LineFactory.drawPolygon(4, P, yellowColor, 1);
	LineFactory.drawPolygonZoom(4, P, yellowColor, 1, 2);
	buf.closeBuffer();
	return 0;
}
