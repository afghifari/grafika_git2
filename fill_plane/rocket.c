#include "rocket.h"

void buildRocket(int x, int y, color c){
  	//making list of points
	Point* PointList = (Point*) malloc(sizeof(Point)*9);

  // body
	PointList[0].x = x;
	PointList[0].y = y;

	PointList[1].x = x + 10;
	PointList[1].y = y + 30;

	PointList[2].x = x - 10;
	PointList[2].y = y + 30;

	drawPolygon(3, PointList, c, 2);

  // body
	PointList[1].x = x + 10;
	PointList[1].y = y + 30;

	PointList[2].x = x + 10;
	PointList[2].y = y + 70;

	PointList[3].x = x - 10;
	PointList[3].y = y + 70;

	PointList[4].x = x - 10;
	PointList[4].y = y + 30;

	drawPolygon(4, PointList + 1, c, 2);

  // fin right
	PointList[0].x = x + 10;
	PointList[0].y = y + 50;
  
	PointList[1].x = x + 10;
	PointList[1].y = y + 70;
  
	PointList[2].x = x + 20;
	PointList[2].y = y + 70;
	drawPolygon(3, PointList, c, 2);
  
  // fin left
	PointList[0].x = x - 10;
	PointList[0].y = y + 50;
  
	PointList[1].x = x - 10;
	PointList[1].y = y + 70;
  
	PointList[2].x = x - 20;
	PointList[2].y = y + 70;
	drawPolygon(3, PointList, c, 2);
  
  free(PointList);
}

void fillRocket(int x, int y, color fin_color, color warhead_color, color body_color){
}
