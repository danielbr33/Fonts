all: compile

compile:
#linux
	g++ -o fonts -Wall *.cpp
#windows
#g++ -o fonts.exe -Wall *.cpp

run:
	./main
