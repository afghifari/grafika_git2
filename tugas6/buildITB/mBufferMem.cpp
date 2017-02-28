#include "bufferMem.h"
#include <iostream>

using namespace std;

int main() {
	bufferMem buf;
	buf.startBuffer();

	color yellowColor(255,255,10);
	color blackColor(0,0,0);

	buf.printBackground(blackColor);
	buf.printSquare (20, 234, 123, yellowColor);
	buf.closeBuffer();
	return 0;
}