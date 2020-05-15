/*
    Author: jbnerd
    Problem: https://www.spoj.com/problems/HISTOGRA/
*/

#include <iostream>
#include <stack>
#include <vector>

#define lli long long int

using namespace std;

vector<int> read_hist(int n){
    vector<int> hist;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        hist.push_back(temp);
    }
    return hist;
}

lli rect_area(lli height, lli left_index, lli right_index){
    return (right_index - left_index) * height;
}

int main(){

    int n;
    cin >> n;
    while(n != 0){
        stack<int> s;
        vector<int> hist = read_hist(n);

        lli max_area = 0;
        for(int iter = 0; iter < hist.size(); iter++){
            if(s.empty() || hist[s.top()] <= hist[iter]){
                s.push(iter);
            }else{
                while(!s.empty() && hist[s.top()] > hist[iter]){
                    int top_height = hist[s.top()];
                    s.pop();
                    int left_index = (s.empty()) ? 0 : s.top() + 1, right_index = iter;
                    max_area = max(max_area, rect_area(top_height, left_index, right_index));
                }
                s.push(iter);
            }
        }

        while(!s.empty()){
            int top_height = hist[s.top()];
            s.pop();
            int left_index = (s.empty()) ? 0 : s.top() + 1, right_index = n;
            max_area = max(max_area, rect_area(top_height, left_index, right_index));
        }

        cout << max_area << endl;

        cin >> n;
    }

    return 0;
}
