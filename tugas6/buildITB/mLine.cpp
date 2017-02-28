#include "line.h"
#include <iostream>

using namespace std;

int main() {
	bufferMem buf;
	buf.startBuffer();

	color blackColor(0,0,0);
	buf.printBackground(blackColor);

	color c(123,23,12);
	line n;
	Point* PointList = (Point*) malloc(sizeof(Point)*7);
	int scala = 10;
	//assign global variables with the assigned parameters
	int	planeX = 234;
	int planeY = 432;

	PointList[0].SetAbsis(planeX);
	PointList[0].SetOrdinat(planeY);

	PointList[1].SetAbsis(planeX - 7 * scala);
	planeX -= 7 * scala;
	PointList[1].SetOrdinat(planeY - 4 * scala);
	planeY -= 4 * scala;

	PointList[2].SetAbsis(planeX - 19 * scala);
	planeX -= 19 * scala;
	PointList[2].SetOrdinat(planeY);

	n.drawPolygon(3, PointList, c, 5);
	free(PointList);


	buf.closeBuffer();
	return 0;
}