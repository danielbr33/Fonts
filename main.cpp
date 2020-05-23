#include <iostream>
#include "Buffer.h"
#include "bitoperations.h"

using namespace std;

uint8_t test = 0;

void printTest(){
	for(int i = 0; i < 8; i++){
		if(getBit(test, i)){
			cout << "+";
		} else {
			cout << "-";
		}
	}
	cout << endl;
}

int main() {
	Buffer buffer;
	buffer.print();

	cout << endl;

	printTest();
	for(int i = 0; i < 8; i++){
		setBit(test, i);
		printTest();
	}

	cout << endl;

	for(int i = 0; i < 8; i++){
		clearBit(test, i);
		printTest();
	}

	return 0;
}