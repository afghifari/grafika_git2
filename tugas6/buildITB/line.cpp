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
	int x1, y1, x2, y2;
	if (clipLine(P1.GetAbsis(), P1.GetOrdinat(), P2.GetAbsis(), P2.GetOrdinat(), x1, y1, x2, y2))
	{
		P1.SetAbsis(x1);
		P1.SetOrdinat(y1);
		P2.SetAbsis(x2);
		P2.SetOrdinat(y2);
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
}

void line::drawBresenhamLine2 (Point P1, Point P2, color C, int W) {
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
	int x1, y1, x2, y2;
	for (i = 0;i < n-1;i++) {
		if (clipLine(P[i].GetAbsis(), P[i].GetOrdinat(), P[i+1].GetAbsis(), P[i+1].GetOrdinat(), x1, y1, x2, y2)) {
			P[i].SetAbsis(x1);
			P[i].SetOrdinat(y1);
			P[i+1].SetAbsis(x2);
			P[i+1].SetOrdinat(y2);
		}
		drawBresenhamLine(P[i], P[i+1], C, W);
	}
}

void line::drawPolyline2 (int n, Point *P, color C, int W) {
	int i;
	int x1, y1, x2, y2;
	for (i = 0;i < n-1;i++) {
		drawBresenhamLine2(P[i], P[i+1], C, W);
	}
}

void line::drawPolygon (int n, Point *P, color C, int W) {
	drawBresenhamLine(P[n-1], P[0], C, W);
	drawPolyline(n, P, C, W);
	// fill unknown generated gap
	drawBresenhamLine(P[n-1], P[0], C, W);
}

void line::drawPolygon2 (int n, Point *P, color C, int W) {
	drawBresenhamLine2(P[n-1], P[0], C, W);
	drawPolyline2(n, P, C, W);
	// fill unknown generated gap
	drawBresenhamLine2(P[n-1], P[0], C, W);
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

void line::drawPolygonZoom2 (int n, Point *P, color C, int W, double multiplier) {
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
	

	drawBresenhamLine2(P[n-1], P[0], C, W);
	drawPolyline2(n, P, C, W);
	// fill unknown generated gap
	drawBresenhamLine2(P[n-1], P[0], C, W);
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

int line::findRegion(int x, int y)
{
	int h = 400;
	int w = 400;
  int code=0;
  if(y >= h)
  code |= 1; //top
  else if(y < 0)
  code |= 2; //bottom
  if(x >= w)
  code |= 4; //right
  else if (x < 0)
  code |= 8; //left
  return(code);
}


bool line::clipLine(int x1, int y1, int x2, int y2, int & x3, int & y3, int & x4, int & y4)
{
  int code1, code2, codeout;
  int w = 400;
  int h = 400;
  bool accept = 0, done=0;
  code1 = findRegion(x1, y1); //the region outcodes for the endpoints
  code2 = findRegion(x2, y2);
  do //In theory, this can never end up in an infinite loop, it'll always come in one of the trivial cases eventually
  {
    if(!(code1 | code2)) accept = done = 1;  //accept because both endpoints are in screen or on the border, trivial accept
    else if(code1 & code2) done = 1; //the line isn't visible on screen, trivial reject
    else  //if no trivial reject or accept, continue the loop
    {
      int x, y;
      codeout = code1 ? code1 : code2;
      if(codeout & 1) //top
      {
        x = x1 + (x2 - x1) * (h - y1) / (y2 - y1);
        y = h - 1;
      }
      else if(codeout & 2) //bottom
      {
        x = x1 + (x2 - x1) * -y1 / (y2 - y1);
        y = 0;
      }
      else if(codeout & 4) //right
      {
        y = y1 + (y2 - y1) * (w - x1) / (x2 - x1);
        x = w - 1;
      }
      else //left
      {
        y = y1 + (y2 - y1) * -x1 / (x2 - x1);
        x = 0;
      }
      if(codeout == code1) //first endpoint was clipped
      {
        x1 = x; y1 = y;
        code1 = findRegion(x1, y1);
      }
      else //second endpoint was clipped
      {
        x2 = x; y2 = y;
        code2 = findRegion(x2, y2);
      }
    }
  }
  while(done == 0);
  if(accept)
  {
    x3 = x1;
    x4 = x2;
    y3 = y1;
    y4 = y2;
    return 1;
  }
  else
  {
    x3 = x4 = y3 = y4 = 0;
    return 0;
  }
}

