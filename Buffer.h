#ifndef BUFFER_H
#define BUFFER_H

#include "Fonts.h"

typedef enum { Font6x8, Font7x10, Font11x18 } Font;
#define BUFFOR_PART_WIDTH 8

class Buffer{

public:
	void print();
	Buffer(uint8_t buffer_width, uint8_t buffer_height);
	~Buffer();
	void addLetter(uint8_t letter, Font, uint8_t coord_X, uint8_t coord_Y);
	void addText(char *text, Font, uint8_t coord_X, uint8_t coord_Y);
	void createFont(Font font);
	void clear();

private:
	uint8_t** table;
	int buffer_width;
	int buffer_height;
	Fonts* Font_6x8;
	Fonts* Font_7x10;
	Fonts* Font_11x18;
	Fonts* Actual_Font;
	uint8_t font6x8_ready;
	uint8_t font7x10_ready;
	uint8_t font11x18_ready;
	uint8_t buffor_element_width;
};

#endif BUFFER_H

