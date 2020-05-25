#include "Buffer.h"
#include <iostream>
using namespace std;

void Buffer::print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (table[i][j] == 0)
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
	table = new int* [height];
	for (int i = 0; i < height; i++)
		table[i] = new int[width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			table[i][j] = 0;
}

Buffer::~Buffer(){
	for (int i = 0; i < height; i++)
		delete[] table[i];
	delete[] table;
}

void Buffer::addLetter(uint8_t letter, uint8_t height, uint8_t coord_X, uint8_t coord_Y) {
	for (uint8_t i = 0; i < height; i++) {
	//	table[i + coord_Y][coord_X] |=
	}
}
