#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    A.push_back(0);

    sort(A.begin(), A.end());
    
    vector<int> diff(4,0);
    for(int i=1;i<=N;i++) {
        int d = A[i]-A[i-1];
        assert(d>=1 && d<=3);
        diff[d]++;
    }
    diff[3]++;
    cout << diff[1] << endl;
    cout << diff[2] << endl;
    cout << diff[3] << endl;

    // part2

    vector<int64_t> paths(N+1, 0);
    paths[0]=1;
    for(int i=1;i<=N;i++) {
        for(int k=1;k<=3;k++){
            if(i-k >= 0 && A[i]-A[i-k]<=3) {
                paths[i] += paths[i-k];
            }
        }
    }
    cout << paths[N] << endl;

    return 0;
}
