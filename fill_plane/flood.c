#include "plane.c"



// color get_pixel(loc_x, loc_y){
//     color initial;

//     long int location;
//     int i,j;
//     location = (i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j+vinfo.yoffset) * finfo.line_length;
//     if (fbp + location) {
//         if (((loc_x)>=0) && ((loc_x + 1)<vinfo.xres) && ((loc_y)>=0) && ((loc_y + 1)<vinfo.yres)) {
//             printf("tes1 %d\n", );
//             initial.R = (*(fbp + location));
//             printf("tes2\n");
//             initial.G = (*(fbp + location + 1));
//             printf("tes2.2\n");
//             initial.B = (*(fbp + location + 2));
//             printf("tes3\n");
//         } else {
//             printf("cek2\n");
//             initial.R = 0;
//             initial.G = 0;
//             initial.B = 0;
//         }
//     } else {
//             printf("cek2.1\n");
//             initial.R = 0;
//             initial.G = 0;
//             initial.B = 0;
//     }

//     return initial;
// }

color get_pixel (int loc_x, int loc_y) {
	color initial;

    long int location;
    int i,j;
    if (((loc_x)>=0) && ((loc_x + 1)<vinfo.xres) && ((loc_y)>=0) && ((loc_y + 1)<vinfo.yres)) {
		for (i = loc_x; i < (loc_x + 1); i++) {
			for (j = loc_y; j < (loc_y + 1); j++) {
				location = (i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j+vinfo.yoffset) * finfo.line_length;
				// printf("ss1 %d\n", (*(fbp + location)));
				if (fbp + location) { //check for segmentation fault
					initial.B = (*(fbp + location));
		            
		            initial.G = (*(fbp + location + 1));
		            
		            initial.R = (*(fbp + location + 2));
					// if (vinfo.bits_per_pixel == 32) {
					// 	*(fbp + location) = C.B;            //Blue
					// 	*(fbp + location + 1) = C.G;        //Green
					// 	*(fbp + location + 2) = C.R;        //Red
					// 	*(fbp + location + 3) = 0;          //Transparancy
					// } else  { //assume 16bpp
					// 	int r = C.R;     //Red
					// 	int g = C.G;     //Green
					// 	int b = C.B;     //Blue
						
					// 	unsigned short int t = r<<11 | g << 5 | b;
					// 	*((unsigned short int*)(fbp + location)) = t;
					// }
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

void boundary_fill (int x, int y, color new_color, color f_color, color b_color) {

	color current;
	if ((x >= 0) && (x < vinfo.xres - 2) && (y >= 0) && (y < vinfo.yres - 2)) {
		current = get_pixel(x, y);
		// printf("1. current %d %d %d\n", current.R, current.G, current.B );
		// printf("2. f_color %d %d %d\n", f_color.R, f_color.G, f_color.B );
		// printf("3. b_color %d %d %d\n", b_color.R, b_color.G, b_color.B );
		// printf("3. new_color %d %d %d\n", new_color.R, new_color.G, new_color.B );
		// printf("------------------\n");
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