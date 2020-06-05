#ifndef FONTS_H
#define FONTS_H

#include "Letter.h"
using namespace std;

class Fonts{

public:
	void createFont6x8();
	void createFont7x10();
	uint16_t* getLetter(uint8_t letter);
	uint8_t getWidth();
	uint8_t getHeight();

private:
	Letter** Font_6x8;
	Letter** Font_7x10;
	uint8_t height;
	uint8_t width;
};

#endif FONTS_H

