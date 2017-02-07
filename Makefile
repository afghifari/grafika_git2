all: myPlane

myPlane:
	gcc -o myPlane fill_plane/*.c -lpthread

clean:
	$(RM) myPlane