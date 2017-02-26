#ifndef PRINT_H
#define PRINT_H

#include "Point.h"
#include "color.h"

class bufferMem {
	public :
		bufferMem();
		~bufferMem();

		printBackground();
		void printSquare (int edge, int loc_x, int loc_y, color C);

	private :
		Point H;


};
#endif