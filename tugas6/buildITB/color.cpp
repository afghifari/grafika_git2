#include "color.h"

color::color() {
	R = 0;
	G = 0;
	B = 0;
}

color::color(int r, int g, int b) {
	R = r;
	G = g;
	B = b;
}

color::~color() {
	
}

color::color(color &c) {
	R = c.R;
	G = c.G;
	B = c.B;
}

color& color::operator= (color &c) {
	R = c.R;
	G = c.G;
	B = c.B;

	return *this;	
}

void color::setColor(int r, int g, int b) {
	R = r;
	G = g;
	B = b;
}

color color::getColor() {
	color c;
	return c;
}

int color::getR() {
	return R;
}

int color::getG() {
	return G;
}

int color::getB() {
	return B;
}

