#include "Point.h"
#include "line.h"
#include "color.h"

class Polygon : public Drawable
{
public:	
	Polygon(Point* p, color c, int w);
	~Polygon();

	void draw();
	void clip();
	void zoom();

	int findRegion(int x, int y);
	bool clipLine(int x1, int y1, int x2, int y2, int & x3, int & y3, int & x4, int & y4);


	/* data */
private:
	Point* arrPoint;
	color C;
	int W;
	int n;
};