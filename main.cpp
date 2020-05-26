#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer buffer;
	buffer.addLetter('B',8,0,15);
	buffer.print();
	return 0;
}