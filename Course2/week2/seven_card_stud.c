#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DECK_SIZE 52
#define NUM_PIPS 13
#define NUM_SUITS 4
#define NUM_HANDS 10
#define CARDS 7
#define TRIALS 1000000


typedef enum suit {spades, clubs, hearts, diamonds} suit;
typedef enum pips {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace} pips;
typedef struct Card{char suit; int pips;} Card;


void initialize_deck(Card deck[])
{
    int n;
    for (int i=0; i<NUM_SUITS; i++){
        for (int j=0; j<NUM_PIPS; j++){
            n = i*NUM_PIPS + j;
            deck[n].suit = i;
            deck[n].pips = j;
        }
    }
}


void shuffle(Card deck[])
{
    // Fisher-Yates shuffle algorithm.
    for (int i=DECK_SIZE-1; i>0; i--){
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


int is_four_of_a_kind(Card deck[])
{
    int ranks[NUM_PIPS] = {0};
    for (int i=0; i<CARDS; i++){
        ranks[deck[i].pips]++;
    }
    for (int i=0; i<NUM_PIPS; i++){
        if (ranks[i] == 4){return 1;}
    }
    return 0;
}


int is_full_house(Card deck[])
{
    int ranks[NUM_PIPS] = {0};
    for (int i=0; i<CARDS; i++){
        ranks[deck[i].pips]++;
    }
    
    int num_threes=0, num_twos=0;
    for (int i=0; i<NUM_PIPS; i++){
        if (ranks[i] == 3){num_threes = 1;}
        if (ranks[i] == 2){num_twos = 1;}
    }

    if (num_threes && num_twos){return 1;}
    return 0;
}


void calculate_probabilities(Card deck[])
{

    double four_of_a_kind=0, full_house=0;

    for (int t=0; t<TRIALS; t++){
        shuffle(deck);
        
        if (is_four_of_a_kind(deck)){four_of_a_kind++;}
        if (is_full_house(deck)){full_house++;}
    }
    printf("Four of a kind: %lf\n", four_of_a_kind / TRIALS);
    printf("Full house: %lf\n", full_house / TRIALS);
}


int main(void)
{
    srand(time(NULL));
    Card deck[DECK_SIZE];
    initialize_deck(deck);
    calculate_probabilities(deck);


    // for (int i=0; i<52; i++){
    //     printf("%d %d \n", deck[i].suit, deck[i].pips);
    // }
    return 0;
}
