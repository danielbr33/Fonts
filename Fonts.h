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
	uint8_t findFontFromFolder(string folder_path, fstream& file, string search);
	void createFont(string font, uint16_t* font_table);

private:
	Letter** Font_6x8;
	Letter** Font_7x10;
	Letter** Font_11x18;
	Letter** Actual_Font;
	uint16_t height;  //error after change on uint8_t
	uint16_t width;
};

#endif FONTS_H

