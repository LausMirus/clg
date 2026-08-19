#include <stdio.h>

int main()
{
    int queue[100];
    int size, front = -1, rear = -1;
    int choice, value, i;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    while (1)
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* Enqueue */
            if (rear == size - 1)
            {
                printf("Queue Overflow\n");
            }
            else
            {
                printf("Enter the element: ");
                scanf("%d", &value);

                if (front == -1)
                    front = 0;

                rear++;
                queue[rear] = value;

                printf("%d inserted into the queue\n", value);
            }
            break;

        case 2:
            /* Dequeue */
            if (front == -1 || front > rear)
            {
                printf("Queue Underflow\n");
            }
            else
            {
                printf("%d deleted from the queue\n", queue[front]);
                front++;
            }

            if (front > rear)
            {
                front = -1;
                rear = -1;
            }
            break;

        case 3:
            /* Peek */
            if (front == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Front element = %d\n", queue[front]);
            }
            break;

        case 4:
            /* Display */
            if (front == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue elements are: ");
                for (i = front; i <= rear; i++)
                {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
