/*
    Author: jbnerd
    Problem: https://community.topcoder.com/stat?c=problem_statement&pm=4475&rd=8012

    Expression A*M^2 + B*M + C can be written as M*(A*M + B) + C
    if C < 0:
        The quadratic curve will cut the Y-axis below the origin. Hence M = 0 will yield a negative number.
        Negative numbers by default are not prime, hence M = 0 is the answer.
    else
        The expression will definitely become composite at M = C, since C will be a common factor. Thus we
        get an upper bound on M, reducing the search space. A linear search on M in [0, C] will yield the 
        answer.
*/

#include <cmath>
#include <iostream>

using namespace std;


class PrimePolynom{
    public:
        int reveal(int A, int B, int C){
            int M = C;
            for(int i = 0; i <= C; i++){
                long long int expression = A * i * i + B * i + C;
                if(!is_prime(expression)){
                    M = i;
                    break;
                }
            }
            return M;
        }

    private:
        bool is_prime(long long int n){
            bool flag = true;
            
            if(n % 2 == 0)
                flag = false;
            else
                for(long long int i = 3; i <= sqrt(n); i += 2)
                    if(n % i == 0){
                        flag = false;
                        break;
                    }

            return flag;
        }
};

int main(){

    int A, B, C;
    PrimePolynom tester = PrimePolynom();
    cin >> A; cin >> B; cin >> C;
    if(C < 0)
        cout << "0" << endl;
    else
        cout << tester.reveal(A, B, C) << endl;

    return 0;
}