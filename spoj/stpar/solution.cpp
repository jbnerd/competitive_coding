/*
    Author: jbnerd
    Problem: https://www.spoj.com/problems/STPAR/
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> read_q(int N){
    queue<int> q;
    int temp;
    while(N--){
        cin >> temp;
        q.push(temp);
    }
    return q;
}

int main(){

    int N;
    cin >> N;
    while(N){
        queue<int> orig_q = read_q(N);
        stack<int> side_street;
        queue<int> final_q;
        int order_iter = 1;
        bool flag = true;
        while(!(orig_q.empty() && side_street.empty())){
            if(!orig_q.empty() && orig_q.front() == order_iter){
                orig_q.pop();
                final_q.push(order_iter);
                order_iter++;
            }else if(!side_street.empty() && side_street.top() == order_iter){
                side_street.pop();
                final_q.push(order_iter);
                order_iter++;
            }else if(!orig_q.empty() && orig_q.front() != order_iter){
                int truck = orig_q.front();
                orig_q.pop();
                side_street.push(truck);
            }else{
                flag = false;
                break;
            }
        }

        if(flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

        cin >> N;
    }

    return 0;
}
