#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Initialize front and rear pointers globally
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add an element to the queue (Enqueue)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, both front and rear point to the new node
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        // Add the new node at the end and update rear
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued successfully.\n", value);
}

// Function to remove an element from the queue (Dequeue)
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! The queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("%d dequeued from queue.\n", temp->data);
    
    // Move front to the next node
    front = front->next;

    // If front becomes NULL, the queue is now empty, so reset rear to NULL as well
    if (front == NULL) {
        rear = NULL;
    }

    free(temp); // Free memory of the removed node
}

// Function to view the front element of the queue
void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

// Function to display all elements in the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = front;
    printf("\nQueue elements (Front to Rear):\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    int choice, value;

    do {
        printf("\n--- Queue Operations (Linked List) ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                // Free remaining nodes to prevent memory leaks
                while (front != NULL) {
                    struct Node* temp = front;
                    front = front->next;
                    free(temp);
                }
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
