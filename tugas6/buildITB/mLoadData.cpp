#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "line.h"
#include "color.h"
#include "Point.h"
#include "Circle.h"
#include <math.h>
using namespace std;
	bufferMem buf;
void loadPolygonFile( ifstream& fs, double multiplier ){
	 Point P[100];
//	 for(int i =0; i<100; i++) {
//		 P[i] = Point(0,0);
//	 }
  while( true ){
	 
	  int N =0;
    string str;
    getline( fs, str );
	color blueColor(0,30,255);

    // new polygon
    istringstream ss( str );
    while( true ){
      int x;
      int y;
      ss >> x;
      ss >> y;
      P[N] = Point(x*multiplier,y*multiplier);
      N++;
      if( ss.eof() ) break;
      //cout << N << " ";
      // add to polygon Point x and y
      	
    }
    line LineFactory;
     LineFactory.drawPolygonZoom(N, P, blueColor, 3, (sqrt(multiplier))/32);
    N= 0;
    if( fs.eof() ) break;
    
    // push to array polygons
  }
}

void loadRoadFile( ifstream& fs, double multiplier ){
	 Point P[100];
//	 for(int i =0; i<100; i++) {
//		 P[i] = Point(0,0);
//	 }
  while( true ){
	 
	  int N =0;
    string str;
    getline( fs, str );
	color yellowColor(255,255,10);
	
    // new polygon
    istringstream ss( str );
    while( N <2){
      int x;
      int y;
      ss >> x;
      ss >> y;
      P[N] = Point(x*multiplier,y*multiplier);
      N++;
      if( ss.eof() ) break;
      //cout << N << " ";
      // add to polygon Point x and y
      	
    }
    line LineFactory;
     LineFactory.drawPolygonZoom(N, P, yellowColor, 1, sqrt(multiplier)/32);
    N= 0;
    while( N <2){
      int x;
      int y;
      ss >> x;
      ss >> y;
      P[N] = Point(x*multiplier,y*multiplier);
      N++;
      if( ss.eof() ) break;
      //cout << N << " ";
      // add to polygon Point x and y
      	
    }
     LineFactory.drawPolygonZoom(N, P, yellowColor, 1, sqrt(multiplier)/32);
    if( fs.eof() ) break;
    
    // push to array polygons
  }
}

vector<Point> loadPointFile( ifstream& fs, double multiplier ){
  vector<Point> points;
  int x, y;
  color greenColor(30,255,30);
  while( true ){
    fs >> x >> y;
    if( fs.eof() ) break;
    // push new tree here
    points.push_back( Point(x*multiplier,y*multiplier) );
    Circle circleFactory(Point(x*multiplier,y*multiplier), 2*multiplier, 1*multiplier, greenColor);
    circleFactory.zoom(buf, sqrt(multiplier));
  }
  
  return points;
}

int main(){

	buf.startBuffer();
	
	color blackColor(0,0,0);
	
	//PRINT LAYAR
	double multiplier = 2;
	buf.printBackground(blackColor);
	ifstream fs3("data/dataTree");
	vector<Point> ps = loadPointFile(fs3, multiplier);
	ifstream fs1("data/dataBuilding");
	loadPolygonFile( fs1, multiplier);
	ifstream fs2("data/dataRoad");
	loadRoadFile( fs2, multiplier );
  
  


    fs1.close();
    fs2.close();
    fs3.close();
  buf.closeBuffer();
  
  return 0;
}
