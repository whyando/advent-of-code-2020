#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> A = {0,13,16,17,1,10,6};
    int N = A.size();

    map<int, int> m;
    for(int i=0;i<N-1;i++)
        m[A[i]] = i;

    int prev = A[N-1];
    for(int i=N;i<30000000;i++){
        int next;
        if (m.count(prev)) {
            next = (i-1)-m[prev];
        } else {
            next = 0;
        }
        m[prev] = i - 1;
        
        prev = next;
    }
    
    cout << prev << endl;

    return 0;
}
