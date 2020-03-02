// Daniel Stahl
// COSCI 130 HW 2B

#include <string>
#include <iostream>
#include <bitset>

using namespace std;

void show(unsigned n);
void wohs(unsigned n);
unsigned ones(unsigned n);
unsigned zeros(unsigned n);
unsigned f(unsigned n);
string addSpace(string& bit);

int main() {
    show(256+12);
    wohs(256+12);
    cout << "ones: " << ones(256+12) << endl;
    cout << "zeros: " << zeros(256+12) << endl;
    cout << "Binary: " << f(3902657940) << endl;
}

void show(unsigned n) {
    string binary = bitset<32>(n).to_string();
    cout << addSpace(binary) << endl;
}

void wohs(unsigned n) {
    string reverseBinary = bitset<32>(n).to_string();
    reverse(reverseBinary.begin(), reverseBinary.end());
    cout << addSpace(reverseBinary) << endl;
}

unsigned ones(unsigned n) {
    string binary = bitset<32>(n).to_string();
    unsigned ret = 0;
    
    for (int x = 0; x < binary.size(); x++) {
        ret = (binary[x] == '1') ? ret + 1 : ret + 0;
    }
    
    return ret;
}

unsigned zeros(unsigned n) {
    string binary = bitset<32>(n).to_string();
    unsigned ret = 0;
    
    for (int x = 0; x < binary.size(); x++) {
        ret = (binary[x] == '0') ? ret + 1 : ret + 0;
    }
    
    return ret;
}

unsigned f(unsigned n) {
    n |= 0x00FF0000U;
    n &= 0xFFFF00FFU;
    n ^= 0x000000FFU;
    
    return n;
}

string addSpace(string& byte) {
    int x = 8;
    int y = byte.size();
    
    while (x < y) {
        byte.insert(x, " ");
        x = x + 9;
    }

    return byte;
}
