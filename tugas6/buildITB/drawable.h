class Drawable
{
public:
	Drawable();
	virtual void draw();
	virtual void clip();
	virtual void zoom();

protected:
	bufferMem buf;
	Frame frame;
	int width;
	int height;

};