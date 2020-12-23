#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

constexpr int decr(int x){
    if(x == 0) return N-1;
    return x-1;
}

int main() {
    // const vector<int> input = {3,8,9,1,2,5,4,6,7};
    const vector<int> input = {7,9,2,8,4,5,1,3,6};

    // next[i] is the number in the list after i
    vector<int> next(N);
    iota(next.begin(), next.end(), 1);
    next[N-1] = input[0]-1;
    for(int i=0;i<input.size()-1;i++)
        next[input[i]-1] = input[i+1]-1;
    if(input.size() != N) next[input.back()-1] = input.size();
    else                  next[input.back()-1] = input[0]-1;

    int cur = input[0]-1;
    for(int tt=0;tt<10000000;tt++) {
        // 'cur' is the current cup

        // A,B and C are the picked up cups
        const int A = next[cur];
        const int B = next[A];
        const int C = next[B];
        // D is the cup after the 3 picked up cups
        const int D = next[C];

        // T is the 'destination cup', which is 1 less than cur, but may not be A,B or C
        int T = decr(cur);
        while(T == A || T == B || T == C)
            T = decr(T);
        
        // linked-list esqe transformations to move the cups around
        next[cur] = D;
        next[C] = next[T];
        next[T] = A;    

        // move onto the next cup
        cur = next[cur];
    }

    cout << next[0]+1 << endl;
    cout << next[next[0]]+1 << endl;
    cout << (int64_t)(next[0]+1) * (next[next[0]]+1) << endl;

    return 0;
}
