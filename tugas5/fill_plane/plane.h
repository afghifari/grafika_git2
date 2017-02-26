#ifndef PLANE_H
#define PLANE_H

#include <stdlib.h>
#include <stdio.h>
#include "cannon.h"

extern int planeX;
extern int planeY;

void buildSquareLine(int leftedgePar, int rightedgePar, int upedgePar, int downedgePar, color c);

void buildPlaneToRight(int x, int y, color c, int scala);

void buildPlaneToLeft(int x, int y, color c, int scala);

void fill_planeToLeft(int indeksIPlane, int indeksJPlane, int scala, color new_color, color edge_color, color old_color);

void fill_planeToRight(int indeksIPlane, int indeksJPlane, int scala, color new_color, color edge_color, color old_color);

#endif
