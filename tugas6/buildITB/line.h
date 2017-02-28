#ifndef LINE_H
#define LINE_H

#include "bufferMem.h"

class line {
	public :

		void swap (int *a, int *b);
		void swapPoint (Point *P1, Point *P2);
		void plotSlopPositiveLine (Point P1, Point P2, color C, int W);
		void plotSlopNegativeLine (Point P1, Point P2, color C, int W);
		void plotVerticalLine (Point P1, Point P2, color C, int W);
		void drawBresenhamLine (Point P1, Point P2, color C, int W);
		void drawPolyline (int n, Point *P, color C, int W);
		void drawPolygon (int n, Point *P, color C, int W);
		void drawPolygonZoom (int n, Point *P, color C, int W, double multiplier);
		/*
		initialPoint : explosion location in the screen
		scaleFactor : size of the explosion
		*P isi dengan array explosionPoint
		*/
		void drawExplosion (Point initialPoint);
		void plot4pixel (Point P, int p, int q, int W, color C);


		/*
		radius	: jari-jari lingkaran
		P	: titik asal lingkaran
		*/
		void drawCircleHalf (int radius, Point P, int W, color C);

	private :	
		bufferMem buf;

};

#endif
