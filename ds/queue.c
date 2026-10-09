#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    if (!rear) front = rear = n;
    else { rear->next = n; rear = n; }
}

void dequeue() {
    if (!front) { printf("Queue Underflow\n"); return; }
    struct Node* t = front; front = front->next;
    if (!front) rear = NULL;
    free(t);
}

void display() {
    if (!front) { printf("Queue is Empty\n"); return; }
    for (struct Node* p = front; p; p = p->next) printf("%d ", p->data);
    printf("\n");
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &val); enqueue(val); }
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else if (ch == 4) break;
    }
    return 0;
}
