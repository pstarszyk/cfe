#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef struct stack{
    char s[MAX_LEN];
    int top;
} stack;

void reset(stack *stk){
    stk-> top = EMPTY;
}

void push(stack *stk, char c){
    stk-> top++;
    stk-> s[stk-> top] = c;
}

char pop(stack *stk){
    char c;
    c = (stk-> s[stk-> top]);
    stk-> top--;
    return c;
    // return (stk-> s[stk-> top--]);
}

char top(stack *stk){
    return (stk-> s[stk-> top]);
}

int is_empty(stack *stk){
    return (stk-> top) == EMPTY;
}

int is_full(stack *stk){
    return (stk-> top) == FULL;
}



int main(void){
    stack my_stack;
    char *str = "hello my friend";
    char back[15];
    int i=0;

    while (str[i] != '\0'){
        push(&my_stack, str[i]);
        i++;
    }
    i=0;
    while (!is_empty(&my_stack)){
        back[i] = pop(&my_stack);
        i++;
    }
    printf("%s\n\n", back);
}











