#include <stdio.h>

int comp = 0;

void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main()
{
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nNumber of Comparisons = %d\n", comp);

    return 0;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1, j, temp;

    for(j = low; j < high; j++)
    {
        comp++; // Count comparison
        if(a[j] < pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}
