#include <stdio.h>
# define EQ ==

enum day {monday, tuesday};


void print_day(enum day d){
    if (d EQ tuesday){
        printf("tuesday\n");
        printf("%d\n", tuesday);
    }
    else{
        printf("monday\n");
        printf("%d\n", monday);
    }
}


int main(void){
    enum day today = monday;
    print_day(today);
    return 0;
}