#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer* buffer = new Buffer(80, 40);
	buffer->addText((char*)"MESSAGE", Font11x18, 2, 0);
	buffer->addText((char*)"MESSAGE", Font7x10, 5, 16);
	buffer->addText((char*)"MESSAGE", Font6x8, 10, 26);
	buffer->print();
	return 0;
}