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
#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68
#define KEY_ENTER 10

#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_T 116
#define KEY_B 98
#define KEY_R 114


using namespace std;
	bufferMem buf;
	ifstream fs3("data/dataTree");
	ifstream fs1("data/dataBuilding");
	ifstream fs2("data/dataRoad");	
	ifstream fs6("data/dataTree");
	ifstream fs4("data/dataBuilding");
	ifstream fs5("data/dataRoad");
		double multiplier = 1;
	Point camera = Point(200, 200);
	bool treeView = true;
	bool roadView = true;
	bool buildingView = true;

		//read keypress
int getch(void) {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}
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

    // new polygon+
    istringstream ss( str );
    while( true ){
      int x;
      int y;
      ss >> x;
      ss >> y;
      P[N] = Point((camera.GetAbsis() + x)*multiplier,(camera.GetOrdinat() + y)*multiplier);
      N++;
      if( ss.eof() ) break;
      //cout << N << " ";
      // add to polygon Point x and y
      	
    }
    line LineFactory;
     LineFactory.drawPolygonZoom(N, P, blueColor, 3, (sqrt(multiplier))/64);
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
      P[N] = Point((camera.GetAbsis() + x)*multiplier,(camera.GetOrdinat() + y)*multiplier);
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
      P[N] = Point((camera.GetAbsis() + x)*multiplier,(camera.GetOrdinat() + y)*multiplier);
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

void loadPointFile( ifstream& fs, double multiplier ){
  int x, y;
  color greenColor(30,255,30);
  while( true ){
    fs >> x >> y;
    if( fs.eof() ) break;
    // push new tree here
    //points.push_back( Point(x*multiplier,y*multiplier) );
    line Linefactory;
    Point points[3];
    points[0] = Point(x+4, y+4);
    points[1] = Point(x-4, y+4);
    points[2] = Point(x, y-4);
    for( int i = 0; i < 3; ++ i ){
    	points[i].SetAbsis( (camera.GetAbsis() + points[i].GetAbsis()) * multiplier );
    	points[i].SetOrdinat( (camera.GetOrdinat() + points[i].GetOrdinat()) * multiplier );
    }

    Linefactory.drawPolygonZoom(3,points,greenColor, 1, sqrt(multiplier)/32);
    // Circle circleFactory(Point(x*multiplier,y*multiplier), 2*multiplier, 1*multiplier, greenColor);
//    circleFactory.zoom(buf, sqrt(multiplier));
  }
}

void loadPolygonFile2( ifstream& fs, double multiplier ){
	 Point P[100];
//	 for(int i =0; i<100; i++) {
//		 P[i] = Point(0,0);
//	 }
  while( true ){
	 
	int N =0;
    string str;
    getline( fs, str );
	color blueColor(0,30,255);

    // new polygon+
    istringstream ss( str );
    while( true ){
      int x;
      int y;
      ss >> x;
      ss >> y;
      P[N] = Point(600+( x)*multiplier,( y)*multiplier);
      N++;
      if( ss.eof() ) break;
      //cout << N << " ";
      // add to polygon Point x and y
      	
    }
    line LineFactory;
     LineFactory.drawPolygonZoom2(N, P, blueColor, 3, (sqrt(multiplier))/64);
    N= 0;
    if( fs.eof() ) break;
    
    // push to array polygons
  }
}

void loadRoadFile2( ifstream& fs, double multiplier ){
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
      P[N] = Point(600+( x)*multiplier,( y)*multiplier);
      N++;
      if( ss.eof() ) break;
      //cout << N << " ";
      // add to polygon Point x and y
      	
    }
    line LineFactory;
     LineFactory.drawPolygonZoom2(N, P, yellowColor, 1, sqrt(multiplier)/32);
    N= 0;
    while( N <2){
      int x;
      int y;
      ss >> x;
      ss >> y;
      P[N] = Point(600 + ( x)*multiplier,( y)*multiplier);
      N++;
      if( ss.eof() ) break;
      //cout << N << " ";
      // add to polygon Point x and y
      	
    }
     LineFactory.drawPolygonZoom2(N, P, yellowColor, 1, sqrt(multiplier)/32);
    if( fs.eof() ) break;
    
    // push to array polygons
  }
}

