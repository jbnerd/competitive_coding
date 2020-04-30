/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/LECANDY
*/

#include <stdio.h>
#include <stdlib.h>

int* read_array(int N){
    int* A = (int*) malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    return A;
}

int array_sum(int* array, int len){
    int sum = 0;
    for(int i = 0; i < len; i++)
        sum += array[i];
    return sum;
}

int main(){
    int num_test_cases;
    scanf("%d", &num_test_cases);
    for(int i = 0; i < num_test_cases; i++){
        int N, C;
        scanf("%d", &N);
        scanf("%d", &C);
        int* A = read_array(N);
        int sum = array_sum(A, N);
        if(C >= sum)
            printf("Yes\n");
        else
            printf("No\n");
    }
}