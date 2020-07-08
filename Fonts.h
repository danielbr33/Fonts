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
	void readFont(fstream& plik, uint16_t* font, int height, int width);
	void createFont6x8();
	void createFont7x10();
	void createFont11x18();
	uint32_t* getLetter(uint8_t letter);
	uint8_t getWidth();
	uint8_t getHeight();
	void findFilesFromFolder(string folder_path, string search);

private:
	Letter** Font_6x8;
	Letter** Font_7x10;
	Letter** Font_11x18;
	uint8_t height;
	uint8_t width;
};

#endif FONTS_H

