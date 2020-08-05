#include "Buffer.h"
#include "bitoperations.h"
#include "string.h"
#include "ArduinoJson-v6.15.2.h"

void Buffer::fill(Color color) {
	for (uint8_t i = 0; i < this->buffer_height / BUFFOR_PART_HEIGHT; i++)
		for (uint8_t j = 0; j < this->buffer_width; j++) {
			if (color == White)
				table[i][j] = BUFFOR_FILLED;
			else
				table[i][j] = 0;
		}
}

/*void Buffer::print() {
	for (uint8_t i = 0; i < this->buffer_width; i++) {
		for (uint8_t k = 0; k < (this->buffer_height / BUFFOR_PART_HEIGHT); k++) {
			for (uint8_t j = 8; j > 0; j--) {
				if (getBit(table[i][k], j - 1) == 0)
					cout << "-";
				else
					cout << "+";
			}
		}
	}
	cout << endl;
}*/

void Buffer::print() {
	for (uint8_t i = 0; i < (this->buffer_height / BUFFOR_PART_HEIGHT); i++){
		for (int8_t j = 0; j < 8; j++) {
			for (uint8_t k = 0; k < this->buffer_width; k++){
				if (getBit(table[i][k], j))
					cout << "-";
				else
					cout << "+";
			}
			cout << endl;
		}
	}
}

uint8_t* Buffer::getBuffer(uint8_t verse){
	return this->table[verse];
}

Buffer::Buffer(uint8_t buffer_width, uint8_t buffer_height){
	this->buffer_height = buffer_height;
	this->buffer_width = buffer_width;
	table = new uint8_t* [this->buffer_height / BUFFOR_PART_HEIGHT];
	for (uint8_t i = 0; i < (this->buffer_height/BUFFOR_PART_HEIGHT); i++)
		table[i] = new uint8_t[this->buffer_width];
	for (uint8_t j=0; j < (this->buffer_height/BUFFOR_PART_HEIGHT); j++)
		for (uint8_t i = 0; i < this->buffer_width; i++)
			table[j][i] = 0;
	createFont();
}

Buffer::~Buffer(){
	delete[] table;
}

void Buffer::addLetter(uint8_t letter, uint8_t height, Color color, uint8_t coord_X, uint8_t coord_Y) {
	findFont(height);
	uint8_t number_of_verse = (uint8_t)(coord_Y/8);
	uint8_t offset = coord_Y % 8;
	uint8_t state;
	uint8_t writted_horizontal_bits;
	for (uint8_t i = 0; i < ActualFont->getWidth(); i++) {
		if (coord_X + i >= this->buffer_width)
			break;

		if (color == White) {
			if (number_of_verse < ((uint8_t)this->buffer_height / 8)) {
				table[number_of_verse][i + coord_X] = 0;
				table[number_of_verse][i+coord_X] |= (ActualFont->getLetter(letter)[i] << offset);
			}
			if ((number_of_verse + 1) < ((uint8_t)buffer_height / 8)) {
				table[number_of_verse + 1][i + coord_X] = 0;
				table[number_of_verse + 1][i + coord_X] |= (ActualFont->getLetter(letter)[i] >> (BUFFOR_PART_HEIGHT - offset));
			}
			if ((number_of_verse + 2) < ((uint8_t)buffer_height / 8)  && height == 18) {
				table[number_of_verse + 2][i + coord_X];
				table[number_of_verse + 2][i + coord_X] |= (ActualFont->getLetter(letter)[i] >> (2*BUFFOR_PART_HEIGHT - offset));
			}
		}

		else if (color == Black) {
			if (number_of_verse < ((uint8_t)this->buffer_height / 8)) {
				if (table[number_of_verse][i+coord_X] == 0)
					table[number_of_verse][i + coord_X] = ~0;
				table[number_of_verse][i + coord_X] &= ~(ActualFont->getLetter(letter)[i] << offset);
			}
			if ((number_of_verse + 1) < ((uint8_t)buffer_height / 8)) {
				if (table[number_of_verse + 1][i + coord_X] == 0)
					table[number_of_verse + 1][i + coord_X] = ~0;
				table[number_of_verse + 1][i + coord_X] &= ~(ActualFont->getLetter(letter)[i] >> (BUFFOR_PART_HEIGHT - offset));
			}
			if ((number_of_verse + 1) < ((uint8_t)buffer_height / 8) && height == 18) {
				if (table[number_of_verse + 2][i + coord_X] == 0)
					table[number_of_verse + 2][i + coord_X] = ~0;
				table[number_of_verse + 2][i + coord_X] &= ~(ActualFont->getLetter(letter)[i] >> (2*BUFFOR_PART_HEIGHT - offset));
			}
		}
	}
}

void Buffer::addText(char* text,  uint8_t height, Color color, uint8_t coord_X, uint8_t coord_Y) {
	findFont(height);
	for (uint8_t i = 0; i < strlen((char*)text); i++) {
		uint8_t current_X = coord_X + i * ActualFont->getWidth();
		addLetter(text[i], height, color, current_X, coord_Y);
	}
}

void Buffer::createFont() {
	const char* path = 0;
	//------------READING JSON----------------
	fstream json_file;
	json_file.open("doc.json", ios::in);
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
	JsonArray array = doc["fonts"];
	for (JsonObject repo : array) {
		path = repo["file"].as<const char*>();
		ActualFont = new Fonts();
		ActualFont->readFont(path);
		FontsAll.push_back(new Fonts(*ActualFont));
		delete ActualFont;
	}
}

void Buffer::findFont(uint8_t height) {
	uint8_t difference = 120;
	for (uint8_t i = 0; i < FontsAll.size(); i++) {
		if (fabs(FontsAll[i]->getHeight() - height) <= difference) {
			ActualFont = FontsAll[i];
			difference = fabs(FontsAll[i]->getHeight() - height);
			cout << (uint16_t)difference << endl;
		}
	}
}
