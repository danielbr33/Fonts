#include "Fonts.h"
#include "bitoperations.h"
#include <string>
static uint16_t Font6x8[96 * 6];
static uint16_t Font7x10[96 * 7];
static uint16_t Font11x18[96 * 11];

void Fonts::readFont(fstream& plik, uint16_t* font, int height, int width) {
	for (uint16_t i = 0; i < (96 * width - 1); i++)
		font[i] = 0;
	char temp;
	for (int i = 0; i < 95; i++) {
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				do {
					plik >> temp;
				}
				while (temp != '-' && temp != '#');
				if (temp == '#') {
					setBit3(font[i * width + k], j);
				}
				else {
					clearBit3(font[i * width + k], j);
				}
			}
		}
		plik >> temp;
	}
}

void Fonts::createFont11x18() {
	this->width = 11;
	this->height = 18;	
	fstream plik;
	plik.open("Font11x18.txt", ios::in);
	readFont(plik, Font11x18, this->height, this->width);
	Font_11x18 = new Letter * [95];
	for (uint8_t i = 0; i < 95; i++) {
		Font_11x18[i] = new Letter(&Font11x18[i * width], height, width);
	}	
	plik.close();
}

void Fonts::findFilesFromFolder(string folder_path, string search) {
	HANDLE hFile = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATAA   file_data;
	hFile = FindFirstFileA((LPCSTR)folder_path.c_str(), &file_data);
	if (hFile == INVALID_HANDLE_VALUE)
		cout << "error";
	cout << file_data.cFileName;
}

void Fonts::createFont6x8() {
	string chFolder_path = "C:\\Users\\danie\\git\\Fonts\\*.txt";
	findFilesFromFolder(chFolder_path, "Font6x8");

	this->width = 6;
	this->height = 8;
	fstream plik;
	plik.open("Font6x8.txt", ios::in);
	readFont(plik, Font6x8, this->height, this->width);
	Font_6x8 = new Letter* [95];
	for (uint8_t i = 0; i < 95; i++) {
		Font_6x8[i] = new Letter(&Font6x8[i * width], height, width);
	}
	plik.close();
}

void Fonts::createFont7x10() {
	this->width = 7;
	this->height = 10;
	fstream plik;
	plik.open("Font7x10.txt", ios::in);
	readFont(plik, Font7x10, this->height, this->width);
	Font_7x10 = new Letter* [95];
	for (uint8_t i = 0; i < 95; i++) {
		Font_7x10[i] = new Letter(&Font7x10[i * width], height, width);
	}
	plik.close();
}

uint32_t* Fonts::getLetter(uint8_t letter) {
	if (this->height == 8)
		return Font_6x8[letter - 32]->getLetter();
	else if (this->height == 10)
		return Font_7x10[letter - 32]->getLetter();
	else if (this->height == 18)
		return Font_11x18[letter - 32]->getLetter();
}

uint8_t Fonts::getWidth() {
	return this->width;
}

uint8_t Fonts::getHeight() {
	return this->height;
}
