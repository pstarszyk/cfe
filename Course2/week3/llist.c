#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list{
    int data;
    struct list *next;
} list;

int is_empty(list *node){
    // printf("%p\n", node);
    return (node == NULL);
}

void print_list(list *node){
    while (!is_empty(node)){
        printf("%d\n", node -> data);
        node = node -> next;
    }
}

int main(void){
    list *head = NULL; // need to initialize/declare pointer before 
    head = malloc(sizeof(list));
    head -> data = 5; // the reason we don't do head.data is because "." is used when we work with struct variable directly, here we are working with struct pointer.
    head -> next = NULL;
    print_list(head);
    return 0;
}