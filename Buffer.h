#pragma once
#include "Fonts.h"
class Buffer{
public:
	void print();
	Buffer();
	~Buffer();
	void addLetter(uint8_t letter, uint8_t height, uint8_t coord_X, uint8_t coord_Y);
private:
	uint8_t** table;
	int width;
	int height;
	Fonts* Font_6x8;
	Fonts* Font_7x10;
	uint8_t font6x8_ready;
	uint8_t font7x10_ready;
	uint8_t buffor_element_width;
};

