#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->prev = ptr;
}

void deleteNode(int item) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* ptr = head;

    while (ptr != NULL && ptr->data != item) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Element %d not found.\n", item);
        return;
    }

    if (ptr == head) {
        head = ptr->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        ptr->prev->next = ptr->next;
        if (ptr->next != NULL) {
            ptr->next->prev = ptr->prev;
        }
    }

    free(ptr);
    printf("Element %d deleted successfully.\n", item);
}

void displayForward() {
    struct Node* ptr = head;
    printf("Forward Traversal: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("Backward Traversal: List is empty.\n");
        return;
    }

    struct Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    printf("Backward Traversal: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Forward Traversal\n4. Backward Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertNode(val);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 3:
                displayForward();
                break;
            case 4:
                displayBackward();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
