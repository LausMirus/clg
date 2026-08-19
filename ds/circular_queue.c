#include <stdio.h>

int main() {
    int queue[100];
    int max, front = -1, rear = -1;
    int choice, item, i;

    printf("Enter the size of circular queue: ");
    scanf("%d", &max);

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            /* Enqueue */
            if ((rear + 1) % max == front) {
                printf("Circular Queue Overflow!\n");
            } else {
                printf("Enter the element: ");
                scanf("%d", &item);
                if (front == -1) {
                    front = 0;
                    rear = 0;
                } else {
                    rear = (rear + 1) % max;
                }
                queue[rear] = item;
                printf("Element inserted successfully!\n");
            }
            break;

        case 2:
            /* Dequeue */
            if (front == -1) {
                printf("Circular Queue Underflow!\n");
            } else {
                item = queue[front];
                printf("Deleted element: %d\n", item);
                if (front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front = (front + 1) % max;
                }
            }
            break;

        case 3:
            /* Peek */
            if (front == -1) {
                printf("Circular Queue is Empty!\n");
            } else {
                printf("Front element: %d\n", queue[front]);
            }
            break;

        case 4:
            /* Display */
            if (front == -1) {
                printf("Circular Queue is Empty!\n");
            } else {
                printf("Elements in the circular queue: ");
                i = front;
                while (1) {
                    printf("%d ", queue[i]);
                    if (i == rear) {
                        break;
                    }
                    i = (i + 1) % max;
                }
                printf("\n");
            }
            break;

        case 5:
            printf("Program terminated.\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
