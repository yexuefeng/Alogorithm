/*************************************************************************
	> File Name: quick_sort.c
	> Author: ye xuefeng
	> Mail: 
	> Created Time: 2017年12月13日 星期三 09时57分50秒
 ************************************************************************/

#include <stdio.h>

int parition(int arr[], int low, int high)
{
    int pivot = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= pivot)
        {
            --high;
        }
        arr[low] = arr[high];

        while (low < high && arr[low] <= pivot)
        {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;

    return low;
}

void quick_sort(int arr[],  int low, int high)
{
    int pivotIndex;

    if (low < high)
    {
        pivotIndex = parition(arr, low, high);
        quick_sort(arr, low,  pivotIndex - 1);
        quick_sort(arr, high, pivotIndex + 1);
    }
}

int main()
{
    int array[10] = { 6, 7, 1, 5, 3, 2, 8, 9, 4, 10};
    int high = sizeof(array) / sizeof(int) - 1;
    int low = 0;
    quick_sort(array, low, high);

    int i;
    for (i = 0; i < high; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
