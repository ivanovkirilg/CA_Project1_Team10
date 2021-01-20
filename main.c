#include <stdio.h>

unsigned int encodeNumbers(void);
void decodeNumber(unsigned int numberToDecode);
int decodeNumberReturnIterations(unsigned int numberToDecode);
void dcdNmbr(unsigned int n);

int main() {
    //unsigned int iNumber = encodeNumbers();
    decodeNumber(3376253299U);
    dcdNmbr(3376253299U);

    return 0;
}

void decodeNumber(unsigned int numberToDecode) {
    unsigned int mask = 0x1Fu;
    do {
        unsigned int currentNumber = numberToDecode & mask;
        printf("%d\n", currentNumber);
    } while (numberToDecode >>= 5);
}

unsigned int encodeNumbers(void) {
    int enteredNumber = 0;
    unsigned int encodedNumber = 0;
    for (int i=0; i<6; i++) {
        printf("Enter 5-bit number (0-31) for position %d: ", i*5);
        scanf("%d", &enteredNumber);
        if ((enteredNumber < 0) || (enteredNumber > 31)) {
            i--;
            continue;
        }
        encodedNumber |= enteredNumber << i*5;
    }
    do {
        printf("Enter 2-bit number (0-3) for position 30: ");
        scanf("%d", &enteredNumber);
    } while (enteredNumber < 0 || enteredNumber > 3);
    encodedNumber |= enteredNumber << 30;
    return encodedNumber;
}

int decodeNumberReturnIterations(unsigned int numberToDecode) {
    int mask = 0x1F;
    int iterations = 0;
    do {
        iterations++;
        unsigned int currentNumber = numberToDecode & mask;
        printf("%d\n", currentNumber);
    } while ( numberToDecode >>= 5);
    return iterations;
}

void dcdNmbr(unsigned int n) {
    do printf("%d ", (n << 27) >> 27);
    while ( n >>= 5);
}