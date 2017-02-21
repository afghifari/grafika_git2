#include "flood.h"
#include "plane.h"
#include "cannon.h"
#include "square.h"
#include "line.h"
#include "bendamantul.h"
#include "propeller.h"

#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68
#define KEY_ENTER 10

static int explode;
static Point P;

//read keypress
int getch(void) {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

color colorBlack() {
	//black
	color X;
	X.R = 0;
	X.G = 0;
	X.B = 0;
	return X;
}

color colorYellow() {
	//yellow
	color C;
	C.R = 255; //255 10
	C.G = 255; //255 -1
	C.B = 10; //10 -1

	return C;
}

color colorBlue() {
	//blue
	color B;
	B.R = 66;
	B.G = 134;
	B.B = 244;

	return B;
}

void *tothread(){
	color B, yellow;
	B = colorBlue();
	yellow = colorYellow();
	shootCannon(P.x, P.y, yellow);
}



/* this function is run by the second thread */
void *inc_x(void *x_void_ptr) {
	pthread_t thread1;

	color C, X;
	C = colorYellow();
	X = colorBlack();

	while(endSign == 0){

		char c = getch();
		if (c == KEY_RIGHT){
			buildHalfCannon(P, X);
			if (P.x + 70 < vinfo.xres)
				P.x += 10;
		}
        else if (c == KEY_LEFT) {
        	buildHalfCannon(P, X);
        	if (P.x > 30)
        		P.x -= 10;
        }
        else if (c == KEY_ENTER) {
        	pthread_create(&thread1, NULL, &tothread, NULL);
			pthread_join(thread1, NULL);
        }else {

        }
	}
	explode = 1;

	return NULL;
}

 int main()
 {
 	hit = 0;
	int x = 0, y = 0;
	int scala, scalaCounter, flagScala;
	direction = 0;
	int sign;
	endSign = 0;
	explode = 0;
	long int location = 0;
	color X, C, B;

	X = colorBlack();
	C = colorYellow();
	B = colorBlue();

	// Open the file for reading and writing
	fbfd = open("/dev/fb0", O_RDWR);
	if (fbfd == -1) {
	 perror("Error: cannot open framebuffer device");
	 exit(1);
	}

	// Get fixed screen information
	if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
	 perror("Error reading fixed information");
	 exit(2);
	}

	// Get variable screen information
	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
	 perror("Error reading variable information");
	 exit(3);
	}

	// Figure out the size of the screen in bytes
	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	// Map the device to memory
	fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED,
	                fbfd, 0);
	if ((int)fbp == -1) {
	 perror("Error: failed to map framebuffer device to memory");
	 exit(4);
	}

	displayWidth = vinfo.xres;
	displayHeight = vinfo.yres;

	P.x = displayWidth / 2;
	P.y = 740;

	// this variable is our reference to the thread
	pthread_t inc_x_thread;

	 //create a thread which executes inc_x(&x)
	if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
		fprintf(stderr, "Error creating thread 1\n");
		return 1;
	}
	int done = 0;
	printBackground(X);

// buildSquare(80, 600, C);
	scalaCounter = 20;
	flagScala = 1;
	scala = 6;
	while (endSign == 0){

		// pesawat terbang disini
		int counter = 0;
		indeksJPesawat = 240;
		sign = 0;
		indeksIPesawat = 1000;

		while(indeksIPesawat > 20 && endSign == 0){
			buildSquareLine(80, 600, C);
			direction = 1;
	  		buildPlaneToLeft(indeksIPesawat, indeksJPesawat, C, scala);
				fill_planeToLeft(indeksIPesawat, indeksJPesawat, scala, B,  C, X);
				buildFourBlade( indeksIPesawat - 50, indeksJPesawat, C, B, X, 0.5*indeksJPesawat);

				usleep(50000);
				cleanFourBlade( indeksIPesawat - 50, indeksJPesawat, X);
	  		buildPlaneToLeft(indeksIPesawat, indeksJPesawat, X, scala);
	  		fill_planeToLeft(indeksIPesawat, indeksJPesawat, scala, X,  C, B);

	 	    if (indeksJPesawat <= 100)
	 	    	sign = 1;
	 	    else if (indeksJPesawat >= 340)
	 	    	sign = 0;

	 	    if (sign == 0)
	 	    	indeksJPesawat -= 10;
	 	    else
	 	    	indeksJPesawat += 15;

	 	    buildHalfCannon(P, B);


	 	    if (counter==1){
	 	    	counter=0;
	 	    }
	 	    counter++;
	 	    indeksIPesawat -= 10;

	 	    if (scalaCounter % 5 == 0 && scalaCounter > 20)
				scala++;
			else if (scalaCounter % 5 == 0 && scalaCounter < 20)
				scala--;

			if (scalaCounter == 40) {
				scalaCounter = 20;
				flagScala = 0;
			} else if (scalaCounter == 0) {
				scalaCounter = 20;
				flagScala = 1;
			}

			if (flagScala==1)
				scalaCounter++;
			else
				scalaCounter--;
	  	}

	  	counter=0;
	  	indeksIPesawat = 20;
	  	while (indeksIPesawat < 1250 && endSign == 0){
	  		buildSquareLine(80, 600, C);
	  		direction = -1;
	  		buildPlaneToRight(indeksIPesawat, indeksJPesawat, C, scala);
	  			 fill_planeToRight(indeksIPesawat, indeksJPesawat, scala, B,  C, X);
		  		buildFourBlade( indeksIPesawat + 50, indeksJPesawat, C, B, X, 0.5*indeksJPesawat);
				usleep(50000);
				cleanFourBlade( indeksIPesawat + 50, indeksJPesawat, X);
	  		buildPlaneToRight(indeksIPesawat, indeksJPesawat, X, scala);
	  		 	fill_planeToRight(indeksIPesawat, indeksJPesawat, scala, X,  C, B);

	 	    if (indeksJPesawat <= 100)
	 	    	sign = 1;
	 	    else if (indeksJPesawat >= 340)
	 	    	sign = 0;

	 	    if (sign == 0)
	 	    	indeksJPesawat -= 10;
	 	    else
	 	    	indeksJPesawat += 15;

	 	    buildHalfCannon(P, B);

	 	    if (counter==1){
	 	    	counter=0;
	 	    }
	 	    counter++;
	 	    indeksIPesawat += 10;
	  	}

	}

	endSign = 1;
    pthread_join(inc_x_thread, NULL);
    buildSquareLine(80, 600, C);
	munmap(fbp, screensize);
	close(fbfd);
	return 0;
}
