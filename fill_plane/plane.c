#include "plane.h"

int planeX;
int planeY;

void buildSquareLine(int x, int y, color c) {
	Point* PointList = (Point*) malloc(sizeof(Point)*4);

	//assign global variables with the assigned parameters
	planeX = x;
	planeY = y;

	PointList[0].x = 150;
	PointList[0].y = vinfo.yres - 100 ;

	PointList[1].x = 150;
	PointList[1].y = 50;

	PointList[2].x = vinfo.xres - 150;
	PointList[2].y = 50;

	PointList[3].x = vinfo.xres - 150;
	PointList[3].y = vinfo.yres - 100 ;

	drawPolygon(4, PointList, c, 5);
	free(PointList);
}


void buildPlaneToRight(int x, int y, color c) {
	//making list of points
	Point* PointList = (Point*) malloc(sizeof(Point)*7);

	//assign global variables with the assigned parameters
	planeX = x;
	planeY = y;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX - 70;
	planeX -= 70;
	PointList[1].y = planeY - 45;
	planeY -= 45;

	PointList[2].x = planeX - 190;
	planeX -= 190;
	PointList[2].y = planeY;

	PointList[3].x = planeX - 60;
	planeX -= 60;
	PointList[3].y = planeY - 35;
	planeY -= 35;

	PointList[4].x = planeX - 20;
	planeX -= 20;
	PointList[4].y = planeY;

	PointList[5].x = planeX + 50;
	PointList[5].y = planeY + 80;
	planeY += 80;

	drawPolygon(6, PointList, c, 5);

	planeX = x - 100;
	planeY = y - 25;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX - 100;
	planeX -= 100;
	PointList[1].y = planeY;

	PointList[2].x = planeX - 100;
	planeX -= 100;
	PointList[2].y = planeY + 45;
	planeY += 45;

	PointList[3].x = planeX + 50;
	planeX += 50;
	PointList[3].y = planeY;

	drawPolygon(4, PointList, c, 5);

	planeX = x - 100;
	planeY = y - 45;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX - 100;
	planeX -= 100;
	PointList[1].y = planeY;

	PointList[2].x = planeX - 100;
	planeX -= 100;
	PointList[2].y = planeY - 45;
	planeY -= 45;

	PointList[3].x = planeX + 50;
	planeX += 50;
	PointList[3].y = planeY;

	drawPolygon(4, PointList, c, 2);
  	free(PointList);
}

void buildPlaneToLeft(int x, int y, color c){
	//making list of points
	Point* PointList = (Point*) malloc(sizeof(Point)*7);

	//assign global variables with the assigned parameters
	planeX = x;
	planeY = y;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX + 70;
	planeX += 70;
	PointList[1].y = planeY - 45;
	planeY -= 45;

	PointList[2].x = planeX + 190;
	planeX += 190;
	PointList[2].y = planeY;

	PointList[3].x = planeX + 60;
	planeX += 60;
	PointList[3].y = planeY - 35;
	planeY -= 35;

	PointList[4].x = planeX + 20;
	planeX += 20;
	PointList[4].y = planeY;

	PointList[5].x = planeX - 50;
	PointList[5].y = planeY + 80;
	planeY += 80;

	drawPolygon(6, PointList, c, 5);

	planeX = x + 100;
	planeY = y - 25;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX + 100;
	planeX += 100;
	PointList[1].y = planeY;

	PointList[2].x = planeX + 100;
	planeX += 100;
	PointList[2].y = planeY + 45;
	planeY += 45;

	PointList[3].x = planeX - 50;
	planeX -= 50;
	PointList[3].y = planeY;

	drawPolygon(4, PointList, c, 5);

	planeX = x + 100;
	planeY = y - 45;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX + 100;
	planeX += 100;
	PointList[1].y = planeY;

	PointList[2].x = planeX + 100;
	planeX += 100;
	PointList[2].y = planeY - 45;
	planeY -= 45;

	PointList[3].x = planeX - 50;
	planeX -= 50;
	PointList[3].y = planeY;

	drawPolygon(4, PointList, c, 5);
  free(PointList);
}

void fill_planeToLeft(int indeksIPlane, int indeksJPlane, color new_color, color edge_color, color old_color) {
	boundary_fill (indeksIPlane + 74, indeksJPlane - 20, new_color,  edge_color, old_color);
	boundary_fill (indeksIPlane + 180, indeksJPlane - 10, new_color,  edge_color, old_color);
	boundary_fill (indeksIPlane + 180, indeksJPlane - 60, new_color,  edge_color, old_color);
	boundary_fill (indeksIPlane + 250, indeksJPlane + 10, new_color,  edge_color, old_color);
}

void fill_planeToRight(int indeksIPlane, int indeksJPlane, color new_color, color edge_color, color old_color) {
	boundary_fill (indeksIPlane - 74, indeksJPlane - 20, new_color,  edge_color, old_color);
	boundary_fill (indeksIPlane - 180, indeksJPlane - 10, new_color,  edge_color, old_color);
	boundary_fill (indeksIPlane - 180, indeksJPlane - 60, new_color,  edge_color, old_color);
	boundary_fill (indeksIPlane - 250, indeksJPlane + 10, new_color,  edge_color, old_color);
}
