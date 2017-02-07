#ifndef CANNON_H
#define CANNON_H

#include <stdlib.h>
#include <stdio.h>
#include "line.h"
#include "rocket.h"

extern int cannonX;
extern int cannonY;
extern int destProjectile;

void buildHalfCannon(Point P, color C);

void buildCannon(int x, int y, color c);

void shootCannon(int x, int y, color c);

#endif
