/*
    Author: jbnerd
    Problem: https://community.topcoder.com/stat?c=problem_statement&pm=6186&rd=9823
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<long long int> get_factors(long long int n){
    vector<long long int> factors;
    long long int limit = sqrt(n);
    for(long long int i = 2; i <= limit; i++)
        if(n % i == 0)
            if (n/i == i)
                factors.push_back(i);
            else{
                factors.push_back(i);
                factors.push_back(n / i);
            }

    sort(factors.begin(), factors.end());

    return factors;
}

int countOperations(int N, int M){
    vector<int> distances(M + 1, M - N);
    distances[N] = 0;
    for(int i = N; i < M; i++){
        vector<long long int> factors = get_factors(i);
        for(long long int factor: factors)
            if (i + factor <= M) distances[i + factor] = min(1 + distances[i], distances[i + factor]);
    }

    if (distances[M] == M - N && distances[M] != 0)
        distances[M] = -1;
    return distances[M];
}

int main(){

    int N, M;
    cin >> N;
    cin >> M;
    int num_operations = countOperations(N, M);
    cout << num_operations << endl;

    return 0;
}
