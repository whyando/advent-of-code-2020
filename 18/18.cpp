#include <bits/stdc++.h>

using namespace std;

int64_t f(const string::iterator s, const string::iterator t) {
    // for(auto it = s; it != t; it++)
    //     cout << *it;
    // cout << endl;

    int d = 0;
    string::iterator a,b;
    list<int64_t> x_arr;
    list<char> op_arr;
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
                x_arr.push_back(x);
            }
        }
        else if(d == 0 && *it == '+') op_arr.push_back('+');
        else if(d == 0 && *it == '*') op_arr.push_back('*');
        else if(d == 0 && *it >= '0' && *it <= '9') {
            int64_t x = *it-'0';
            x_arr.push_back(x);
        }
    };

    assert(x_arr.size() == op_arr.size() + 1);
    assert(d==0);
    int N = x_arr.size();

    // pass 1 for addition
    auto it = next(x_arr.begin());
    auto it1 = op_arr.begin();

    while(it != x_arr.end()) {
        if(*it1 == '+') {
            *(prev(it)) += *it;
            it = x_arr.erase(it);
            it1 = op_arr.erase(it1);
        } 
        else {
            it++;
            it1++;
        }
    }
    assert(it1 == op_arr.end());

    int64_t ret = 1;
    // pass 2 for multiplication
    for(auto x : x_arr)
        ret *= x;
    
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
