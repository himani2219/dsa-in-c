#include <stdio.h>
int main(){

    int b =10;
    int *p;
    int *q;
    p=&b;
    q=&b;

    printf("%d\n",*p);
    printf("%d\n",p);
    printf("%d\n",b);
    printf("%d\n",&b);
    printf("%p\n",p);
    return 0;
}