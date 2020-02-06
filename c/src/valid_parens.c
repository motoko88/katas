/**
 * Cameron Brenke
 * https://www.codewars.com/kata/52774a314c2333f0a7000688/c
 *
 * ./valid_parens "hi(hi)()"
 * ./valid_parens "(())((()())())"
 * clang -Wall valid_parens.c -o valid_parens
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct node {
    char val;
    struct node* next;
};

struct stack {
    struct node* top;
    size_t size;
};

void free_stack(struct stack *stack) {
    struct node* current = stack->top;
    struct node* previous = current;
    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }

    free(stack);
}

void push(struct stack *stack, char character) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->val = character;
    new_node->next = stack->top;

    stack->top = new_node;
    stack->size++;
}

struct node* pop(struct stack* stack) {
    struct node* top = stack->top;
    stack->top = top->next;
    stack->size--;
    return top;
}

bool validParentheses(const char* strin) {
    struct stack* stack = (struct stack*) malloc(sizeof(struct stack));
    stack->size = 0;
    for (size_t i = 0; i < strlen(strin); ++i) {
        if (strin[i] == '(') {
            push(stack, '(');
        }
        else if (strin[i] == ')') {
            if (stack->size > 0) {
                pop(stack);
            } else {
                return false;
            }
        }
    }

    const size_t res = stack->size;
    free_stack(stack);
    return res == 0;
}


int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    const bool res = validParentheses(argv[1]);
    if (res) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
