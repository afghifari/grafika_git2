#include "cannon.h"
#include "bendamantul.h"
#include "propeller.h"

int cannonX;
int cannonY;
int destProjectile;
int sentx, senty;


void *thread2Procedure(void *x_void_ptr) {
	color X;
	X.R = 0;
	X.G = 0;
	X.B = 0;

	color C;
	C.R = 255; //255 10
	C.G = 255; //255 -1
	C.B = 10; //10 -1

	indeksIPesawat += 500;

	while(indeksJPesawat + 50 < vinfo.yres) {
		buildCrashPlane(indeksIPesawat, indeksJPesawat, C);
		usleep(10000);
		buildCrashPlane(indeksIPesawat, indeksJPesawat, X);
		indeksIPesawat += 10;
		indeksJPesawat += 10;
	}
	return NULL;
}

void orang_terjun(int x, int y, color c) {
	color black;
	black.R = 0;
	black.G = 0;
	black.B = 0;

	color X;
	X.R = 0;
	X.G = 0;
	X.B = 0;


	color C;
	C.R = 255; //255 10
	C.G = 255; //255 -1
	C.B = 10; //10 -1

	color B;
	B.R = 66;
	B.G = 134;
	B.B = 244;


	Point P1;
	P1.x = x;
	P1.y = y;
	Point P2;
	P2.x = x;
	P2.y = y - 20;

	// while (1)
	// {
	int status = 0;
	int sum = 0;
		while (sum<230) {
			if (P2.y <= 700 && status == 0)
			{
				// drawBresenhamLine(P1, P2, c, 40);
				buildBenda(P2.x +2, P2.y - 40, c);
				// boundary_fill (P2.x, P2.y - 20, B, C, X) ;
				buildFourBlade( P2.x - P2.y*1.5, P2.y, C, B, X, 200-0.05*P2.y);
				// boundary_fill (P2.x, P2.y - 20, B, C, X) ;
				usleep(10000);
				cleanFourBlade( P2.x - P2.y*1.5, P2.y, X);
				// drawBresenhamLine(P1, P2, black, 40);
				buildBenda(P2.x +2, P2.y - 40, black);		
				// boundary_fill (P2.x, P2.y - 20, X, C, B);

				P2.y += 4;
				if (P2.y > 700)
					status = 1;
			}
			else if (P2.y >= 300 && status != 0)
			{
				// drawBresenhamLine(P1, P2, c, 40);
				// usleep(10000);
				buildBenda(P2.x +2, P2.y - 150, c);
				// boundary_fill (P2.x, P2.y - 20, B, C, X) ;
				usleep(10000);
				// drawBresenhamLine(P1, P2, black, 40);
				buildBenda(P2.x +2, P2.y - 150, black);
				// boundary_fill (P2.x, P2.y - 20, X, C, B);

				P2.y -= 4;
				if (P2.y < 300)
					status = 0;
			}
			// if (direction == 1){
			// 	if ((P2.x >= indeksIPesawat && P2.x < indeksIPesawat+180) && (P2.y < indeksJPesawat) ) {
			// 		endSign = 1;
			// 		hit = 1;
			// 		// buildBenda(P2.x+40, P2.y+40, C);
			// 	}
			// }else {
			// 	if ((P2.x <= indeksIPesawat && P2.x > indeksIPesawat-180) && (P2.y < indeksJPesawat) ) {
			// 		endSign = 1;
			// 		hit = 1;
			// 		drawExplosion(P2);
			// 		buildBenda(P2.x+40, P2.y+40, C);
			// 	}
			// }
			sum++;
		}
		// usleep(10000);
		// while (P2.y >= 200) {
		// 	printf("masuk ke-dua: %d\n", P2.y);
		// 	// drawBresenhamLine(P1, P2, c, 40);
		// 	usleep(10000);
		// 	buildBenda(P2.x +2, P2.y - 40, black);
		// 	// boundary_fill (P2.x, P2.y - 20, B, C, X) ;
		// 	usleep(10000);
		// 	// drawBresenhamLine(P1, P2, black, 40);
		// 	buildBenda(P2.x +2, P2.y - 40, c);
		// 	// boundary_fill (P2.x, P2.y - 20, X, C, B);

		// 	P2.y -= 4;
		// }
	// }
}

