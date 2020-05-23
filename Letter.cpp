#include "Letter.h"

Letter::Letter(uint16_t* tab, uint8_t height, uint8_t width) {
	this->height = height;
	this->width = width;
	this->letter = new uint16_t[height];
	for (uint8_t i = 0; i < height; i++)
		this->letter[i] = tab[i] << MAX_WIDTH - width;
}