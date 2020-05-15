#include "Letter.h"
int Letter::convertToInt(std::string bin_number) {
	int dec = 0;
	for (uint8_t i = 0; i < bin_number.size(); i++)
		if (bin_number[i] == '1') dec += pow(2, bin_number.size() - i - 1);
	return dec;
}

Letter::Letter(string* letter, uint8_t height, uint8_t width) {
	this->height = height;
	this->width = width;
	this->tab = new uint16_t[height];
	for (uint8_t i = 0; i < height; i++)
		tab[i] = convertToInt(letter[i])<<10;
}