#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node* next;
};

void insertOrAdd(struct Node** R, int c, int e) {
    struct Node* temp = *R;
    while (temp) {
        if (temp->exp == e) {
            temp->coeff += c;
            return;
        }
        temp = temp->next;
    }
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->coeff = c; n->exp = e; n->next = *R;
    *R = n;
}

void display(struct Node* poly) {
    for (; poly; poly = poly->next)
        printf("%dx^%d %s", poly->coeff, poly->exp, poly->next ? "+ " : "");
    printf("\n");
}

void multiplyPoly(struct Node* P, struct Node* Q) {
    struct Node* R = NULL;
    for (struct Node* p = P; p; p = p->next)
        for (struct Node* q = Q; q; q = q->next)
            insertOrAdd(&R, p->coeff * q->coeff, p->exp + q->exp);
    
    printf("Product: ");
    display(R);
}

int main() {
    struct Node *P = NULL, *Q = NULL;
    int n, c, e;

    printf("Terms in Poly P: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d %d", &c, &e); insertOrAdd(&P, c, e); }

    printf("Terms in Poly Q: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d %d", &c, &e); insertOrAdd(&Q, c, e); }

    multiplyPoly(P, Q);
    return 0;
}
