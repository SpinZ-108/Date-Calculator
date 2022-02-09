#include "date_calc.h"


unsigned int dayOfTheWeek(Date A)
{

    unsigned int Y = A.year, M = A.month;

    unsigned int d1 = (5*((Y-1)%4)+4*((Y-1)%100)+6*((Y-1)%400))%7;

    unsigned short int m;

    if (M==1) m=0;
    else if (M==2) m=3;

    else
    {
        switch(M)
        {
        case 3:
            m = (isLeap(Y) ? 4 : 3);
            break;
        case 4:
            m = (isLeap(Y) ? 0 : 6);
            break;
        case 5:
            m = (isLeap(Y) ? 2 : 1);
            break;
        case 6:
            m = (isLeap(Y) ? 5 : 4);
            break;
        case 7:
            m = (isLeap(Y) ? 0 : 6);
            break;
        case 8:
            m = (isLeap(Y) ? 3 : 2);
            break;
        case 9:
            m = (isLeap(Y) ? 6 : 5);
            break;
        case 10:
            m = (isLeap(Y) ? 1 : 0);
            break;
        case 11:
            m = (isLeap(Y) ? 4 : 3);
            break;
        case 12:
            m = (isLeap(Y) ? 6 : 5);
            break;

        }
    }

    unsigned int Gauss_day = ((d1+m+A.day)%7), result;
    result = ((Gauss_day==0) ? 7 : Gauss_day);          // Numerating of Gauss' days starts at 0 - Sunday


    return result;

}


_Bool isLeap(unsigned int Y)
{
    return ((Y%4==0&&Y%100!=0)||(Y%400==0));
}


_Bool isValid(Date A)
{
    if ((A.day==0)||(A.day > 31)||(A.month==0)||(A.month>12)||(A.year==0)) return 0;
    if ((isLeap(A.year))&&(A.month==2)&&(A.day==29)) return 1;
    if ((A.month==1 || A.month==3 || A.month==5 || A.month==7 || A.month==8 || A.month==10 || A.month==12) && A.day>31) return 0;
    if ((A.month==4 || A.month==6 || A.month==9 || A.month==11) && A.day>30) return 0;
    if (A.month==2 && A.day>28) return 0;
    return 1;
}


Date NextDay(Date A)
{

    if (!isValid(A))
    {
        A.day=0;
        A.month=0;
        A.year=0;
        printf("You have entered the invalid date!\n");
        return A;
    }

    do
    {
        A.day++;

        if(A.day>31)
        {
            A.day=1;
            A.month++;
        }

        if(A.month>12)
        {
            A.day=1;
            A.month=1;
        }
    }
    while(!isValid(A));


    return A;
}



Date EarliestDate(Date tab[], int n)
{
    int val = 0;

    for (int i=0; i<n; i++)
    {
        if(isValid(tab[i])) val++;
    }

    Date najwcz;

    if (val==0)
    {
        printf("There are no valid dates in the set!\n");
        najwcz.day=0;
        najwcz.month=0;
        najwcz.year=0;
        return najwcz;
    }

    Date valid_dates[val];

    int j=0;

    for (int i=0; i<n; i++)
    {
        if(isValid(tab[i]))
        {
            valid_dates[j]=tab[i];
            j++;
        }
    }

    najwcz = valid_dates[0];

    for(int i=1; i<j; i++)  //or i<val
    {
        if(isEarlier(valid_dates[i], najwcz))
        {
            najwcz=valid_dates[i];
        }
    }

    return najwcz;

}


void EarliestFromArray()
{
    int n;
    printf("Enter how many dates do you want to comapare: ");
    scanf("%d", &n);

    if (n<=1)
    {
        printf("There is nothing to comapre!\n\n");
        return;
    }

    else
    {
        Date dates[n];

        for(int i=0; i<n; i++)
        {
            printf("Year (date %d): ", i+1);
            scanf("%hu", &(dates[i].year));
            printf("Month (date %d): ", i+1);
            scanf("%hu", &(dates[i].month));
            printf("Day (date %d): ", i+1);
            scanf("%hu", &(dates[i].day));

            printf("\n");
        }

        printf("------------------------------\n");

        printf("The following dates were input:\n");

        for(int i=0; i<n; i++)
        {
            if(!isValid(dates[i])) printf("%d-%.2d-%d (NOT VALID!)\n", dates[i].day, dates[i].month, dates[i].year);
            else PrintDate(dates[i]);
        }

        printf("------------------------------\n");

        Date earliest = EarliestDate(dates,n);

        if(earliest.day!=0&&earliest.month!=0&&earliest.year!=0)
        {
            printf("The earliest of the given (vaild) dates is:\n");
            PrintDate(earliest);
        }

        printf("------------------------------\n");


    }
}


bool isEarlier(Date A, Date B)
{
    if(A.year<B.year) return 1;
    if(A.year>B.year) return 0;
    if(A.month<B.month) return 1;
    if(A.month>B.month) return 0;
    if(A.day<B.day) return 1;
    return 0;
}


void PrintDate(Date A)
{
    printf("%d-%.2d-%d\n", A.year, A.month, A.day);       //// ISO 8601: YYYY-MM-DD
}


void ReadFromUser(Date *A)
{
    printf("Enter a year: ");
    scanf("%hu", &(A->year));
    printf("Enter a month: ");
    scanf("%hu", &(A->month));
    printf("Enter a day: ");
    scanf("%hu", &(A->day));

    printf("\n");
}
