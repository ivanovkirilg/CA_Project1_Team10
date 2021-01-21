/*  Направете функция, която получава като параметър число. 
    Неговите битове ще третираме по следния начин - 
    първите 5 бита (най-младшите) представляват едно число(5 bit-ово), 
    следващите 5 - друго число и тн. 
    Изведете на стандартния изход числата, "закодирани" в оригиналното число. */

#include <stdio.h>

void decodeNumber(void); // <---------- основната функция за задачата
void dcdNmbr(unsigned int n);
unsigned int encodeNumbers(void);

int main() {
    decodeNumber();

    return 0;
}

void decodeNumber(void) {
    unsigned int numberToDecode;
    printf("\nEnter number:\n");
    scanf("%d",  &numberToDecode); 
    unsigned int mask = 0x1Fu; // Построяване на маска  ... 0000 0001 1111
    do {
        unsigned int currentNumber = numberToDecode & mask; 
        printf("%d ", currentNumber);
    } while ( numberToDecode >>= 5);    // do ще се изпълнява докато числото не стане 0
    return;                             // като на всеки цикъл го измества надясно
}

void dcdNmbr(unsigned int n) {
    do printf("%d ", (n << 27) >> 27);  // трием левите битове и връщаме числото в началото
    while ( n >>= 5);                   // докато числото не стане 0
}

unsigned int encodeNumbers(void) {
    int enteredNumber = 0;          // числото, което въвежда потребителят
    unsigned int encodedNumber = 0; // числото, което ще върнем
    for (int i=0; i<6; i++) {       // цикълът минава през всяка позиция, след която има 5 свободни бита
        printf("Enter 5-bit number (0-31) for position %d: ", i*5);
        scanf("%d", &enteredNumber);
        if ((enteredNumber < 0) || (enteredNumber > 31)) {  // ако потребителят въведе невалидно число,
            i--;                                            // оставаме на същата позиция
            continue;
        }
        encodedNumber |= enteredNumber << i*5;  // записваме въведеното 5-битово число
    }
    do {
        printf("Enter 2-bit number (0-3) for position 30: ");
        scanf("%d", &enteredNumber);
    } while (enteredNumber < 0 || enteredNumber > 3);
    encodedNumber |= enteredNumber << 30;
    return encodedNumber;
}
