#include <stdio.h>

int main() {

    int iNumber = 0xAF; // 1010 1111 -> трябва ни позиция 7
    
    unsigned int mask = 0x80000000; // 1000 0000 ...    
    int bit = 0;                    // СТОЙНОСТТА на бита, който проверяваме
    int index = 31;                 // ПОЗИЦИЯТА на бита, който проверяваме

    for (bit = mask & iNumber; bit == 0 && index >= 0; index-- ){ 
        mask >>= 1u;            // Изместваме маската, за да проверим следващия бит
        bit = mask & iNumber;   // записваме стойността му
    } 
    // Ако числото е 0, т.е. няма нито един бит със стойност 1, получаваме -1

    printf("%d", index);

    return 0;
}