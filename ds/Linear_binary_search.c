#include <stdio.h>

int main()
{
    int a[100], n, key;
    int i, j, temp;
    int low, high, mid;
    int count = 0, bcount = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Linear Search
    for(i = 0; i < n; i++)
    {
        count++;
        if(a[i] == key)
        {
            printf("\nLinear Search: Element found at position %d\n", i + 1);
            break;
        }
    }

    if(i == n)
        printf("\nLinear Search: Element not found\n");

    printf("Number of comparisons = %d\n", count);

    // Sort the array for Binary Search
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Binary Search
    low = 0;
    high = n - 1;

    while(low <= high)
    {
        bcount++;
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            printf("\nBinary Search: Element found at position %d\n", mid + 1);
            break;
        }
        else if(a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(low > high)
        printf("\nBinary Search: Element not found.\n");

    printf("Number of comparisons = %d\n", bcount);

    if(count < bcount)
        printf("\nLinear Search performed better.\n");
    else if(bcount < count)
        printf("\nBinary Search performed better.\n");
    else
        printf("\nBoth performed equally.\n");

    return 0;
}
