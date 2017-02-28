#include "bufferMem.h"

using namespace std;

int main() {
	bufferMem buf;

	color yellowColor(255,255,10);
	color blackColor(0,0,0);

	buf.printBackground(blackColor);
	return 0;
}