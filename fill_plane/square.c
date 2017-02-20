#include "square.h"

int fbfd = 0;
struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
long int screensize = 0;
char *fbp = 0;
int displayWidth, displayHeight;

int indeksIPesawat, indeksJPesawat;
int endSign;
int direction;
int hit;

/*
edge    : square size
loc_x   : x coordinate
loc_y   : y coordinate
C       : color struct (Red, Green, Blue)
*/
void printSquare (int edge, int loc_x, int loc_y, color C) {
    long int location;
    int i,j;
    if (((loc_x)>=149) && ((loc_x + edge)<vinfo.xres - 140) && ((loc_y)>=50) && ((loc_y + edge)<vinfo.yres - 80)) {
		for (i = loc_x; i < (loc_x+edge); i++) {
			for (j = loc_y; j < (loc_y+edge); j++) {
				location = (i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j+vinfo.yoffset) * finfo.line_length;
				if (fbp + location) { //check for segmentation fault
					if (vinfo.bits_per_pixel == 32) {
						*(fbp + location) = C.B;            //Blue
						*(fbp + location + 1) = C.G;        //Green
						*(fbp + location + 2) = C.R;        //Red
						*(fbp + location + 3) = 0;          //Transparancy
					} else  { //assume 16bpp
						int r = C.R;     //Red
						int g = C.G;     //Green
						int b = C.B;     //Blue

						unsigned short int t = r<<11 | g << 5 | b;
						*((unsigned short int*)(fbp + location)) = t;
					}
				} else {
					return;
				}
			}
		}
	}
}

void printRect( int loc_x, int loc_y, int h, int w, color C){
  long int location;
  int i,j;
  int edge = 1;
  //if (((loc_x)>=0) && ((loc_x + w)<vinfo.xres) && ((loc_y)>=0) && ((loc_y + h)<vinfo.yres)) {
  if (((loc_x)>=149) && ((loc_x + edge)<vinfo.xres - 140) && ((loc_y)>=50) && ((loc_y + edge)<vinfo.yres - 80)) {
    for (i = loc_x; i < (loc_x+w); i++) {
      for (j = loc_y; j < (loc_y+h); j++) {
        location = (i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j+vinfo.yoffset) * finfo.line_length;
        if (fbp + location) { //check for segmentation fault
          if (vinfo.bits_per_pixel == 32) {
            *(fbp + location) = C.B;            //Blue
            *(fbp + location + 1) = C.G;        //Green
            *(fbp + location + 2) = C.R;        //Red
            *(fbp + location + 3) = 0;          //Transparancy
          } else  { //assume 16bpp
            int r = C.R;     //Red
            int g = C.G;     //Green
            int b = C.B;     //Blue

            unsigned short int t = r<<11 | g << 5 | b;
            *((unsigned short int*)(fbp + location)) = t;
          }
        } else {
          return;
        }
      }
    }
  }
}


void printPixel(int x,int y, color C){
  if( x < 149 || x >= vinfo.xres - 140) return;
  if( y < 50 || y >= vinfo.yres - 80) return;
  long int location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
  if (vinfo.bits_per_pixel == 32) {
      *(fbp + location) = C.B;         //Blue
      *(fbp + location + 1) = C.G;     //Green
      *(fbp + location + 2) = C.R;     //Red
      *(fbp + location + 3) = 0;       //No transparency
  } else  { //assume 16bpp
      int r = C.R;     //Red
      int g = C.G;     //Green
      int b = C.B;     //Blue

      unsigned short int t = r<<11 | g << 5 | b;
      *((unsigned short int*)(fbp + location)) = t;
  }
}

void copyPixel(int dx, int dy, int sx, int sy){
  if( sx < 149 || sx >= vinfo.xres - 140 ) return;
  if( sy < 50 || sy >= vinfo.yres - 80) return;
  if( dx < 149 || dx >= vinfo.xres - 140) return;
  if( dy < 50 || dy >= vinfo.yres - 80) return;

  long int src = (sx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (sy+vinfo.yoffset) * finfo.line_length;
  long int dst = (dx+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (dy+vinfo.yoffset) * finfo.line_length;

  if (vinfo.bits_per_pixel == 32) {
      *(fbp + dst) = *(fbp + src);
      *(fbp + dst + 1) = *(fbp + src + 1);
      *(fbp + dst + 2) = *(fbp + src + 2);
      *(fbp + dst + 3) = 0;       //No transparency
  } else  { //assume 16bpp
      int r = *(fbp + src);     //Red
      int g = *(fbp + src + 1);     //Green
      int b = *(fbp + src + 2);     //Blue

      unsigned short int t = r<<11 | g << 5 | b;
      *((unsigned short int*)(fbp + dst)) = t;
  }

}


void printBackground(color C) {
    long int location;
    int width = displayWidth - 6;
    int height = displayHeight - 6;
    int i,j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            location = (i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j+vinfo.yoffset) * finfo.line_length;
            if (vinfo.bits_per_pixel == 32) {
                *(fbp + location) = C.B;         //Blue
                *(fbp + location + 1) = C.G;     //Green
                *(fbp + location + 2) = C.R;     //Red
                *(fbp + location + 3) = 0;       //No transparency
            } else  { //assume 16bpp
                int r = C.R;     //Red
                int g = C.G;     //Green
                int b = C.B;     //Blue

                unsigned short int t = r<<11 | g << 5 | b;
                *((unsigned short int*)(fbp + location)) = t;
            }
        }
    }
}
