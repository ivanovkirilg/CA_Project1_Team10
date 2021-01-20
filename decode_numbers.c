#include <stdio.h>

int findMSB(int iNumber);

int main() {
    int numberToDecode = 10230;
    int mask = 0x1F;

    do {
        int currentNumber = numberToDecode & mask;
        printf("%d\n", currentNumber);
    } while ( numberToDecode >>= 5);

    /* int iterations = 0;
    iterations = findMSB(numberToDecode) / 5;
    printf("msb: %d\n", findMSB(numberToDecode));
    if (findMSB(numberToDecode) % 5) {
        iterations++;
    }
    printf("%d\n", iterations); */
    
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
    return index;
}