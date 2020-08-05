#ifndef BUFFER_H
#define BUFFER_H

#include "Fonts.h"
#include <vector>

typedef enum { Font6x8, Font7x10, Font11x18 } Font;
typedef enum { Black, White } Color;
#define BUFFOR_PART_HEIGHT 8
#define BUFFOR_FILLED 255

class Buffer{

public:
	void print();
	Buffer(uint8_t buffer_width, uint8_t buffer_height);
	~Buffer();
	void addLetter(uint8_t letter, uint8_t height, Color color, uint8_t coord_X, uint8_t coord_Y);
	void addText(char *text, uint8_t height, Color color, uint8_t coord_X, uint8_t coord_Y);
	void createFont();
	void fill(Color color);
	uint8_t* getBuffer(uint8_t verse);

private:
	void findFont(uint8_t height);
	uint8_t** table;
	int buffer_width;
	int buffer_height;
	vector<Fonts*> Fonts;
	Fonts* ActualFont;
	uint8_t buffor_element_height;
};

#endif BUFFER_H

