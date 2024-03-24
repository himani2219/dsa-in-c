#include <stdio.h>

void linearSearch(int arr[], int sizeOfArray){
    int el;
    printf("Enter element that you want to search: ");
    scanf("%d", &el);
    int found=0;
    for(int i=0; i<sizeOfArray; i++){
        if(arr[i]==el){
            printf("Element found at index: %d \n",i);
            found=1;
        }          
        }
        if(found==0){
            printf("Element not found.\n");
        }
}

int main(){
    int sizeOfArray;
        printf("\nEnter the size of array:");
        scanf("%d", &sizeOfArray);
        int arr[sizeOfArray];
        printf("Enter elements of the array:\n");
        for(int i=0; i<sizeOfArray; i++){
            scanf("%d",&arr[i]);
        }
        printf("Elements in array are: ");
        for(int i=0; i<sizeOfArray; i++){
            printf( "%d ",arr[i]);
        }
        printf("\n");
        linearSearch(arr,sizeOfArray);
        return 0;
}