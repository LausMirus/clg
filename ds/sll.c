#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// 1. Insertion (at the beginning)
void insert(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d\n", val);
}

// 2. Deletion (by value)
void deleteNode(int val) {
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        printf("Deleted %d\n", val);
        return;
    }

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", val);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d\n", val);
}

// 3. Searching
void search(int val) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Element %d found at position %d.\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", val);
}

// 4. Displaying
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
