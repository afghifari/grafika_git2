#ifndef FLOOD_H
#define FLOOD_H

#include "plane.h"


color get_pixel (int loc_x, int loc_y);

/**
* boundary_fill berfungsi untuk mewarnai objek dari dalam. seperti flood fill
*	x : kordinat x
*	y : kordinat y
*	new_color 	: warna buat fill objek
*	f_color		: warna garis objek (polygon)
*	b_color		: warna sebelum diwarnai. warna backgroundnya.
*/
void boundary_fill (int x, int y, color new_color, color f_color, color b_color);
#endif