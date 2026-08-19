#include <stdio.h>

int main()
{
    int max, deque[100];
    int front = -1, rear = -1;
    int choice, item, i;

    printf("Enter the size of deque: ");
    scanf("%d", &max);

    while (1)
    {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Front Element\n");
        printf("6. Display Rear Element\n");
        printf("7. Display All Elements\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* Insert at Front */
            if ((front == 0 && rear == max - 1) || (front == rear + 1))
            {
                printf("Deque Overflow\n");
            }
            else
            {
                printf("Enter the element: ");
                scanf("%d", &item);
                if (front == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else if (front == 0)
                {
                    front = max - 1;
                }
                else
                {
                    front = front - 1;
                }
                deque[front] = item;
                printf("Element inserted at the front.\n");
            }
            break;

        case 2:
            /* Insert at Rear */
            if ((front == 0 && rear == max - 1) || (front == rear + 1))
            {
                printf("Deque Overflow\n");
            }
            else
            {
                printf("Enter the element: ");
                scanf("%d", &item);
                if (front == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else if (rear == max - 1)
                {
                    rear = 0;
                }
                else
                {
                    rear = rear + 1;
                }
                deque[rear] = item;
                printf("Element inserted at the rear.\n");
            }
            break;

        case 3:
            /* Delete from Front */
            if (front == -1)
            {
                printf("Deque Underflow\n");
            }
            else
            {
                item = deque[front];
                printf("Deleted element: %d\n", item);
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else if (front == max - 1)
                {
                    front = 0;
                }
                else
                {
                    front = front + 1;
                }
            }
            break;

        case 4:
            /* Delete from Rear */
            if (front == -1)
            {
                printf("Deque Underflow\n");
            }
            else
            {
                item = deque[rear];
                printf("Deleted element: %d\n", item);
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else if (rear == 0)
                {
                    rear = max - 1;
                }
                else
                {
                    rear = rear - 1;
                }
            }
            break;

        case 5:
            /* Display Front Element */
            if (front == -1)
            {
                printf("Deque is Empty\n");
            }
            else
            {
                printf("Front element: %d\n", deque[front]);
            }
            break;

        case 6:
            /* Display Rear Element */
            if (front == -1)
            {
                printf("Deque is Empty\n");
            }
            else
            {
                printf("Rear element: %d\n", deque[rear]);
            }
            break;

        case 7:
            /* Display All Elements */
            if (front == -1)
            {
                printf("Deque is Empty\n");
            }
            else
            {
                printf("Elements in the deque: ");
                i = front;
                while (1)
                {
                    printf("%d ", deque[i]);
                    if (i == rear)
                    {
                        break;
                    }
                    i = (i + 1) % max;
                }
                printf("\n");
            }
            break;

        case 8:
            printf("Program terminated.\n");
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
