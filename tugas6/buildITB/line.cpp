#include "line.h"
#include <stdio.h>

void line::swap (int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void line::swapPoint (Point *P1, Point *P2) {
	int x1 = P1->GetAbsis();
	int y1 = P1->GetOrdinat();
	int x2 = P2->GetAbsis();
	int y2 = P2->GetOrdinat();

	swap(&x1, &x2);
	swap(&y1, &y2);

	P1->SetAbsis(x1);
	P1->SetOrdinat(y1);
	P2->SetAbsis(x2);
	P2->SetOrdinat(y2);
}

void line::plotSlopPositiveLine (Point P1, Point P2, color C, int W) {
	int dX, dY, p;
	int i, j, x, y;

	dX = abs(P2.GetAbsis() - P1.GetAbsis());
	dY = abs(P2.GetOrdinat() - P1.GetOrdinat());
	i = P1.GetAbsis();
	j = P1.GetOrdinat();

	if (dX >= dY) {
		p = 2*dY - dX;
		// printf("Based on +X\n");
		for (x=P1.GetAbsis(); x<=P2.GetAbsis(); x++) {
			// printf("%d %d\n", x, j);
			if (W<4) buf.printSquare(W, x, j, C);
			else {
				if (x%(W/2)==0) buf.printSquare(W, x, j, C);
			}
			if (p >= 0) {
				p += 2* (dY - dX);
				i++;
				j++;
			}
			else {
				p += 2*dY;
				i++;
			}
		}
	}
	else {
		p = 2*dX - dY;
		// printf("Based on +Y\n");
		for (y=P1.GetOrdinat(); y<=P2.GetOrdinat(); y++) {
			// printf("%d %d\n", i, y);
			if (W<4) buf.printSquare(W, i, y, C);
			else {
				if (y%(W/2)==0) buf.printSquare(W, i, y, C);
			}
			if (p >= 0) {
				p += 2* (dX - dY);
				i++;
				j++;
			}
			else {
				p += 2*dX;
				j++;
			}
		}
	}
}

void line::plotSlopNegativeLine (Point P1, Point P2, color C, int W) {
	int dX, dY, p;
	int i, j, x, y;


	dX = abs(P2.GetAbsis() - P1.GetAbsis());
	dY = abs(P2.GetOrdinat() - P1.GetOrdinat());
	i = P1.GetAbsis();
	j = P1.GetOrdinat();

	if (dX >= dY) {
		p = 2*dY - dX;
		// printf("Based on -X\n");
		for (x=P1.GetAbsis(); x<=P2.GetAbsis(); x++) {
			// printf("%d %d\n", x, j);
			if (W<4) buf.printSquare(W, x, j, C);
			else {
				if (x%(W/2)==0) buf.printSquare(W, x, j, C);
			}
			if (p >= 0) {
				p += 2* (dY - dX);
				i++;
				j--;
			}
			else {
				p += 2*dY;
				i++;
			}
		}
	}
	else {
		p = 2*dX - dY;
		i = P2.GetAbsis();
		j = P2.GetOrdinat();
		// printf("Based on -Y\n");
		for (y=P2.GetOrdinat(); y<=P1.GetOrdinat(); y++) {
			// printf("%d %d\n", i, y);
			if (W<4) buf.printSquare(W, i, y, C);
			else {
				if (y%(W/2)==0) buf.printSquare(W, i, y, C);
			}
			if (p >= 0) {
				p += 2* (dX - dY);
				i--;
				j++;
			}
			else {
				p += 2*dX;
				j++;
			}
		}
	}
}

void line::plotVerticalLine (Point P1, Point P2, color C, int W) {
	int j;

	if (P2.GetOrdinat() < P1.GetOrdinat()) {
		swapPoint(&P1,&P2);
	}

	for(j = P1.GetOrdinat() ; j <= P2.GetOrdinat(); j++){
		// printf("%d %d\n", P1.x , j);
		buf.printSquare(W, P1.GetAbsis(), j, C);
	}
}

void line::drawBresenhamLine (Point P1, Point P2, color C, int W) {
	if (P1.GetAbsis() > P2.GetAbsis()) {
		swapPoint(&P1,&P2);
	}

	if ((P2.GetAbsis() >= P1.GetAbsis() && P1.GetOrdinat() > P2.GetOrdinat())) {
		plotSlopNegativeLine(P1,P2,C,W);
	}
	else if (P1.GetAbsis() == P2.GetAbsis()) {
		plotVerticalLine(P1,P2,C,W);
	}
	else {
		plotSlopPositiveLine(P1,P2,C,W);
	}
}

void line::drawPolyline (int n, Point *P, color C, int W) {
	int i;
	for (i = 0;i < n-1;i++) {
		drawBresenhamLine(P[i], P[i+1], C, W);
	}
}

void line::drawPolygon (int n, Point *P, color C, int W) {
	drawBresenhamLine(P[n-1], P[0], C, W);
	drawPolyline(n, P, C, W);
	// fill unknown generated gap
	drawBresenhamLine(P[n-1], P[0], C, W);
}

void line::drawPolygonZoom (int n, Point *P, color C, int W, double multiplier) {
	Point* P2;
	Point Pcentroid(0,0);
	for(int i=0; i<n; i++) {
		Pcentroid.AddToMe(P[i]);
	}
	Pcentroid.SetAbsis(Pcentroid.GetAbsis()/n);
	Pcentroid.SetOrdinat(Pcentroid.GetOrdinat()/n);
	int deltaX, deltaY;
	for(int i=0; i<n; i++) {
		deltaX = Pcentroid.GetAbsis() - P[i].GetAbsis();
		deltaY = Pcentroid.GetOrdinat() - P[i].GetOrdinat();
		P[i].SetAbsis(P[i].GetAbsis() - multiplier*deltaX);
		P[i].SetOrdinat(P[i].GetOrdinat() - multiplier*deltaY);
	}
	

	drawBresenhamLine(P[n-1], P[0], C, W);
	drawPolyline(n, P, C, W);
	// fill unknown generated gap
	drawBresenhamLine(P[n-1], P[0], C, W);
}

/*
initialPoint : explosion location in the screen
scaleFactor : size of the explosion
*P isi dengan array explosionPoint
*/
void line::drawExplosion (Point initialPoint) {
	/*Orange color*/
	color C;
	C.setColor(218,114,53);

	int i;
	for(i=0;i<200;i+=3){
		//drawCircle (i, initialPoint, 5, C);
		initialPoint.SetAbsis(initialPoint.GetAbsis() - 3);
		usleep(4000);
	}

	initialPoint.SetAbsis(initialPoint.GetAbsis() - 130);
	initialPoint.SetOrdinat(initialPoint.GetOrdinat() + 50);

	for(i=0;i<140;i+=3){
	//drawCircle (i, initialPoint, 5, C);
		initialPoint.SetAbsis(initialPoint.GetAbsis() + 1);
		usleep(4000);
	}
}


void line::plot4pixel (Point P, int p, int q, int W, color C) {
    buf.printSquare(W, P.GetAbsis()+p, P.GetOrdinat()-q, C);
    buf.printSquare(W, P.GetAbsis()-p, P.GetOrdinat()-q, C);
    buf.printSquare(W, P.GetAbsis()+q, P.GetOrdinat()-p, C);
    buf.printSquare(W, P.GetAbsis()-q, P.GetOrdinat()-p, C);
}




/*
radius	: jari-jari lingkaran
P	: titik asal lingkaran
*/
void line::drawCircleHalf (int radius, Point P, int W, color C) {
    int d, p, q;

    p = 0;
    q = radius;
    d = 3 - 2*radius;

    plot4pixel(P, p, q, W, C);

    while (p < q) {
        p++;
        if (d<0) {
            d = d + 4*p + 6;
        }
        else {
            q--;
            d = d + 4*(p-q) + 10;
        }

        plot4pixel(P, p, q, W, C);
    }
}
