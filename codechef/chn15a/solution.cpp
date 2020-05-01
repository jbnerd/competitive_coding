/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/CHN15A
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int* read_values(int N){
    int* values = (int*) malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", &values[i]);
    return values;
}

int find_num_divisible(int* values, int N, int K, int divisor){
    int total_divisible = 0;
    for(int i = 0; i < N; i++)
        if((values[i] + K) % divisor == 0)
            total_divisible++;
    return total_divisible;
}

int main(){

    int num_test_cases;
    scanf("%d", &num_test_cases);
    while(num_test_cases--){
        int N, K;
        scanf("%d", &N);
        scanf("%d", &K);
        int* values = read_values(N);
        printf("%d\n", find_num_divisible(values, N, K, 7));
    }

    return 0;
}

