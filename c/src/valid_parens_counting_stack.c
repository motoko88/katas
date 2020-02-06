/**
 * Cameron Brenke
 *
 * Uses a counting stack to keep track of valid paranthesis uo
 * to the i_th char. Early stopping condition: If the stack is ever negative then the string
 * has more ')' than '('.
 * Otherwise, if there are equal '(' and ')' then the stack should be empty by the
 * last char.
 *
 * https://www.codewars.com/kata/52774a314c2333f0a7000688/c
 *
 * ./valid_parens_counting_stack "hi(hi)()"
 * ./valid_parens_counting_stack "(())((()())())"
 * clang -Wall valid_parens_counting_stack.c -o valid_parens_counting_stack
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool validParentheses(const char* strin) {
    int stack = 0;
    for (size_t i = 0; i < strlen(strin); ++i) {
        if (strin[i] == '(') {
            stack++;
        } else if (strin[i] == ')') {
            if (stack > 0) {
                stack--;
            } else {
                return false;
            }
        }
    }

    return stack == 0;
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
