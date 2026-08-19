#include <stdio.h>

int comp = 0;

void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main()
{
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nNumber of Comparisons = %d\n", comp);

    return 0;
}

void mergeSort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high)
    {
        comp++;
        if(a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while(i <= mid)
    {
        temp[k++] = a[i++];
    }

    while(j <= high)
    {
        temp[k++] = a[j++];
    }

    for(i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}
