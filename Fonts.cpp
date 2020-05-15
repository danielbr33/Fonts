#include "Fonts.h"
#include <iostream>

void Fonts::print() {
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

Fonts::Fonts() {
	this->height = 32;
	this->width = 64;
	table = new int* [height];
	for (int i = 0; i < height; i++)
		table[i] = new int[width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			table[i][j] = 0;
}

Fonts::~Fonts() {
	for (int i = 0; i < height; i++)
		delete[] table[i];
	delete[] table;
}
