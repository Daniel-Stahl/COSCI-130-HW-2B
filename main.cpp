// Daniel Stahl
// COSCI 130 HW 2B

#include <string>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

void show(unsigned n);
void wohs(unsigned n);
unsigned ones(unsigned n);
unsigned zeros(unsigned n);
unsigned f(unsigned n);
string addSpace(string& bit);

int main() {
    show(5645);
    wohs(5645);
    cout << "ones: " << ones(5645) << endl;
    cout << "zeros: " << zeros(5645) << endl;
    cout << "Function f: " << f(0x789ABCDEU) << endl;
}

void show(unsigned n) {
    vector<unsigned>binary;
    
    for (int x = 0; n > 0; x++) {
        binary.insert(binary.end()-x, n%2);
        n = n/2;
    }
    
    for (int x = 0; binary.size() != 32 ; x++) {
        binary.insert(binary.begin(), 0);
    }
    
    for (int x = 0; x < binary.size(); x++) {
        if (x == 8 || x == 16 || x == 24) {
            cout << " ";
        }
        
        cout << binary.at(x);
    }
    cout << "\n";
}

void wohs(unsigned n) {
    vector<unsigned>binary;
    
    for (int x = 0; n > 0; x++) {
        binary.insert(binary.end(), n%2);
        n = n/2;
    }
    
    for (int x = 0; binary.size() != 32 ; x++) {
        binary.insert(binary.end(), 0);
    }
    
    for (int x = 0; x < binary.size(); x++) {
        if (x == 8 || x == 16 || x == 24) {
            cout << " ";
        }
        
        cout << binary.at(x);
    }
    cout << "\n";
}

unsigned ones(unsigned n) {
    vector<unsigned>binary;
    unsigned ret = 0;
    
    for (int x = 0; n > 0; x++) {
        binary.insert(binary.end(), n%2);
        n = n/2;
        ret = (binary[x] == 1) ? ret + 1 : ret + 0;
    }
    
    return ret;
}

unsigned zeros(unsigned n) {
    vector<unsigned>binary;
    unsigned ret = 0;
    
    for (int x = 0; n > 0; x++) {
        binary.insert(binary.end(), n%2);
        n = n/2;
    }
    
    for (int x = 0; binary.size() != 32 ; x++) {
        binary.insert(binary.end(), 0);
    }
    
    for (int x = 0; x < binary.size(); x++) {
        ret = (binary[x] == 0) ? ret + 1 : ret + 0;
    }
    
    return ret;
}

unsigned f(unsigned n) {
    n |= 0x00FF0000U;
    n &= 0xFFFF00FFU;
    n ^= 0x000000FFU;
    
    return n;
}
