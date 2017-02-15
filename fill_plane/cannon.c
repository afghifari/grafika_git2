#include "cannon.h"
#include "bendamantul.h"

int cannonX;
int cannonY;
int destProjectile;
int sentx, senty;

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
		while (sum<200) {
			if (P2.y <= 700 && status == 0)
			{
				// drawBresenhamLine(P1, P2, c, 40);
				buildBenda(P2.x +2, P2.y - 40, c);
				// boundary_fill (P2.x, P2.y - 20, B, C, X) ;
				usleep(10000);
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
			if ((P2.x >= indeksIPesawat && P2.x < indeksIPesawat+180) && (P2.y < indeksJPesawat) ) {
				endSign = 1;
				hit = 1;
				P2.x += 20;
				P2.y += 20;
				drawExplosion(P2);
				orang_terjun(P2.x+40, P2.y+40, C);
				break;
			}
		}else {
			// printf("x : %d, y: %d \n", P2.x, P2.y);
			if ((P2.x <= indeksIPesawat && P2.x > indeksIPesawat-180) && (P2.y < indeksJPesawat) ) {
				endSign = 1;
				hit = 1;
				P2.x += 20;
				P2.y += 20;
				drawExplosion(P2);
				orang_terjun(P2.x+40, P2.y+40, C);
				break;
			}
		}

	}
}
