#pragma once
#include "Fonts.h"
class Buffer{
public:
	void print();
	Buffer();
	~Buffer();
	void addLetter(uint8_t letter, uint8_t height, uint8_t coord_X, uint8_t coord_Y);
private:
	int** table;
	int width;
	int height;
};

