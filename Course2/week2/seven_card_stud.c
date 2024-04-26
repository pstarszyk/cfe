#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DECK_SIZE 52
#define NUM_PIPS 13
#define NUM_SUITS 4
#define NUM_HANDS 10
#define CARDS 7
#define TRIALS 1000000

// Define enum for suits, pips
typedef enum suit {spades, clubs, hearts, diamonds} suit;
typedef enum pips {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace} pips;

// Define Card struct containing suit and pips members.
typedef struct Card{char suit; int pips;} Card;


void initialize_deck(Card deck[])
{
    // Initializes the deck array with 52 Card structs.

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
    // Implements the Fisher-Yates shuffle algorithm
    // to shuffle a deck in O(n) time in place.

    for (int i=DECK_SIZE-1; i>0; i--){
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


int is_four_kind(Card deck[], int ranks[])
{
    // Check if a hand is four of a kind.
    // Just check if a pips has count 4.

    for (int i=0; i<NUM_PIPS; i++){
        if (ranks[i] == 4){return 1;}
    }
    return 0;
}

int is_three_kind(Card deck[], int ranks[])
{
    // Check if a hand is three of a kind.
    // Just check if a pips has count 3 and 4 pips have count 1.
   
    int num_threes=0, num_ones=0;
    for (int i=0; i<NUM_PIPS; i++){
        if (ranks[i] == 3){num_threes++;}
        if (ranks[i] == 1){num_ones++;}
    }
    if ((num_threes==1)&&(num_ones==4)){return 1;}
    return 0;
}

int is_full_house(Card deck[], int ranks[])
{
    // Check if a hand is full house.
    // Just check if a pips has count 3 and at least one pips has count 2.
   
    int num_threes=0, num_twos=0;
    for (int i=0; i<NUM_PIPS; i++){
        if (ranks[i] == 3){num_threes++;}
        if (ranks[i] == 2){num_twos++;}
    }
    if (num_threes && num_twos){return 1;}
    return 0;
}

int is_one_pair(Card deck[], int ranks[])
{
    // Check if a hand has one pair.
    // Just check if exactly one pips has count 2.
   
    int num_twos=0;
    for (int i=0; i<NUM_PIPS; i++){
        if (ranks[i] == 2){num_twos++;}
    }
    if (num_twos==1){return 1;}
    return 0;
}

int is_two_pair(Card deck[], int ranks[])
{   
    // Check if a hand has two pair.
    // Just check if exactly 2 pips have count 2.
   
    int num_twos=0;
    for (int i=0; i<NUM_PIPS; i++){
        if (ranks[i] == 2){num_twos++;}
    }
    if (num_twos==2){return 1;}
    return 0;
}

void calculate_probabilities(Card deck[])
{

    double four_kind=0, full_house=0, one_pair=0, two_pair=0, three_kind=0;
    int ranks[NUM_PIPS] = {0};

    for (int t=0; t<TRIALS; t++){
        // shuffle deck for each trial.
        shuffle(deck);

        // reset ranks array.
        memset(ranks, 0, sizeof(ranks));

        // counts pips frequency for the top 7 cards.
        for (int i=0; i<CARDS; i++){
            ranks[deck[i].pips]++;
        }
            
        // check classification of hand.
        if (is_four_kind(deck, ranks)){four_kind++;}
        if (is_full_house(deck, ranks)){full_house++;}
        if (is_one_pair(deck, ranks)){one_pair++;}
        if (is_two_pair(deck, ranks)){two_pair++;}
        if (is_three_kind(deck, ranks)){three_kind++;}
    }
    printf("Four of a kind: %lf\n", four_kind / TRIALS);
    printf("Full house: %lf\n", full_house / TRIALS);
    printf("One pair: %lf\n", one_pair / TRIALS);
    printf("Two pair: %lf\n", two_pair / TRIALS);
    printf("Three of a kind: %lf\n", three_kind / TRIALS);
}


int main(void)
{
    srand(time(NULL));
    Card deck[DECK_SIZE];
    initialize_deck(deck);
    calculate_probabilities(deck);

    return 0;
}
