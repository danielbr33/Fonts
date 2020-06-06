#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer* buffer = new Buffer(80, 40);
	buffer->addText((char*)"MESSAGE", Font11x18, White, 2, 0);
	buffer->addText((char*)"MESSAGE", Font7x10, Black, 5, 18);
	buffer->addText((char*)"MESSAGE", Font6x8, White, 10, 28);
	//buffer->fill(White);
	buffer->print();
	return 0;
}