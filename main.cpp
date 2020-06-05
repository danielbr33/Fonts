#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer* buffer = new Buffer(64, 32);
	buffer->addText((char*)"MESSAGE", Font7x10, 10, 5);
	buffer->addText((char*)"MESSAGE", Font6x8, 10, 15);
	buffer->clear();
	buffer->print();
	return 0;
}