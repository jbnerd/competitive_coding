/*
    Author: jbnerd
    Problem: https://www.spoj.com/problems/JNEXT/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> read_number(int N){
    vector<int> number;
    number.resize(N);
    for(auto &i: number)
        cin >> i;
    return number;
}

bool is_decreasing(vector<int>& number){
    bool flag = true;
    for(int i = 0; i < number.size() - 1; i++){
        if(number[i] < number[i + 1]){
            flag = false;
            break;
        }
    }
    return flag;
}

int find_pivot_index(vector<int>& number){
    int i;
    for(i = number.size() - 2; i >= 0; i--)
        if(number[i] < number[i + 1])
            break;
    return i;
}

int find_swap_index(vector<int>& number, int pivot_index){
    int swap_index = pivot_index + 1;
    for(int i = pivot_index + 1; i < number.size(); i++)
        if(number[i] < number[swap_index] && number[i] > number[pivot_index])
            swap_index = i;
    return swap_index;
}

void swap(vector<int>& number, int pivot_index, int swap_index){
    int temp = number[pivot_index];
    number[pivot_index] = number[swap_index];
    number[swap_index] = temp;
}

void print_number(vector<int>& number){
    for(auto &i: number)
        cout << i;
    cout << endl;
}

int main(){

    int num_test_cases;
    cin >> num_test_cases;
    while(num_test_cases--){
        int N;
        cin >> N;
        vector<int> number = read_number(N);
        if(is_decreasing(number)){
            cout << "-1" << endl;
            continue;
        }else{
            int pivot_index = find_pivot_index(number);
            int swap_index = find_swap_index(number, pivot_index);
            swap(number, pivot_index, swap_index);
            sort(number.begin() + pivot_index + 1, number.end());
            print_number(number);
        }
        
    }

    return 0;
}