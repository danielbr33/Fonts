#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer* buffer = new Buffer(80, 40);
	buffer->addText((char*)"MESSAGE", Font11x18, White, 2, 6);
	//buffer->fill(White);
	buffer->print();
	return 0;
}