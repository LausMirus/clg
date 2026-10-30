#include <stdio.h>
#define MAX 100

int main()
{
    int h[MAX], m, method, R = 5;
    int i, key, choice, pos, step, found;

    printf("Enter hash table size: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
        h[i] = -1;

    printf("1. Linear Probing\n");
    printf("2. Quadratic Probing\n");
    printf("3. Double Hashing\n");
    printf("Enter technique: ");
    scanf("%d", &method);

    if(method == 3)
    {
        printf("Enter prime R smaller than %d: ", m);
        scanf("%d", &R);
    }

    do
    {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1 || choice == 2)
        {
            printf("Enter key: ");
            scanf("%d", &key);
            found = 0;

            for(i = 0; i < m; i++)
            {
                if(method == 1)
                    pos = (key % m + i) % m;
                else if(method == 2)
                    pos = (key % m + i * i) % m;
                else
                {
                    step = R - (key % R);
                    pos = (key % m + i * step) % m;
                }

                if(choice == 1) // Insertion
                {
                    if(h[pos] == key)
                    {
                        printf("Key already exists.\n");
                        found = 1;
                        break;
                    }
                    if(h[pos] == -1)
                    {
                        h[pos] = key;
                        printf("Key inserted successfully.\n");
                        found = 1;
                        break;
                    }
                }
                else // Search
                {
                    if(h[pos] == key)
                    {
                        printf("Key found at index %d.\n", pos);
                        found = 1;
                        break;
                    }
                    if(h[pos] == -1)
                        break;
                }
            }

            if(!found)
            {
                if(choice == 1)
                    printf("Insertion not possible.\n");
                else
                    printf("Key not found.\n");
            }
        }
        else if(choice == 3)
        {
            printf("Hash Table:\n");
            for(i = 0; i < m; i++)
            {
                if(h[i] == -1)
                    printf("%d : EMPTY\n", i);
                else
                    printf("%d : %d\n", i, h[i]);
            }
        }
        else if(choice != 4)
        {
            printf("Invalid choice.\n");
        }
    } while(choice != 4);

    printf("Exiting program.\n");
    return 0;
}
