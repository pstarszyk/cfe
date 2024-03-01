#include <stdio.h>
#include <stdlib.h>

// declare enums
typedef enum month {
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
} month;

// declare struct date
typedef struct date {
    month m;
    int d;
} date;

// declare printdate - here we just capitalize the month and write the full name using switch.
void printdate(struct date date){
    switch(date.m){
        case jan: printf("January %d\n", date.d); break;
        case feb: printf("February %d\n", date.d); break;
        case mar: printf("March %d\n", date.d); break;
        case apr: printf("April %d\n", date.d); break;
        case may: printf("May %d\n", date.d); break;
        case jun: printf("June %d\n", date.d); break;
        case jul: printf("July %d\n", date.d); break;
        case aug: printf("August %d\n", date.d); break;
        case sep: printf("September %d\n", date.d); break;
        case oct: printf("October %d\n", date.d); break;
        case nov: printf("November %d\n", date.d); break;
        case dec: printf("December %d\n", date.d); break;
    }
}


date nextday(struct date next){
    /*
    switch statement for the month.
    if we are at the last day of month, set next.d = 1
    else we just increment next.d++
    */
    switch(next.m){
        case jan:
        case mar:
        case may:
        case jul:
        case aug:
        case oct:
        case dec:
            if (next.d < 31)
                next.d++;
            else
                next.d = 1; 
            break;
        case apr:
        case jun:
        case sep:
        case nov:
            if (next.d < 30)
                next.d++;
            else
                next.d = 1;            
            break;
        default:
            if (next.d < 28)
                next.d++;
            else
                next.d = 1;
            break;
    }
    
    // if we entered a new month, increment month.
    if (next.d == 1)
        if (next.m == 11)
            next.m = 0;
        else 
            next.m++;

    return next;
}


int main(void)
{   
    struct date dates[] = {
        {dec, 31},
        {mar, 30},
        {apr, 15},
        {jul, 31},
        {oct, 1},
        {nov, 30}
    };

    for (int i=0; i<sizeof(dates)/sizeof(dates[0]); i++){
        printdate(dates[i]);
        printdate(nextday(dates[i]));
    }

    return 0;
}

