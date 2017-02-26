#include "flood.h"

color get_pixel (int loc_x, int loc_y) {
	color initial;

    long int location;
    int i,j;
    if (((loc_x)>=0) && ((loc_x + 1)<vinfo.xres) && ((loc_y)>=0) && ((loc_y + 1)<vinfo.yres)) {
		for (i = loc_x; i < (loc_x + 1); i++) {
			for (j = loc_y; j < (loc_y + 1); j++) {
				location = (i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j+vinfo.yoffset) * finfo.line_length;

				if (fbp + location) {  	//check for segmentation fault
					initial.B = (*(fbp + location));
		            initial.G = (*(fbp + location + 1));
		            initial.R = (*(fbp + location + 2));
				} else {
					initial.R = 0;
		            initial.G = 0;
		            initial.B = 0;
				}
			}
		}
	}
	return initial;
}

/**
* boundary_fill berfungsi untuk mewarnai objek dari dalam. seperti flood fill
*	x : kordinat x
*	y : kordinat y
*	new_color 	: warna buat fill objek
*	f_color		: warna garis objek (polygon)
*	b_color		: warna sebelum diwarnai. warna backgroundnya.
*/
void boundary_fill (int x, int y, color new_color, color f_color, color b_color) {

	color current;
	if ((x >= 160) && (x < vinfo.xres - 160) && (y >= 60) && (y < vinfo.yres - 110)) {
		current = get_pixel(x, y);
		if ((current.R != f_color.R) && (current.G != f_color.G) && (current.B != f_color.B)
		     &&
		     (current.R != new_color.R) && (current.G != new_color.G) && (current.B != new_color.B)) {
			printSquare (1, x, y, new_color);
			boundary_fill(x+1, y, new_color, f_color, b_color);
			boundary_fill(x, y+1, new_color, f_color, b_color);
			boundary_fill(x-1, y, new_color, f_color, b_color);
			boundary_fill(x, y-1, new_color, f_color, b_color);

			boundary_fill(x+1, y+1, new_color, f_color, b_color);
			boundary_fill(x-1, y+1, new_color, f_color, b_color);
			boundary_fill(x-1, y-1, new_color, f_color, b_color);
			boundary_fill(x+1, y-1, new_color, f_color, b_color);
		}
	}
}
