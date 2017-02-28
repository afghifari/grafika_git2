all: clean mycolor mybufferMem myLine

mycolor:
	g++ -o myColor buildITB/mColor.cpp buildITB/color.cpp -std=c++11

mybufferMem :
	g++ -o mybufferMem buildITB/color.cpp buildITB/bufferMem.cpp buildITB/mBufferMem.cpp -std=c++11

myLine:
	g++ -o myLine buildITB/mLine.cpp buildITB/line.cpp buildITB/color.cpp buildITB/bufferMem.cpp buildITB/Point.cpp -std=c++11
clean:
	$(RM) mycolor mybufferMem myLine
