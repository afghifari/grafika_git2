#ifndef PROPELLER_H
#define PROPELLER_H

#include <stdlib.h>
#include <stdio.h>
#include "color.h"
#include "point.h"
#include "square.h"
#include <math.h>

void copyRotate(int cx, int cy, int sx, int sy, int width, int height, float angle);
void buildBlade(int x, int y, color line_color, color fill_color, color background_color);

void buildFourBlade(int cx, int cy, color line_color, color fill_color, color background_color, float angle);
void cleanFourBlade( int x, int y, color background_color);

#endif
