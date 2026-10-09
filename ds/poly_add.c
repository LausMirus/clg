#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node* next;
};

void insert(struct Node** poly, int c, int e) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node)), *temp = *poly;
    n->coeff = c; n->exp = e; n->next = NULL;
    if (!*poly) { *poly = n; return; }
    while (temp->next) temp = temp->next;
    temp->next = n;
}

void display(struct Node* poly) {
    for (; poly; poly = poly->next)
        printf("%dx^%d %s", poly->coeff, poly->exp, poly->next ? "+ " : "");
    printf("\n");
}

void addPoly(struct Node* P, struct Node* Q) {
    struct Node* R = NULL;
    while (P && Q) {
        if (P->exp == Q->exp) {
            insert(&R, P->coeff + Q->coeff, P->exp);
            P = P->next; Q = Q->next;
        } else if (P->exp > Q->exp) {
            insert(&R, P->coeff, P->exp);
            P = P->next;
        } else {
            insert(&R, Q->coeff, Q->exp);
            Q = Q->next;
        }
    }
    while (P) { insert(&R, P->coeff, P->exp); P = P->next; }
    while (Q) { insert(&R, Q->coeff, Q->exp); Q = Q->next; }
    
    printf("Sum: ");
    display(R);
}

int main() {
    struct Node *P = NULL, *Q = NULL;
    int n, c, e;

    printf("Terms in Poly P: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d %d", &c, &e); insert(&P, c, e); }

    printf("Terms in Poly Q: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d %d", &c, &e); insert(&Q, c, e); }

    addPoly(P, Q);
    return 0;
}
