#pragma once
#include <cstdint>
#include "math.h"
#include <iostream>
using namespace std;
#define MAX_WIDTH 16
class Letter{
public:
	Letter(uint16_t* tab, uint8_t height, uint8_t width);
	~Letter();
	uint16_t* getLetter();
private:
	uint8_t width;
	uint8_t height;
	uint16_t* letter_tab;
};

