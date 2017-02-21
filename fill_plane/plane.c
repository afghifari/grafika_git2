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


void buildPlaneToRight(int x, int y, color c, int scala) {
	//making list of points
	Point* PointList = (Point*) malloc(sizeof(Point)*7);

	//assign global variables with the assigned parameters
	planeX = x;
	planeY = y;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX - 7 * scala;
	planeX -= 7 * scala;
	PointList[1].y = planeY - 4 * scala;
	planeY -= 4 * scala;

	PointList[2].x = planeX - 19 * scala;
	planeX -= 19 * scala;
	PointList[2].y = planeY;

	PointList[3].x = planeX - 6 * scala;
	planeX -= 6 * scala;
	PointList[3].y = planeY - 3 * scala;
	planeY -= 3 * scala;

	PointList[4].x = planeX - 2 * scala;
	planeX -= 2 * scala;
	PointList[4].y = planeY;

	PointList[5].x = planeX + 5 * scala;
	PointList[5].y = planeY + 8 * scala;
	planeY += 8 * scala;

	drawPolygon(6, PointList, c, 5);

	planeX = x - 10 * scala;
	planeY = y - 2 * scala;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX - 10 * scala;
	planeX -= 10 * scala;
	PointList[1].y = planeY;

	PointList[2].x = planeX - 10 * scala;
	planeX -= 10 * scala;
	PointList[2].y = planeY + 4 * scala;
	planeY += 4 * scala;

	PointList[3].x = planeX + 5 * scala;
	planeX += 5 * scala;
	PointList[3].y = planeY;

	drawPolygon(4, PointList, c, 5);

	planeX = x - 10 * scala;
	planeY = y - 4 * scala;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX - 10 * scala;
	planeX -= 10 * scala;
	PointList[1].y = planeY;

	PointList[2].x = planeX - 10 * scala;
	planeX -= 10 * scala;
	PointList[2].y = planeY - 4 * scala;
	planeY -= 4 * scala;

	PointList[3].x = planeX + 5 * scala;
	planeX += 5 * scala;
	PointList[3].y = planeY;

	drawPolygon(4, PointList, c, 2);
  	free(PointList);
}

void buildPlaneToLeft(int x, int y, color c, int scala){
	//making list of points
	Point* PointList = (Point*) malloc(sizeof(Point)*7);

	//assign global variables with the assigned parameters
	planeX = x;
	planeY = y;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX + 7 * scala;
	planeX += 7 * scala;
	PointList[1].y = planeY - 4 * scala;
	planeY -= 4 * scala;

	PointList[2].x = planeX + 19 * scala;
	planeX += 19 * scala;
	PointList[2].y = planeY;

	PointList[3].x = planeX + 6 * scala;
	planeX += 6 * scala;
	PointList[3].y = planeY - 3 * scala;
	planeY -= 3 * scala;

	PointList[4].x = planeX + 2 * scala;
	planeX += 2 * scala;
	PointList[4].y = planeY;

	PointList[5].x = planeX - 5 * scala;
	PointList[5].y = planeY + 8 * scala;
	planeY += 8 * scala;

	drawPolygon(6, PointList, c, 5);

	planeX = x + 10 * scala;
	planeY = y - 2 * scala;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX + 10 * scala;
	planeX += 10 * scala;
	PointList[1].y = planeY;

	PointList[2].x = planeX + 10 * scala;
	planeX += 10 * scala;
	PointList[2].y = planeY + 4 * scala;
	planeY += 4 * scala;

	PointList[3].x = planeX - 5 * scala;
	planeX -= 5 * scala;
	PointList[3].y = planeY;

	drawPolygon(4, PointList, c, 5);

	planeX = x + 10 * scala;
	planeY = y - 4 * scala;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX + 10 * scala;
	planeX += 10 * scala;
	PointList[1].y = planeY;

	PointList[2].x = planeX + 10 * scala;
	planeX += 10 * scala;
	PointList[2].y = planeY - 4 * scala;
	planeY -= 4 * scala;

	PointList[3].x = planeX - 5 * scala;
	planeX -= 5 * scala;
	PointList[3].y = planeY;

	drawPolygon(4, PointList, c, 5);
  free(PointList);


}

void fill_planeToLeft(int indeksIPlane, int indeksJPlane, int scala, color new_color, color edge_color, color old_color) {
	//body ekor
	boundary_fill (indeksIPlane + 7 * scala * 3, indeksJPlane - 2 * scala, new_color,  edge_color, old_color);
	//body moncong
	boundary_fill (indeksIPlane + 7 * scala, indeksJPlane - 2 * scala, new_color,  edge_color, old_color);
	//sayap kiri dalam
	boundary_fill (indeksIPlane + 18 * scala, indeksJPlane - 1 * scala, new_color,  edge_color, old_color);
	//sayap kanan
	boundary_fill (indeksIPlane + 18 * scala, indeksJPlane - 6 * scala + scala, new_color,  edge_color, old_color);
	//sayap kanan luar
	boundary_fill (indeksIPlane + 25 * scala + scala , indeksJPlane + 1 * scala + scala - 2, new_color,  edge_color, old_color);
}

void fill_planeToRight(int indeksIPlane, int indeksJPlane, int scala, color new_color, color edge_color, color old_color) {
	// body moncong
	boundary_fill (indeksIPlane - 7 * scala, indeksJPlane - 2 * scala, new_color,  edge_color, old_color);
	//body ekor
	boundary_fill (indeksIPlane - 7 * scala * 3, indeksJPlane - 2 * scala, new_color,  edge_color, old_color);
	
	boundary_fill (indeksIPlane - 18 * scala, indeksJPlane - 1 * scala, new_color,  edge_color, old_color);
	boundary_fill (indeksIPlane - 18 * scala, indeksJPlane - 6 * scala + scala, new_color,  edge_color, old_color);
	boundary_fill (indeksIPlane - 25 * scala - scala, indeksJPlane + 1 * scala + scala - 2, new_color,  edge_color, old_color);
}
