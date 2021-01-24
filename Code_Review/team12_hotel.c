#include <stdio.h>
#include <time.h>
#include <string.h>

#define SECONDS_TO_DAYS 24*60*60
#define SEPARATOR "######################\n"

int validDate();
void chooseRooms(char type[], unsigned short int *number, unsigned short int *nights);

int main()
{
    const double c_luxuryRoomPrice = 180;
    const double c_standardRoomPrice = 120;

    unsigned short int roomsLuxury = 0;
    unsigned short int nightsLuxury = 0;
    unsigned short int roomsStandard = 0;
    unsigned short int nightsStandard = 0;
    double subTotal = 0;
    float touristTax = 0;
    double total = 0;

    char choice = 0;
    printf("\nWelcome to hotel Sunrise!\n");
    printf("In our hotel we have Luxury and Standard rooms.\n");
    printf("Please make your choice!\n");

    while (choice != '3')
    {
        printf(SEPARATOR);
        printf("For Luxury rooms type 1.\n");
        printf("For Standard rooms type 2.\n");
        printf("To exit type 3. ");
        scanf(" %c", &choice);
        printf(SEPARATOR);

        switch (choice) {
            case '1':
                chooseRooms("Luxury", &roomsLuxury, &nightsLuxury);
                subTotal = roomsStandard * nightsStandard * c_standardRoomPrice;
                subTotal += roomsLuxury * nightsLuxury * c_luxuryRoomPrice;
                printf("Your current bill is %.2f leva.\n", subTotal);
                break;

            case '2':
                chooseRooms("Standard", &roomsStandard, &nightsStandard);
                subTotal = roomsStandard * nightsStandard * c_standardRoomPrice;
                subTotal += roomsLuxury * nightsLuxury * c_luxuryRoomPrice;
                printf("Your current bill is %.2f leva.\n", subTotal);
                break;

            case '3':
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    unsigned short int totalNights = 0;
    totalNights = nightsStandard + nightsLuxury;

    if (totalNights > 5 && subTotal < 700)
    {
        printf("You get a 15 percent discount.\n");
        double discount1 = subTotal * 0.15;
        printf("Your discount is %.2f leva.\n", discount1);
        subTotal = subTotal - discount1;
        printf("Your bill after discount is: %.2f leva.\n", subTotal);
        goto finalOffer;
    }

    else if (subTotal > 700 && subTotal < 1000)
    {
        printf("You can choose between a 15 percent discount and a free spa procedure for 100 leva.\n");
        printf("For a 15 percent discount type 1.\n");
        printf("For a free spa procedure type 2. ");
        double discount2 = 0;
        char choice2 = 0;
        scanf("%c", &choice2);

        while (! (choice2=='1' || choice2=='2') ) {
            switch (choice2)
            {
                case '1':
                    printf("You get a 15 percent discount.\n");
                    discount2 = subTotal * 0.15;
                    printf("Your discount is %.2f leva.\n", discount2);
                    subTotal = subTotal - discount2;
                    printf("Your bill after discount is: %.2f leva.\n", subTotal);
                    goto finalOffer;
                    break;

                case '2':
                    printf("You get a free spa procedure for 100 leva.\n");
                    goto finalOffer;
                    break;

                default:
                    printf("Invalid choice!\n");
                    break;
            }
        }
    }

    else if (subTotal > 1000)
    {
        printf("You can choose between a 20 percent discount, a free spa procedure for 100 leva and 2 free dinners for your family.\n");
        printf("For a 20 percent discount type 1.\n");
        printf("For a free spa procedure type 2.\n");
        printf("For 2 free dinners for your family type 3. ");
        double discount3 = 0;
        char choice3 = 0;
        scanf("%c", &choice3);

        while (! (choice3=='1' || choice3=='2' || choice3=='3') ) {
            switch (choice3)
            {
                case '1':
                    printf("You get a 20 percent discount.\n");
                    discount3 = subTotal * 0.20;
                    printf("Your discount is %.2f leva.\n", discount3);
                    subTotal = subTotal - discount3;
                    printf("Your bill after discount is: %.2f leva.\n", subTotal);
                    goto finalOffer;
                    break;

                case '2':
                    printf("You get a free spa procedure for 100 leva.\n");
                    goto finalOffer;
                    break;

                case '3':
                    printf("You get 2 free dinners for your family.\n");
                    goto finalOffer;
                    break;
                    
                default:
                    printf("Invalid choice!\n");
                    break;
            }
        }
    }

    finalOffer:
        touristTax = subTotal * 0.06;
        printf("You owe tourist tax: %.2f leva.\n", touristTax);
        total = subTotal + touristTax;
        printf(SEPARATOR);
        printf("Your final offer is:\n");
        printf("Standard rooms: %d\n", roomsStandard);
        printf("Luxury rooms: %d\n", roomsLuxury);
        printf("Total nights: %d\n", totalNights);
        printf("Final bill: %.2f leva\n", total);
        printf(SEPARATOR);
        validDate();
        printf(SEPARATOR);

   return 0;
}

void chooseRooms(char type[], unsigned short int *number, unsigned short int *nights) {
    /* Вече повторното избиране на стая презаписва избора, а не добавя към предишния */
    printf("Your choice is %s room.\n", type);
    printf("How many nights are you going to stay? ");
    scanf("%hu", nights);
    printf("How many %s rooms would you like? ", type);
    scanf("%hu", number);
}

int validDate(){
    long long int t;
    t = time(NULL);
    t += 14 * SECONDS_TO_DAYS; /* две седмици (14 дена) след сегашното време */
    printf("This offer is valid until %s", ctime(&t) );
}
