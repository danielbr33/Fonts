#pragma once
class Buffer{
public:
	void print();
	Buffer();
	~Buffer();
private:
	int** table;
	int width;
	int height;
};

