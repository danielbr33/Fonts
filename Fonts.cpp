#include "Fonts.h"
#include "bitoperations.h"
#include <string>
#include "ArduinoJson-v6.15.2.h"
static uint16_t Font6x8[96 * 6];
static uint16_t Font7x10[96 * 7];
static uint16_t Font11x18[96 * 11];

void Fonts::createFont(string font, uint16_t* font_table) {
	Actual_Font = new Letter * [95];
	for (uint8_t i = 0; i < 95; i++) {
		Actual_Font[i] = new Letter(&font_table[i * width], height, width);
	}
	if (font == "Font6x8")
		Font_6x8 = Actual_Font;
	else if (font == "Font7x10")
		Font_7x10 = Actual_Font;
	else if (font == "Font11x18")
		Font_11x18 = Actual_Font;
}

void Fonts::readFont(string font) {
	//------------READING JSON----------------
	fstream json_file;
	json_file.open("doc.txt", ios::in);
	string json_string = " ";
	if (json_file) {
		string line;
		while (getline(json_file, line)) {
			json_string += line;
		}
		json_file.close();
	}
	const int capacity = JSON_OBJECT_SIZE(3); 
	DynamicJsonDocument doc(1024);
	DeserializationError error = deserializeJson(doc, json_string);
	if (error)
		cout << error.c_str();
	const char* path = doc[font.c_str()]["file"];
	cout << path << endl;
	fstream file;
	file.open((string)path, ios::in);
	//------------**************----------------

	file >> this->width;
	file >> this->height;
	cout << "width=" << this->width << endl;
	cout << "height=" << this->height << endl;
	uint16_t* Font;
	Font = new uint16_t[96 * this->width];
	if (font == "Font6x8")
		Font = Font6x8;
	if (font == "Font7x10")
		Font = Font7x10;
	if (font == "Font11x18")
		Font = Font11x18;
	for (uint16_t i = 0; i < (96 * this->width - 1); i++)
		Font[i] = 0;
	char temp;
	for (int i = 0; i < 95; i++) {
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				do {
					file >> temp;
				}
				while (temp != '-' && temp != '#');
				if (temp == '#') {
					setBit3(Font[i * width + k], j);
				}
				else {
					clearBit3(Font[i * width + k], j);
				}
			}
		}
		file >> temp;
	}
	file.close();
	createFont(font, Font);
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
