#pragma once
#include <iostream>
#include <cstdint>
#include "Letter.h"
using namespace std;

class Fonts{
public:
	void createFont6x8();
	void createFont7x10();
	uint16_t* getLetter6x8(uint8_t letter);
	uint16_t* getLetter7x10(uint8_t letter);
private:
	Letter** Font_6x8;
	Letter** Font_7x10;
};

