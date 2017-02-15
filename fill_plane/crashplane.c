#include "crashplane.h"


void buildCrashPlane(int x, int y, color c) {
	//making list of points
	Point* PointList = (Point*) malloc(sizeof(Point)*7);

	//assign global variables with the assigned parameters
	planeX = x;
	planeY = y;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX + 10;
	planeX += 100;
	PointList[1].y = planeY - 25;
	planeY -= 25;

	PointList[2].x = planeX + 90;
	planeX += 90;
	PointList[2].y = planeY;

	PointList[3].x = planeX + 90;
	planeX += 90;
	PointList[3].y = planeY - 55;
	planeY -= 55;

	PointList[4].x = planeX + 100;
	planeX += 100;
	PointList[4].y = planeY;

	PointList[5].x = planeX - 10;
	PointList[5].y = planeY + 120;
	planeY += 120;

	drawPolygon(6, PointList, c, 5);

	free(PointList);
}