#include "date_calc.h"



int main()
{

    bool finish = 0;
    int choice;
    Date adate;

    while (!finish)
    {
        printf("SELECT AN OPTION: \n");
        printf("0. EXIT\n");
        printf("1. CHECH IF A DATE IS VALID\n");
        printf("2. CALCULATE A NEXT DAY\n");
        printf("3. CALUCLATE THE EARLIEST DATE FROM A GIVEN SET\n");
        printf("4. CALCULATE THE DAY OF THE WEEK\n");
        printf("------------------------------\n");
        scanf("%d", &choice);

        switch(choice)
        {

        case 0:
            finish=1;
            break;

        case 1:
        {

            ReadFromUser(&adate);

            printf("------------------------------\n");

            if (isValid(adate))
                printf("Date %d-%.2d-%d is valid!\n", adate.year, adate.month, adate.day);
            else printf("Date %d-%.2d-%d is not valid!\n", adate.year, adate.month, adate.day);

            printf("------------------------------\n");

            break;
        }

        case 2:
        {

            Date next;
            printf("We will calculate the next day.\n");
            ReadFromUser(&adate);
            next=NextDay(adate);
            printf("The next day is %d-%.2d-%d.\n", next.year, next.month, next.day);
            printf("------------------------------\n");
            break;
        }

        case 3:
        {
            EarliestFromArray();
            break;
        }

        case 4:
        {
            printf("We will calculate the day of the week.\n\n");
            ReadFromUser(&adate);

            unsigned int num_of_day = dayOfTheWeek(adate);

            switch (num_of_day)
            {
            case 1:
                printf("It's Monday!\n");
                break;
            case 2:
                printf("It's Tuesday!\n");
                break;
            case 3:
                printf("It's Wednesday!\n");
                break;
            case 4:
                printf("It's Thursday!\n");
                break;
            case 5:
                printf("It's Friday!\n");
                break;
            case 6:
                printf("It's Saturday!\n");
                break;
            case 7:
                printf("It's Sunday!\n");
                break;
            default:
                printf("An error has occured.\n");
                break;
            }

            printf("------------------------------\n");

            break;

        }

        default:
        {
            printf("There is no such an option!\n");
            printf("------------------------------\n");

            break;
        }

        }

    }

    return 0;
}
