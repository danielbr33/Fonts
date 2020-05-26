#include "Buffer.h"
#include <iostream>
#include "bitoperations.h"
using namespace std;

void Buffer::print() {
	for (uint8_t i = 0; i < this->height; i++) {
		for (uint8_t j = width; j > 0; j--) {
			if (getBit(table[i], j-1) == 0)
				cout << "-";
			else
				cout << "+";
		}
		cout << endl;
	}
}

Buffer::Buffer(){
	this->height = 32;
	this->width = 64;
	table = new uint64_t [height];
	for (uint8_t i = 0; i < height; i++)
		table[i] = 0;
	font6x8_ready = 0;
	font7x10_ready = 0;
}

Buffer::~Buffer(){
	delete[] table;
}

void Buffer::addLetter(uint8_t letter, uint8_t height, uint8_t coord_X, uint8_t coord_Y) {
	if (height == 8) {
		if (font6x8_ready == 0) {
			Font_6x8 = new Fonts();
			Font_6x8->createFont6x8();
			font6x8_ready = 1;
		}
		for (uint8_t i = 0; i < height; i++) {
			table[i + coord_Y] |= (uint64_t)Font_6x8->getLetter6x8(letter)[i];
		}
	}

	else if (height == 10) {
		if (font7x10_ready == 0) {
			Font_7x10 = new Fonts();
			Font_7x10->createFont6x8();
			font7x10_ready = 1;
		}
		for (uint8_t i = 0; i < height; i++) {
			table[i + coord_Y] |= Font_7x10->getLetter7x10(letter)[i];
		}
	}
}
