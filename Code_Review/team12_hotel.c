#include <stdio.h>
#include <time.h>
#include <string.h>

int validDate();

int main()
{
    double luxRoomPrice = 180;
    double standartRoomPrice = 120;

    printf("Welcome to hotel Sunrise!\n");
    printf("In our hotel we have luxury and standard rooms.\n");
    printf("Please make your choice!\n");

    char choice = 0;
    unsigned short int roomsLuxury = 0;
    unsigned short int roomsLuxuryTotal = 0;
    unsigned short int nightsLuxury = 0;
    unsigned short int nightsLuxuryTotal = 0;
    unsigned short int roomStandart = 0;
    unsigned short int roomStandartTotal = 0;
    unsigned short int nightsStandart = 0;
    unsigned short int nightsStandartTotal = 0;
    double subTotal = 0;
    float toristTax = 0;
    double total = 0;

    while (choice != '3')
    {
        printf("######################\nFor luxury room type 1.\n");
        printf("For standart room type 2.\n");
        printf("For exit type 3.\n######################\n");
        scanf("%s", &choice);
        if (choice == '1')
        {
            printf("Your choice is Luxury room.\n");
            printf("How many nights you are going to stay?\n");
            scanf("%d", &nightsLuxury);
            printf("How many luxury rooms would you like?\n");
            scanf("%d", &roomsLuxury);
            subTotal = (subTotal + (nightsLuxury * luxRoomPrice * roomsLuxury));
            roomsLuxuryTotal = roomsLuxury + roomsLuxuryTotal;
            nightsLuxuryTotal = nightsLuxury * roomsLuxury + nightsLuxuryTotal;
            printf("Your bill is  %.2f leva.\n", subTotal);
        }
        else if (choice == '2')
        {
            printf("Your choice is Standart room.\n");
            printf("How many nights you are going to stay?\n");
            scanf("%d", &nightsStandart);
            printf("How many standart rooms would you like?\n");
            scanf("%d", &roomStandart);
            subTotal = (subTotal + (nightsStandart * standartRoomPrice * roomStandart));
            roomStandartTotal = roomStandart + roomStandartTotal;
            nightsStandartTotal = nightsStandart * roomStandart + nightsStandartTotal;
            printf("Your bill is  %.2f leva.\n", subTotal);
        }
        else if (choice == '3')
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
    unsigned short int totalNights = 0;
    totalNights = nightsStandartTotal + nightsLuxuryTotal;

    if (totalNights > 5 && subTotal < 700)
    {
        printf("You get 15 percent discount.\n");
        double discount1 = subTotal * 0.15;
        printf("Your discount is %.2f leva.\n", discount1);
        subTotal = subTotal - discount1;
        printf("Your bill with discount is: %.2f leva.\n", subTotal);
        goto finalOffer;
    }

    else if (subTotal > 700 && subTotal < 1000)
    {
        printf("You can choose between 15 percent discount and free spa procedure for 100 leva.\n");
        printf("For 15 percent discount type 1.\n");
        printf("For free spa procedure for 100 leva type 2.\n");
        double discount2 = 0;
        char ch2 = 0;
        scanf("%d", &ch2);

        switch (ch2)
        {
            case 1:
            
                printf("You get 15 percent discount.\n");
                discount2 = subTotal * 0.15;
                printf("Your discount is %.2f leva.\n", discount2);
                subTotal = subTotal - discount2;
                printf("Your bill with discount is: %.2f leva.\n", subTotal);
                goto finalOffer;
                break;

            case 2:
                printf("You get a spa procedure for 100 leva.\n");
                goto finalOffer;
                break;
        }
    }

    else if (subTotal > 1000)
    {
        printf("You can choose between 20 percent discount, free spa procedure for 100 leva and 2 free dinners for your family.\n");
        printf("For 20 percent discount type 1.\n");
        printf("For free spa procedure for 100 leva type 2.\n");
        printf("For 2 free dinners for your family type 3.\n");
        double discount3 = 0;
        char ch3 = 0;
        scanf("%d", &ch3);

        switch (ch3)
        {
            case 1:
            
                 printf("You get 20 percent discount.\n");
                 discount3 = subTotal * 0.20;
                 printf("Your discount is %.2f leva.\n", discount3);
                 subTotal = subTotal - discount3;
                 printf("Your bill with discount is: %.2f leva.\n", subTotal);
                 goto finalOffer;
                 break;

            case 2:
                 printf("You get a spa procedure for 100 leva.\n");
                 goto finalOffer;
                 break;

            case 3:
                printf("You get 2 free dinners for your family.\n");
                goto finalOffer;
                break;
        }
    }
    else
    {   
            goto finalOffer;     
    }

    finalOffer:
        toristTax = subTotal * 0.06;
        printf("You owe tourist tax: %.2f leva.\n", toristTax);
        total = subTotal + toristTax;
        printf("######################\nYour final offer is:\n");
        printf("Standart rooms: %d\n", roomStandartTotal);
        printf("Luxury rooms: %d\n", roomsLuxuryTotal);
        printf("Total nights: %d\n", totalNights);
        printf("Final bill: %.2f leva\n######################\n", total);
        validDate();

   return 0;
}
 int validDate(){
    long long int t;
    t=time(NULL);
    t+=14*24*60*60;
    printf("Offer is valid until %s", ctime(&t) );
}
