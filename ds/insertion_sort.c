#include <stdio.h>

int main()
{
    int a[100], n;
    int i, j, key;
    int comp = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while(j >= 0)
        {
            comp++;
            if(a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
            {
                break;
            }
        }
        a[j + 1] = key;
    }

    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nNumber of Comparisons = %d\n", comp);

    return 0;
}
