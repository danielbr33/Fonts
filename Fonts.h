#ifndef FONTS_H
#define FONTS_H

#include "Letter.h"
#include <fstream>
#include <tchar.h>
#include <string>
#include <cstring>
#include <Windows.h>
using namespace std;

class Fonts{

public:
	void readFont(string font);
	uint32_t* getLetter(uint8_t letter);
	uint8_t getWidth();
	uint8_t getHeight();
	void createFont();

private:
	Letter** FontLetter;
	uint16_t* fontTable;
	uint16_t height;  //error after change on uint8_t
	uint16_t width;
};

#endif FONTS_H

