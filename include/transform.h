#include <iostream>
#include <bitset>
using namespace std;
//The find function returns -1 if not found.
void printBinary(int num) {
    cout << "Binary representation of " << num << " is: ";
    
    bitset<32> binary(num); // create a bitset with 32 bits and initialize it with num
    cout << binary.to_string().substr(binary.to_string().find('1')); // print the binary representation

    cout << endl;
}