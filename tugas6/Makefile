all: clean mycolor mybufferMem myLine myZoom

mycolor:
	g++ -o myColor buildITB/bufferMem.cpp buildITB/mColor.cpp buildITB/color.cpp -std=c++11

mybufferMem :
	g++ -o mybufferMem buildITB/color.cpp buildITB/bufferMem.cpp buildITB/mBufferMem.cpp buildITB/Point.cpp buildITB/Circle.cpp buildITB/line.cpp -std=c++11

myLine:
	g++ -o myLine buildITB/mLine.cpp buildITB/line.cpp buildITB/color.cpp buildITB/bufferMem.cpp buildITB/Point.cpp -std=c++11
	
myZoom :
	g++ -o myZoom buildITB/color.cpp buildITB/bufferMem.cpp buildITB/mZoom.cpp buildITB/zoom.cpp -std=c++11
	
clean:
	$(RM) mycolor mybufferMem myLine myZoom
