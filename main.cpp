#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer* buffer = new Buffer(80, 40);
	buffer->fill(White);
	buffer->addText((char*)"MESSAGE", Font11x18, Black, 2, 6);
	buffer->addText((char*)"MESSAGE", Font7x10, White, 2, 26);
	buffer->print();
	return 0;
}