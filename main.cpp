#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer* buffer = new Buffer(64, 32);
	buffer->addText((char*)"MESSAGE", Font6x8, 15, 20);
	buffer->print();
	return 0;
}