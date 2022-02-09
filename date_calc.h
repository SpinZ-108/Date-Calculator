#ifndef DATE_CALC_H_INCLUDED
#define DATE_CALC_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    unsigned short int year, month, day;
} Date;


unsigned int dayOfTheWeek(Date A);
_Bool isLeap(unsigned int);
_Bool isValid(Date);
Date NextDay(Date);
Date EarliestDate(Date [], int);
void EarliestFromArray();
_Bool isEarlier(Date, Date);
void PrintDate(Date);
void ReadFromUser(Date *);


#endif // DATE_CALC_H_INCLUDED
