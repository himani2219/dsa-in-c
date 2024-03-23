#include <stdio.h>

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter elements of array:\n");
    //creating array by taking user input
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //finding size of count array which is equal to max element in arr
    int max=arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max<arr[i])
        {
            max = arr[i];
        }
    }
    //creating count array and initializing values (frequency of each element in arr)
    int count[max+1];
    for (int i = 0; i <= max; i++)
    {
        count[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    //updating count by cumualtive sum
    for (int i = 1; i <= max; i++)
    {
        count[i]+=count[i-1];
    }
    //creating output array of size n and placing elements in correct position
    int output[n];
    for (int i = 0; i < n; i++)
    {
        output[--count[arr[i]]]=arr[i];
    }
    //printing original and sorted array
    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", output[i]);
    }
    
    return 0;
}