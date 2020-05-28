#include "Buffer.h"
#include <iostream>
#include "bitoperations.h"
using namespace std;

void Buffer::print() {
	for (uint8_t i = 0; i < this->height; i++) {
		for (uint8_t k = 0; k < (width/this->buffor_element_width); k++) {
			for (uint8_t j = 8; j > 0; j--) {
				if (getBit(table[k][i], j - 1) == 0)
					cout << "-";
				else
					cout << "+";
			}
		}
		cout << endl;
	}
}

Buffer::Buffer(){
	this->height = 32;
	this->width = 64;
	this->buffor_element_width=8;
	table = new uint8_t* [width/this->buffor_element_width];
	for (uint8_t i = 0; i < (width / this->buffor_element_width); i++)
		table[i] = new uint8_t[height];
	for (uint8_t j=0; j < (width/this->buffor_element_width); j++)
		for (uint8_t i = 0; i < height; i++)
		table[j][i] = 0;
	font6x8_ready = 0;
	font7x10_ready = 0;
}

Buffer::~Buffer(){
	delete[] table;
}

void Buffer::addLetter(uint8_t letter, uint8_t height, uint8_t coord_X, uint8_t coord_Y) {
	uint16_t number_of_collumn = (uint16_t)(coord_X/8);
	uint16_t offset = coord_X % 8;
	cout << endl << number_of_collumn << endl;
	cout << offset << endl;
	if (height == 8) {
		if (font6x8_ready == 0) {
			Font_6x8 = new Fonts();
			Font_6x8->createFont6x8();
			font6x8_ready = 1;
		}
		for (uint8_t i = 0; i < height; i++) {
			table[number_of_collumn][i + coord_Y] |= (Font_6x8->getLetter6x8(letter)[i] >> (this->buffor_element_width + offset));
			if (offset != 0)
				table[number_of_collumn + 1][i + coord_Y] |= (Font_6x8->getLetter6x8(letter)[i] >> 8 << (this->buffor_element_width-offset));
		}
	}
	/*
	else if (height == 10) {
		if (font7x10_ready == 0) {
			Font_7x10 = new Fonts();
			Font_7x10->createFont6x8();
			font7x10_ready = 1;
		}
		for (uint8_t i = 0; i < height; i++) {
			table[i + coord_Y] |= (Font_7x10->getLetter7x10(letter)[i] << (64-16-coord_X));
		}
	}
	*/
}
