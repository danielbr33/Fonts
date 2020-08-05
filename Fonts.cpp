#include "Fonts.h"
#include "bitoperations.h"
#include <string>

void Fonts::createFont() {
	FontLetter = new Letter * [95];
	for (uint8_t i = 0; i < 95; i++) {
		FontLetter[i] = new Letter(&fontTable[i * width], height, width);
	}
}

void Fonts::readFont(string path) {
	fstream file;
	file.open(path, ios::in);
	//------------**************----------------
	file >> this->width;
	file >> this->height;
	fontTable = new uint16_t[96 * this->width];
	for (uint16_t i = 0; i < (96 * this->width - 1); i++)
		fontTable[i] = 0;
	char temp;
	for (int i = 0; i < 95; i++) {
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				do {
					file >> temp;
				}
				while (temp != '-' && temp != '#');
				if (temp == '#') {
					setBit3(fontTable[i * width + k], j);
				}
				else {
					clearBit3(fontTable[i * width + k], j);
				}
			}
		}
		file >> temp;
	}
	file.close();
	createFont();
}

uint32_t* Fonts::getLetter(uint8_t letter) {
	return FontLetter[letter - 32]->getLetter();
}

uint8_t Fonts::getWidth() {
	return this->width;
}

uint8_t Fonts::getHeight() {
	return this->height;
}
