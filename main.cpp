#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer* buffer = new Buffer(64, 32);
	buffer->addLetter('5',Font6x8,0,25);
	buffer->print();
	return 0;
}