void buildHalfCannon(Point P, color C) {
	drawCircleHalf(30, P, 10, C);
	printSquare(12, P.x, P.y - 100, C);
}

void buildCannon(int x, int y, color c) {
	cannonX = x;
	cannonY = y;
	destProjectile = 0;

	Point P1;
	P1.x = x-12;
	P1.y = y;
	Point P2;
	P2.x = x+10;
	P2.y = y;
	Point P3;
	P3.x = x;
	P3.y = y;
	Point P4;
	P4.x = x;
	P4.y = y-8;

	drawBresenhamLine(P1, P2, c, 6);
	drawBresenhamLine(P3, P4, c, 4);
}

void shootCannon(int x, int y, color c) {
	pthread_t thread2;
	int xx = 0;

	color black;
	black.R = 0;
	black.G = 0;
	black.B = 0;

	color X;
	X.R = 0;
	X.G = 0;
	X.B = 0;


	color C;
	C.R = 255; //255 10
	C.G = 255; //255 -1
	C.B = 10; //10 -1

	color B;
	B.R = 66;
	B.G = 134;
	B.B = 244;


	Point P1;
	P1.x = x;
	P1.y = y;
	Point P2;
	P2.x = x;
	P2.y = y - 20;

	while ((P1.y > 0) && (destProjectile == 0) && hit==0) {
		// drawBresenhamLine(P1, P2, c, 40);
		buildRocket(P2.x +2, P2.y - 40, c);
		boundary_fill (P2.x, P2.y - 20, B, C, X) ;
		usleep(5000);
		// drawBresenhamLine(P1, P2, black, 40);
		buildRocket(P2.x +2, P2.y - 40, black);
		boundary_fill (P2.x, P2.y - 20, X, C, B);

		P1.y -= 4;
		P2.y -= 4;
		if (direction == 1){
			// printf("x : %d, y: %d \n", P2.x, P2.y);
			if ((P2.x >= indeksIPesawat - 60 && P2.x < indeksIPesawat + 260) && (P2.y < indeksJPesawat + 60) ) {
				endSign = 1;
				hit = 1;
				P2.x += 20;
				P2.y += 20;

				cleanFourBlade( indeksIPesawat - 100, indeksJPesawat, X);
				buildPlaneToLeft(indeksIPesawat, indeksJPesawat, X);
	  			fill_planeToLeft(indeksIPesawat, indeksJPesawat, X,  C, B);
			}
		}else {
			// printf("x : %d, y: %d \n", P2.x, P2.y);
			if ((P2.x <= indeksIPesawat + 60 && P2.x > indeksIPesawat - 260) && (P2.y + 50 < indeksJPesawat + 60) ) {
				endSign = 1;
				hit = 1;
				P2.x += 20;
				P2.y += 20;

				cleanFourBlade( indeksIPesawat - 100, indeksJPesawat, X);
				buildPlaneToRight(indeksIPesawat, indeksJPesawat, X);
	  			fill_planeToRight(indeksIPesawat, indeksJPesawat, X,  C, B);
			}
		}

	}
	if (hit==1) {
		int forking;
		forking = fork();
		if (forking==0)
			orang_terjun(P2.x+20, P2.y+40, C);
		else if (forking>0) {
			//create a thread which executes inc_x(&x)
			if(pthread_create(&thread2, NULL, thread2Procedure, &xx)) {
				fprintf(stderr, "Error creating thread\n");
			}
			drawExplosion(P2);
			P2.x += 300;
			drawExplosion(P2);
			P2.x -= 150;
			P2.y -= 70;
			drawExplosion(P2);
		}
	}
}
