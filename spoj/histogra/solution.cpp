/*
    Author: jbnerd
    Problem: https://www.spoj.com/problems/HISTOGRA/

    Commentary:
        If we know the shortest block in a range [li, ri] is hist[i], then the area of the rectangle
        formed by this range and hist[i] is given by (ri - li) * hist[i]. If we know the bounds [li, ri]
        for every i, then the area of the largest rectangle is simply the maximum of all such bounded
        rectangles for every i in [0, n-1].

        Maintaining li:
            a) For any increasing sequence li for any i is simply hist[i - 1]
            b) For any non-increasing element hist[i] in a sequence, li can be found by traversing hist
               leftward till we encounter an element j: j < i and hist[j] < hist[i]. Otherwise li = -1.

            Conditions a) and b) can be represented by a LIFO policy. For any hist[i], if hist[i] >= stack.top()
            then push i on top of the stack. Otherwise we pop the stack till we establish hist[i] >= stack.top()
            and push the current element onto the stack. Therefore maintaining the stack.top() is invariantly
            li for the popped element.

        Maintaining ri:
            By the policy we sought for maintaining li, by definition hist[i] will be ri in option b) for
            the popped elements.
        
        Therefore, we can compute the area of the rectangle formed by popped element j and its corresponding
        bound lj and rj while maintaining the max over all the computed areas.

    Note:
        By describing the policy for maintaining li, we have inadvertantly developed a tool popularly known as
        a monotonic stack. For any binary associative operator (BOP), we can easily maintain the left just largest
        and the right just largest element for every element in a list.
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
