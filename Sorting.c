#include <stdio.h>

void traverseArray(int arr[], int sizeOfArray){
        printf("Elements in array are: ");
        for(int i=0; i<sizeOfArray; i++){
            printf( "%d ",arr[i]);
        }
        printf("\n");
    }

void insertion(int arr[], int *sizeOfArray){
    int ind, el;
    printf("Enter index at which element is to be inserted: ");
    scanf("%d",&ind);
    printf("Enter element to be inserted: ");
    scanf("%d",&el);
    if(ind<0 || ind>*sizeOfArray){
        printf("Invalid position!");
        return;
    }
    for(int i = *sizeOfArray; i>ind; i--){
        arr[i] = arr[i-1];
    }
    arr[ind]=el;
    (*sizeOfArray)++;
}

void deletion(int arr[], int *sizeOfArray){
    int ind;
     printf("Enter index at which element is to be deleted: ");
    scanf("%d",&ind);
    if(ind<0 || ind>=*sizeOfArray){
        printf("Invalid position!");
        return;
    }
     for(int i = ind; i<*sizeOfArray; i++){
        arr[i] = arr[i+1];
    }
    (*sizeOfArray)--;
}

void bubbleSort(int arr[], int sizeOfArray){
    for(int i=0; i<sizeOfArray-1; i++){
        int swap =0;
        for(int j=0; j<sizeOfArray-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=1;
            }
        }
        if(swap==0){
            break;
        }
    }
}

void selectionSort(int arr[], int sizeOfArray){
    
    for(int i=0; i<sizeOfArray-1; i++){
        int minIndex = i;
        for(int j=i+1; j<sizeOfArray; j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;

    }

}

void insertionSort(int arr[], int sizeOfArray){
    for(int i=1; i<sizeOfArray; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    
}

void sortingOptions(int arr[],int sizeOfArray){
    int option;
    printf("Select type of sort: ");
    printf("\n1.\tBubble Sort \n2.\tSelection Sort \n3.\tInsertion Sort\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        bubbleSort(arr, sizeOfArray);
        break;
    case 2:
        selectionSort(arr, sizeOfArray);
        break;
    case 3:
        insertionSort(arr, sizeOfArray);   
        break;     
    default:
        printf("Invalid Input!");
        break;
    }
    return;
}

void linearSearch(int arr[], int sizeOfArray){
    int el;
    printf("Enter element: ");
    scanf("%d", &el);
    int i;
    for(i=0; i<sizeOfArray; i++){
        if(arr[i]==el){
            printf("Element found at index %d \n",i);
            break;
        }          
        }
        if(i==sizeOfArray){
            printf("Element not found.\n");
        }

}

void binarySearch(int arr[], int sizeOfArray){
    bubbleSort(arr, sizeOfArray);
    int el;
    printf("Enter element: ");
    scanf("%d", &el);
    int l = 0;
    int r = sizeOfArray-1;
    while(l<r){
        int mid = l+(r-l)/2;
        if(arr[mid]==el){
            printf("Element found.\n");
            break;
        }
        else if(el<arr[mid]){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    if(l==r){
        printf("Element not found.\n");
    }


}

void searchingOptions(int arr[], int sizeOfArray){
    int option;
    printf("Select type of search: ");
    printf("\n1.\tLinear Search \n2.\tBinary Search\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        linearSearch(arr, sizeOfArray);
        break;
    case 2:
        binarySearch(arr, sizeOfArray);
    default:
        break;
    }
    return;
}

int main(){

    int sizeOfArray;
    int option;
    printf("\nEnter the size of array:");
    scanf("%d", &sizeOfArray);
    int arr[sizeOfArray];
        printf("Enter elements of the array:\n");
    for(int i=0; i<sizeOfArray; i++){
        scanf("%d",&arr[i]);
    }
    do{
        printf("\nSelect the operation to be performed on array: ");
        printf("\n1.\tTraverse array \n2.\tInsertion \n3.\tDeletion \n4.\tSearching \n5.\tSorting \n6. \tExit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1 : traverseArray(arr, sizeOfArray);
            break;
        case 2 : insertion(arr, &sizeOfArray);
            break;
        case 3 : deletion(arr, &sizeOfArray);
            break;
        case 4 : searchingOptions(arr, sizeOfArray);
            break;
        case 5 : sortingOptions(arr, sizeOfArray);
            break;
        case 6 : return 0;
                 break;
        
        default: printf("Invalid option: ");
            break;
        }
    }
    while(1);

    return 0;
}