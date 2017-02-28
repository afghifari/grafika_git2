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

	/* data */
private:
	Point* arrPoint;
	color C;
	int W;
};