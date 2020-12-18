#include <bits/stdc++.h>

using namespace std;

int64_t f(const string::iterator s, const string::iterator t) {
    // for(auto it = s; it != t; it++)
    //     cout << *it;
    // cout << endl;

    int d = 0;
    char op = '\0';
    int64_t ret;
    string::iterator a,b;
    for(auto it = s; it != t; it++) {
        if(*it == '(') {
            d++;
            if(d == 1) {
                a = it + 1;
            }
        }
        else if(*it == ')') {
            d--;
            if(d == 0) {
                b = it;
                int64_t x = f(a,b);
                if(op == '\0') ret = x;
                if(op == '+')  ret += x;
                if(op == '*')  ret *= x;
            }
        }
        else if(d == 0 && *it == '+') op = '+';
        else if(d == 0 && *it == '*') op = '*';
        else if(d == 0 && *it >= '0' && *it <= '9') {
            int64_t x = *it-'0';
            if(op == '\0') ret = x;
            if(op == '+')  ret += x;
            if(op == '*')  ret *= x;
        }
    };
    assert(d==0);
    
    for(auto it = s; it != t; it++)
        cout << *it;
    cout << " = " << ret << endl;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N; cin.ignore();
    vector<string> A(N);    
    for(int i=0;i<N;i++)
        getline(cin, A[i]);

    int64_t sum = 0;
    for(int i=0;i<N;i++){
        sum += f(A[i].begin(), A[i].end());
    }
    cout << "sum:" << sum << endl;
    return 0;
}
