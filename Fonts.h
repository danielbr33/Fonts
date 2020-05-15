#pragma once
#include <iostream>
#include <cstdint>
using namespace std;

struct Font_6x8 {
	uint8_t height;
	uint8_t width;
	string tab[8];
};

//Font_6x8 A = {6, 8, {"001100","010010", "010010", "100001", "111111", "110011", "100001", "100001"}};

class Fonts{
public:
	Fonts();
	virtual ~Fonts();
	void print();

private:
	int** table;
	int width;
	int height;
};

