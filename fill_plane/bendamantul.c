#include "bendamantul.h"

void buildBenda(int x, int y, color c) 
{
  	//making list of points
	Point* PointList = (Point*) malloc(sizeof(Point)*9);

  	// body
	PointList[0].x = x;
	PointList[0].y = y + 40;

	PointList[1].x = x - 70;
	PointList[1].y = y - 80;

	drawPolyline(2, PointList, c, 2);

	PointList[1].x = x + 70;
	PointList[1].y = y - 80;

	drawPolyline(2, PointList, c, 2);
	// drawPolygon(3, PointList, c, 2);

	PointList[1].x = x;
	PointList[1].y = y - 80;

	drawPolyline(2, PointList, c, 2);

	drawCircleHalf(70, PointList[1], 2, c);

	PointList[0].x = x - 70;
	PointList[0].y = y - 80;

	PointList[1].x = x + 70;
	PointList[1].y = y - 80;	

	drawPolyline(2, PointList, c, 2);

	Point Phead;
	Phead.x = x;
	Phead.y = y;
	drawCircle(20, Phead, 2, c);

  	// body

	// PointList[1].x = x + 10;
	// PointList[1].y = y + 30;

	// PointList[2].x = x + 10;
	// PointList[2].y = y + 70;

	// PointList[3].x = x - 10;
	// PointList[3].y = y + 70;

	// PointList[4].x = x - 10;
	// PointList[4].y = y + 30;

	// drawPolygon(4, PointList + 1, c, 2);

  	// fin right
	// PointList[0].x = x + 10;
	// PointList[0].y = y + 50;
  
	// PointList[1].x = x + 10;
	// PointList[1].y = y + 70;
  
	// PointList[2].x = x + 20;
	// PointList[2].y = y + 70;
	// // drawPolygon(3, PointList, c, 2);
  
 //  	// fin left
	// PointList[0].x = x - 10;
	// PointList[0].y = y + 50;
  
	// PointList[1].x = x - 10;
	// PointList[1].y = y + 70;
  
	// PointList[2].x = x - 20;
	// PointList[2].y = y + 70;
	// drawPolygon(3, PointList, c, 2);
	  
	free(PointList);
}

void fillBenda(int x, int y, color fin_color, color warhead_color, color body_color)
{

}