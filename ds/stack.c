#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL;

void push(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = top; top = n;
}

void pop() {
    if (!top) { printf("Stack Underflow\n"); return; }
    struct Node* t = top; top = top->next; free(t);
}

void display() {
    if (!top) { printf("Stack is Empty\n"); return; }
    for (struct Node* p = top; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &val); push(val); }
        else if (ch == 2) pop();
        else if (ch == 3) display();
        else if (ch == 4) break;
    }
    return 0;
}
