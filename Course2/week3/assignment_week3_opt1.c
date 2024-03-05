#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
} list;

void generate_random_array(int arr[], int size){
    // generates a random array.

    for (int i=0; i<size; i++){
        arr[i] = rand();
    }
}

void print_list(list* head){
    // prints linked list values in rows of 5.

    int cur = 1;
    
    while (head != NULL){
        printf("%d\t", head-> data);
        head = head-> next;
        if (cur % 5 == 0)
            printf("\n");
        cur++;
    }
}

list* create_list(int data){
    // creates new list node.

    list* new = malloc(sizeof(list));
    new-> data = data;
    new-> next = NULL;
    return new;
}

list* add_to_front(int data, list* old){
    // adds a new list node in front of given list.

    list* new = create_list(data);
    new-> next = old;
    return new;
}

list* array_to_list(int arr[], int size){
    // converts array to linked list.

    list* head = create_list(arr[0]);
    for (int i=1; i<size; i++){
        head = add_to_front(arr[i], head);
    }
    return head;
}

void pass_through(list* head, int current_end){
    /*
    This function performs a pass through the list 
    comparing adjacent node values.
    */

    int cur_val, nxt_val;

    for (int j=0; j<current_end; j++){
        cur_val = head-> data;
        nxt_val = (head-> next)-> data;
        if (cur_val > nxt_val){
            head-> data = nxt_val;
            (head-> next)-> data = cur_val;
        }
        head = head-> next;
    }
}


void bubble_sort_list(list* head, int size){
    /*
    This function performs all n-1 pass throughs of list
    pass_through is a separate function so that our local "head"
    pointer always points to first node.
    */
    for (int i=size-1; i>0; i--){
        pass_through(head, i);
    }
}

int main(void){
    // generate random array 
    int size = 100;
    int arr[size];
    generate_random_array(arr, size);
    
    // create linked list from randomly generated array
    list* head = NULL;
    head = array_to_list(arr, size);
    
    // sort
    bubble_sort_list(head, size);

    // print
    print_list(head);

    return 0;
}
