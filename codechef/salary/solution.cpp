/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/SALARY
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int* read_salaries(int N){
    int* salaries = (int*) malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
        scanf("%d", &salaries[i]);
    return salaries;
}

int sum(int* salaries, int N){
    int total = 0;
    for(int i = 0; i < N; i++)
        total += salaries[i];
    return total;
}

int main(){

    int num_test_cases;
    scanf("%d", &num_test_cases);
    while(num_test_cases--){
        int N;
        scanf("%d", &N);
        int* salaries = read_salaries(N);
        int min_salary = *(std::min_element(salaries, salaries + N));
        int tot_salary = sum(salaries, N);

        int num_steps = tot_salary - N * min_salary;
        printf("%d\n", num_steps);
    }

    return 0;
}
