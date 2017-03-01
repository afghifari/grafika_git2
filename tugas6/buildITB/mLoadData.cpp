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

using namespace std;
	bufferMem buf;
	ifstream fs3("data/dataTree");
	ifstream fs1("data/dataBuilding");
	ifstream fs2("data/dataRoad");
		double multiplier = 1;
		
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
      P[N] = Point(x*multiplier,y*multiplier);
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

void loadPointFile( ifstream& fs, double multiplier ){
  int x, y;
  color greenColor(30,255,30);
  while( true ){
    fs >> x >> y;
    if( fs.eof() ) break;
    // push new tree here
    //points.push_back( Point(x*multiplier,y*multiplier) );
    Circle circleFactory(Point(x*multiplier,y*multiplier), 2*multiplier, 1*multiplier, greenColor);
    circleFactory.zoom(buf, sqrt(multiplier));
  }
}

void *inc_x(void *x_void_ptr) {
	pthread_t thread1;

	while(true){
		char c;
		c = getch();
		if (c == KEY_DOWN){
			multiplier = multiplier-0.3;
		}
        else if (c == KEY_UP) {
        	multiplier = multiplier+0.3;
        }else {

        }
		
	}


	return NULL;
}


int main(){

	buf.startBuffer();
	int x=0;
	int sign = 0;
	color blackColor(0,0,0);
	
	pthread_t inc_x_thread, thread33;

	//  //create a thread which executes inc_x(&x)
	if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
		fprintf(stderr, "Error creating thread 1\n");
		return 1;
	}
	
	while (sign==0) {

		buf.printBackground(blackColor);
		
		loadPointFile(fs3, multiplier);
		
		loadPolygonFile( fs1, multiplier);
		
		loadRoadFile( fs2, multiplier );
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
