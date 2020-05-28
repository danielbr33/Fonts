#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer* buffer = new Buffer(64, 32);
	buffer->addLetter('C',8,20,15);
	buffer->print();
	return 0;
}