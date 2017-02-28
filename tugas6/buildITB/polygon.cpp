Polygon::Polygon(Point* p, color c, int w) {
	arrPoint = p;
	C = c;
	W = w;
}
Polygon::~Polygon() {
	free(arrPoint);
}
void Polygon::draw() {
	
}
void Polygon::clip() {

}
void Polygon::zoom() {

}