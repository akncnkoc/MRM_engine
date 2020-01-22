g++ -c graphics/window.cpp &&
g++ -c main.cpp &&
g++ main.o window.o -o main -lGL -lGLU -lglut -lGLEW -lglfw &&
./main