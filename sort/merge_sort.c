#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int src1[], int src2[], int dest[], int len1, int len2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    while (i < len1 && j < len2)
    {
        dest[k++] = src1[i] < src2[j] ? src1[i++] : src2[j++];
    }

    while (i < len1)
    {
        dest[k++] = src1[i++];
    }
    while (j < len2)
    {
        dest[k++] = src2[j++];
    }
}

void mSort(int src[], int dest[], int s, int e)
{
    int m;
    if (s == e)
    {
        dest[s] = src[s];
    }
    else
    {   
        m = (s + e) / 2;
        mSort(src, dest+s, s, m);
        mSort(src, dest + m + 1, m+1, e);
        merge(src + s, src + m + 1, dest + s, m - s + 1, e - (m+1) + 1);
        if (e > s)
        {
            memcpy(src + s, dest + s, e - s);
        }
    }
}

int main()
{
    int i = 0;
    int arr1[3] = {3, 2, 1};
    int arr2[6] = {6, 5, 4, 3, 2, 1};
    int dest1[5];
    int dest2[6];

    mSort(arr1, dest1, 0, 2);
    for (i = 0; i < 3; i++)
    {
        printf ("%d ", *(dest1 + i));
    }
    printf("\n");

    /*
    mSort(arr2, dest2, 0, 5);
    for (i = 0; i < sizeof(arr2); i++)
    {
        printf("%d ", *(dest2 + i));
    }
    */
    return 0;
}
