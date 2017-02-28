#include "Point.h"
#include "line.h"

class Polygon : public Drawable
{
public:	
	Polygon(Point*);
	~Polygon();

	void draw();
	void clip();
	void scale();

	/* data */
private:
	Point* arrPoint;
};