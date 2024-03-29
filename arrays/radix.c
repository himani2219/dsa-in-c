#include <stdio.h>

void countSort(int arr[], int output[], int n, int pos){

    int count[10];
    for (int i = 0; i <= 9; i++)
    {
        count[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        ++count[(arr[i]/pos)%10];
    }
    //updating count by cumualtive sum
    for (int i = 1; i <= 9; i++)
    {
        count[i]+=count[i-1];
    }
    // placing elements in output array
    for (int i = n-1; i>=0; i--)
    {
        output[--count[(arr[i]/pos)%10]]=arr[i];
    
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int output[], int n, int max){
    for (int pos = 1; max/pos> 0; pos*=10){
        countSort(arr, output, n, pos);
    }
    
}

int main(){
    int n;
    printf("enter size: ");
    scanf("%d", &n);
    int arr[n];
    printf("\n Enter elements: \n");
    for(int i=0;i<n; i++){
        scanf("%d", &arr[i]);
    }

    int max=arr[0];
    for (int i = 1 ; i < n; i++)
    {
        if(max<arr[i]){
            max=arr[i];
        }
    }

    int output[n];
    for (int i = 0; i < n; i++)
    {
        output[i]=0;
    }

    

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    radixSort(arr, output, n, max);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", output[i]);
    }
    
    
}