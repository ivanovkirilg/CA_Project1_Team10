#include <stdio.h>
#include <time.h>
#include <string.h>

#define FIFTEEN_PERCENT 0.15
#define TWENTY_PERCENT 0.20
#define TOURIST_TAX_RATE 0.06
#define SECONDS_TO_DAYS 24*60*60
#define SEPARATOR "######################\n"

int validDate();
double chooseRooms(char type[], double price, unsigned short int *number, unsigned short int *nights);

int main()
{
    const double c_luxuryRoomPrice = 180;
    const double c_standardRoomPrice = 120;

    unsigned short int roomsLuxury = 0;
    unsigned short int nightsLuxury = 0;
    unsigned short int roomsStandard = 0;
    unsigned short int nightsStandard = 0;
    unsigned short int totalNights = 0;
    double luxuryTotal = 0;
    double standardTotal = 0;
    double subTotal = 0;
    double touristTax = 0;
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

        switch (choice) 
        {
            case '1':
                luxuryTotal = chooseRooms("Luxury", c_luxuryRoomPrice, &roomsLuxury, &nightsLuxury);
                subTotal = luxuryTotal + standardTotal;
                printf("Your current bill is %.2f leva.\n", subTotal);
                break;

            case '2':
                standardTotal = chooseRooms("Standard", c_standardRoomPrice, &roomsStandard, &nightsStandard);
                subTotal = luxuryTotal + standardTotal;
                printf("Your current bill is %.2f leva.\n", subTotal);
                break;

            case '3':
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    totalNights = nightsStandard * roomsStandard + nightsLuxury * roomsLuxury;

    if (totalNights > 5 && subTotal < 700)
    {
        double discount1 = subTotal * FIFTEEN_PERCENT;
        subTotal = subTotal - discount1;
        printf("You get a 15 percent discount.\n");
        printf("Your discount is %.2f leva.\n", discount1);
        printf("Your bill after discount is: %.2f leva.\n", subTotal);
    }

    else if (subTotal > 700 && subTotal < 1000)
    {
        char choice2 = 0;
        printf("You can choose between a 15 percent discount and a free spa procedure for 100 leva.\n");
        double discount2 = 0;

        while (! (choice2=='1' || choice2=='2') ) 
        {
            printf("For a 15 percent discount type 1.\n");
            printf("For a free spa procedure type 2. ");
            scanf(" %c", &choice2);
            switch (choice2)
            {
                case '1':
                    discount2 = subTotal * FIFTEEN_PERCENT;
                    subTotal = subTotal - discount2;
                    printf(SEPARATOR);
                    printf("You get a 15 percent discount.\n");
                    printf("Your discount is %.2f leva.\n", discount2);
                    printf("Your bill after discount is: %.2f leva.\n", subTotal);
                    break;

                case '2':
                    printf(SEPARATOR);
                    printf("You get a free spa procedure for 100 leva.\n");
                    break;

                default:
                    printf("Invalid choice! ");
                    break;
            }
        }
    }

    else if (subTotal > 1000)
    {
        char choice3 = 0;
        printf("You can choose between a 20 percent discount,\n a free spa procedure for 100 leva and\n 2 free dinners for your family.\n");
        double discount3 = 0;

        while (! (choice3=='1' || choice3=='2' || choice3=='3') ) 
        {
            printf("For a 20 percent discount type 1.\n");
            printf("For a free spa procedure type 2.\n");
            printf("For 2 free dinners for your family type 3. ");
            scanf(" %c", &choice3);
            switch (choice3)
            {
                case '1':
                    discount3 = subTotal * TWENTY_PERCENT;
                    subTotal = subTotal - discount3;
                    printf(SEPARATOR);
                    printf("You get a 20 percent discount.\n");
                    printf("Your discount is %.2f leva.\n", discount3);
                    printf("Your bill after discount is: %.2f leva.\n", subTotal);
                    break;

                case '2':
                    printf(SEPARATOR);
                    printf("You get a free spa procedure for 100 leva.\n");
                    break;

                case '3':
                    printf(SEPARATOR);
                    printf("You get 2 free dinners for your family.\n");
                    break;
                    
                default:
                    printf("Invalid choice! ");
                    break;
            }
        }
    }

    touristTax = subTotal * TOURIST_TAX_RATE;
    total = subTotal + touristTax;
    printf("You owe tourist tax: %.2f leva.\n", touristTax);
    printf("Your final offer is:\n");
    printf("%d Standard rooms for %d nights.\n", roomsStandard, nightsStandard);
    printf("%d Luxury rooms for %d nights.\n", roomsLuxury, nightsLuxury);
    printf("Total nights: %d\n", totalNights);
    printf("Final bill: %.2f leva\n", total);
    validDate();
    printf(SEPARATOR);

   return 0;
}

double chooseRooms(char type[], double price, unsigned short int *number, unsigned short int *nights) {
    /* Вече повторното избиране на стая презаписва избора, а не добавя към предишния */
    printf("Your choice is %s room.\n", type);
    printf("How many nights are you going to stay? ");
    scanf("%hu", nights);
    printf("How many %s rooms would you like? ", type);
    scanf("%hu", number);
    return price * *number * *nights;
}

int validDate(){
    long long int t;
    t = time(NULL);
    t += 14 * SECONDS_TO_DAYS; /* две седмици (14 дена) след сегашното време */
    printf("This offer is valid until %s", ctime(&t) );
}
