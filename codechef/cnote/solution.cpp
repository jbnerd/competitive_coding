/*
    Author: jbnerd
    Problem: https://www.codechef.com/problems/CNOTE
*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int** read_pages_and_prices(int N){
    int** pages_and_prices = (int**) malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++){
        pages_and_prices[i] = (int*) malloc(2 * sizeof(int));
        scanf("%d", &pages_and_prices[i][0]);
        scanf("%d", &pages_and_prices[i][1]);
    }
    return pages_and_prices;
}

int main(){
    
    int num_test_cases;
    scanf("%d", &num_test_cases);
    while(num_test_cases--){
        int X, Y, K, N;
        scanf("%d", &X);
        scanf("%d", &Y);
        scanf("%d", &K);
        scanf("%d", &N);
        int** pages_and_prices = read_pages_and_prices(N);

        int pages_required = X - Y;
        bool flag = false;
        for(int i = 0; i < N; i++){
            if(pages_and_prices[i][0] >= pages_required && pages_and_prices[i][1] <= K){
                flag = true;
                break;
            }
        }

        if(flag)
            printf("LuckyChef\n");
        else
            printf("UnluckyChef\n");
    }

    return 0;
}
