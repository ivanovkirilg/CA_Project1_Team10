#include <stdio.h>

int main() {
    
    return 0;
}

int findMSB(int iNumber) {
    unsigned int mask = 0x80000000;
    int bit = 0;
    int index = 31;
    for (bit = mask & iNumber; bit == 0 && index >= 0; index-- ){ 
        mask >>= 1u;
        bit = mask & iNumber;
    }
}