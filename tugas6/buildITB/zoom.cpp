#include "bufferMem.h"
#include "color.h"
#include "zoom.h"
#include <stdlib.h>

bufferMem bufer;
zoom::~zoom() {}
zoom::zoom() {}

void zoom::tesZoom() {
	bufer.startBuffer();

	color yellowColor(255,255,10);
	color blueColor(0,0,255);
	color greenColor(0,255,0);
	color pinkColor(200,120,255);
	color redColor(255,0,0);
	color blackColor(0,0,0);
	color whiteColor(255,255,255);
	
	bufer.printBackground(blackColor);
	printf("oke\n");
	bufer.printSquare(62, 199, 99, whiteColor);
	bufer.printSquareZoom(62, 199, 99, yellowColor, 2);
	bufer.printSquare (20, 200, 100, yellowColor);
	bufer.printSquare (20, 220, 100, blueColor);
	bufer.printSquare (20, 240, 100, greenColor);
	bufer.printSquare (20, 200, 120, pinkColor);
	bufer.printSquare (20, 220, 120, redColor);
	color get;
	get = bufer.get_pixel(220,120);
	usleep(2000000);
	zoomInOut(199,99, 60, 60, 0.5);
	bufer.closeBuffer();
}

// loc_x, loc_y adalah posisi kiri atas dari lokasi yang ingin di zoom
// edge_x, edge_y adalah panjang dan lebar dari lokasi yang ingin di zoom
// multiplier adalah multipler dari panjang dan lebar, gambar akan diperbesar sebanyak multiplier^2 kali
void zoom::zoomInOut(int loc_x, int loc_y, int edge_x, int edge_y, double multiplier) {
	color yellowColor(255,255,10);
	const int x = edge_x;
	const int y = edge_y;
	color **internalBuffer = new color*[y];
	for (int i = 0; i < y; ++i)
	 internalBuffer[i] = new color[x];
	for(int i=0; i<edge_x; i++) {
		for(int j=0; j<edge_y; j++) {
			//printf("%d %d\n", i-loc_x, j-loc_y);
			internalBuffer[i][j] = bufer.get_pixel(loc_x + i/multiplier, loc_y + j/multiplier);
		}
	}
	for(int i=0; i<loc_x+edge_x; i++) {
		for(int j=loc_y; j<loc_y+edge_y; j++) {
			if (i <400 && j<400) {
				bufer.put_pixel(i, j, internalBuffer[i-loc_x-100][j-loc_y]);
			}
		}
	}
}
