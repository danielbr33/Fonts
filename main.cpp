#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer* buffer = new Buffer(80, 40);
	buffer->fill(White);
	buffer->addText((char*)"MESSAGE", 5, Black, 0, 2);
	buffer->addText((char*)"MESSAGE", 11, Black, 0, 12);
	buffer->addText((char*)"MESSAGE", 15, Black, 0, 24);
	buffer->print();
	return 0;
}