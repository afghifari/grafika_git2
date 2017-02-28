#include "bufferMem.h"
#include "Circle.h"
#include "Point.h"
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
	buf.closeBuffer();
	return 0;
}
