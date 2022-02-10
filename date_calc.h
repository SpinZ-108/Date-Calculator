#ifndef DATE_CALC_H_INCLUDED
#define DATE_CALC_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    unsigned short int year, month, day;
} Date;


unsigned int dayOfTheWeek(const Date A);
_Bool isLeap(const unsigned int);
_Bool isValid(const Date);
Date NextDay(Date);
Date EarliestDate(const Date [], const int);
void EarliestFromArray();
_Bool isEarlier(const Date, const Date);
void PrintDate(const Date);
void ReadFromUser(Date *);


#endif // DATE_CALC_H_INCLUDED
