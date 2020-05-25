#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;


int main() {
	Buffer buffer;
	buffer.addLetter('a',8,1,5);
	buffer.print();

	cout << endl;
	return 0;
}