void loadPointFile2( ifstream& fs, double multiplier ){
  int x, y;
  color greenColor(30,255,30);
  while( true ){
    fs >> x >> y;
    if( fs.eof() ) break;
    // push new tree here
    //points.push_back( Point(x*multiplier,y*multiplier) );
    line Linefactory;
    Point points[3];
    points[0] = Point(x+4, y+4);
    points[1] = Point(x-4, y+4);
    points[2] = Point(x, y-4);
    for( int i = 0; i < 3; ++ i ){
    	points[i].SetAbsis( 600+ ( points[i].GetAbsis()) * multiplier );
    	points[i].SetOrdinat( ( points[i].GetOrdinat()) * multiplier );
    }

    Linefactory.drawPolygonZoom2(3,points,greenColor, 1, sqrt(multiplier)/32);
    // Circle circleFactory(Point(x*multiplier,y*multiplier), 2*multiplier, 1*multiplier, greenColor);
//    circleFactory.zoom(buf, sqrt(multiplier));
  }
}



void *petaBesar(void* args) {	
	while (true) {
		if (treeView)
			loadPointFile(fs6, 1);
		if (buildingView)
			loadPolygonFile( fs4, 1);
		if (roadView)
			loadRoadFile( fs5, 1 );
		usleep(100000);
		fs4.close();
		fs5.close();
		fs6.close();
		fs6.open("data/dataTree");
		fs4.open("data/dataBuilding");
		fs5.open("data/dataRoad");
	}
	return NULL;
}

void *inc_x(void *x_void_ptr) {
	pthread_t thread1;

	while(true){
		char c;
		c = getch();
		if (c == KEY_DOWN){
			multiplier = multiplier-0.1;
		}
        else if (c == KEY_UP) {
        	multiplier = multiplier+0.1;
        }else if (c == KEY_A) {
    		camera.SetAbsis(camera.GetAbsis() + 10);
    	} else if (c == KEY_D) {
    		camera.SetAbsis(camera.GetAbsis() - 10);
    	} else if (c == KEY_S) {
    		camera.SetOrdinat(camera.GetOrdinat() - 10);
    	} else if (c == KEY_W) {
    		camera.SetOrdinat(camera.GetOrdinat() + 10);
    	} else if (c == KEY_T) {
    		treeView = !treeView;
    	} else if (c == KEY_B) {
    		buildingView = !buildingView;
    	} else if (c == KEY_R) {
    		roadView = !roadView;
    	}
		
	}


	return NULL;
}


int main(){

	buf.startBuffer();
	int x=0;
	int sign = 0;
	color blackColor(0,0,0);
	color whiteColor(255,255,255);
	line Liner;
	Point po[4];
	po[0] = Point(0,0);
	po[1] = Point(0,400);
	po[2] = Point(400,400);
	po[3] = Point(400,0);
	
	pthread_t inc_x_thread, thread33;

	//  //create a thread which executes inc_x(&x)
	if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
		fprintf(stderr, "Error creating thread 1\n");
		return 1;
	}
	
	if(pthread_create(&thread33, NULL, petaBesar, (void*)0)) {
		fprintf(stderr, "Error creating thread 1\n");
		return 1;
	}
	while (sign==0) {


		buf.printBackground(blackColor);
		if (treeView)
			loadPointFile(fs3, multiplier);
		if (buildingView)
			loadPolygonFile( fs1, multiplier);
		if (roadView)
			loadRoadFile( fs2, multiplier );
		Liner.drawPolyline(4,po,whiteColor,2);
		usleep(100000);
		fs1.close();
		fs2.close();
		fs3.close();
		fs3.open("data/dataTree");
		fs1.open("data/dataBuilding");
		fs2.open("data/dataRoad");
	}


    fs1.close();
    fs2.close();
    fs3.close();
  buf.closeBuffer();
  
  return 0;
}
