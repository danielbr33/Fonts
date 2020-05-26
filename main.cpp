#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer buffer;
	buffer.addLetter('B',8,20,0);
	buffer.print();

	cout << endl;

	uint64_t number = 0;
	number |= 8192;
	cout << (number) << endl;
	return 0;
}