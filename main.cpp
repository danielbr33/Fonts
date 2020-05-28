#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer buffer;
	buffer.addLetter('C',8,20,15);
	buffer.print();
	cout << endl << (int8_t)5%3 << endl;
	return 0;
}