void print_stack(struct stack* stack) {
    struct node *current = stack->top;
    while (current != NULL) {
        printf("%c, ", current->val);
        current = current->next;
    }
    printf("\n");
}