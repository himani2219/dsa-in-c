#include <stdio.h>

int main(){
    int rows;
    int cols;
    int count=0;
    printf("\nEnter rows of matrix: ");
        scanf("%d", &rows);
        printf("Enter columns of matrix: ");
        scanf("%d", &cols);
        int arr[rows][cols];

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                printf("Enter element at [%d][%d]: ",i+1,j+1);
                scanf("%d", &arr[i][j]);
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(arr[i][j]==0){
                    count++;
                }
            }
        }
    if(count>(rows*cols)/2){
        printf("It is a sparse matrix.\n");
    }
    else{
        printf("It is a dense matrix.\n");
    }
    return 0;
}