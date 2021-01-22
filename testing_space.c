#include <stdio.h>

/* ---- ПОЛЕЗНИ ФУНКЦИИ ---- */
int findMSB(int iNumber);
void printInBinary(long long number, unsigned int bitsToPrint);

int main() {
    

    /* ---- СТАР КОД ---- */
    /*
    int numberToDecode = 10230;
    int mask = 0x1F;
    do {
        int currentNumber = numberToDecode & mask;
        printf("%d\n", currentNumber);
    } while ( numberToDecode >>= 5);
 */
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

void printInBinary(long long number, unsigned int bitsToPrint)
{
    unsigned int i = 1;
    for(i <<= bitsToPrint - 1; i > 0; i >>= 1) {
        if (i&number) printf("1");
        else printf("0");
    }
    printf("\n");
}