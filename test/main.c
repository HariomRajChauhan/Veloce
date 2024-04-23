#include<stdio.h>
#define MAX 1000
#include "input.c"
#include "output.c"3


int main(){
    int n, a[MAX];
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    input_array(a, n);

    printf("The elements are: ");
    print_array(a, n);


    

    return 0;
}