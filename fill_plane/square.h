#ifndef SQUARE_H
#define SQUARE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#define SIZE 10

extern int fbfd;
extern struct fb_var_screeninfo vinfo;
extern struct fb_fix_screeninfo finfo;
extern long int screensize;
extern char *fbp;
extern int displayWidth, displayHeight;

extern int indeksIPesawat, indeksJPesawat;
extern int endSign;
extern int direction;
extern int hit;


/*color struct consists of Red, Green, and Blue */
typedef struct {
    int R;
    int G;
    int B;
} color;

/*
edge    : square size
loc_x   : x coordinate
loc_y   : y coordinate
C       : color struct (Red, Green, Blue)
*/
void printSquare (int edge, int loc_x, int loc_y, color C);

void printBackground(color C);

#endif
