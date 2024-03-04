#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list{int data; struct list *next;} list;

int is_empty(list *l){
    return (l == NULL);
}

list* create_list(int d){
    list* head = malloc(sizeof(list));
    head-> data = d;
    head-> next = NULL;
    return head;
}

list* add_to_front(int d, list* h){
    list* head = create_list(d);
    head-> next = h;
    return head;
}

list* array_to_list(int arr[], int size){
    list* head = create_list(arr[0]);
    for (int i=1; i<size; i++){
        head = add_to_front(arr[i], head);
    }
    return head;
}

void print_list(list* h){
    while (!is_empty(h)){
        printf("%d\n", h-> data);
        h = h-> next;
    }
}

int main(void){
    int data[6] = {3,2,6,1,7,9};
    list* head = NULL;
    head = array_to_list(data, 6);
    print_list(head);
    return 0;
}



