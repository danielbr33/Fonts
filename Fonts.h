#pragma once
#include <iostream>
#include <cstdint>
#include "Letter.h"
using namespace std;

class Fonts{
public:
	void createFont6x8();
	void createFont7x10();
private:
	Letter** Font_6x8;
	Letter** Font_7x10;
};

