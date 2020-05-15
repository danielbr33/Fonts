#pragma once
#include <cstdint>
#include "math.h"
#include <iostream>
using namespace std;
#define MAX_WIDTH 16
class Letter{
public:
	Letter(string* letter, uint8_t height, uint8_t width);
	~Letter();
	int convertToInt(std::string bin_number);
private:
	uint8_t width;
	uint8_t height;
	uint16_t* tab;
};

