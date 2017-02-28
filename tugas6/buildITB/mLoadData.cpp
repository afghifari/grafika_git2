#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Point.h"
using namespace std;

void loadPolygonFile( ifstream& fs ){
  while( true ){
    string str;
    getline( fs, str );

    // new polygon
    istringstream ss( str );
    while( true ){
      int x;
      int y;
      ss >> x;
      ss >> y;
      if( ss.eof() ) break;
      cout << x << "," << y << " ";
      // add to polygon Point x and y
    }
    if( fs.eof() ) break;
    
    // push to array polygons
  }
}

vector<Point> loadPointFile( ifstream& fs ){
  vector<Point> points;
  int x, y;
  while( true ){
    fs >> x >> y;
    if( fs.eof() ) break;
    // push new tree here
    points.push_back( Point(x,y) );
  }
  
  return points;
}

int main(){
  ifstream fs("data/dataBuilding");
  loadPolygonFile( fs );
  fs.close();
  
  fs.open("data/dataRoad");
  loadPolygonFile( fs );
  fs.close();
  
  fs.open("data/dataTree");
  vector<Point> ps = loadPointFile(fs);
  fs.close();
  
  
  
  return 0;
}