/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/RAINBOWA
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int* read_array(int N){
    int* array = (int*) malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", &array[i]);
    return array;
}

bool check_consistency(int* array, int N){
    bool flag = true;
    int iter_start = 0, iter_end = N - 1;

    for(int num_tracker = 1; num_tracker < 7; num_tracker++){
        if(array[iter_start] != num_tracker || array[iter_end] != num_tracker){
            flag = false;
            break;
        }
        
        int freq_start = 0, freq_end = 0;
        while(iter_start <= N && array[iter_start] == num_tracker) iter_start++, freq_start++;
        while(iter_end > 0 && array[iter_end] == num_tracker) iter_end--, freq_end++;
        if(freq_start != freq_end){
            flag = false;
            break;
        }
    }

    if(flag && iter_start <= iter_end){
        for(; iter_start <= iter_end; iter_start++){
            if(array[iter_start] != 7){
                flag = false;
                break;
            }
        }
    }else{
        flag = false;
    }

    return flag;
}

int main(){

    int num_test_cases;
    scanf("%d", &num_test_cases);
    while(num_test_cases--){
        int N;
        scanf("%d", &N);
        int* array = read_array(N);
        if(check_consistency(array, N))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
