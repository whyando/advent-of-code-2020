#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 200;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                if(A[i]+A[j]+A[k] == 2020) {
                    cout << i << "\t" << A[i] << endl;
                    cout << j << "\t" << A[j] << endl;
                    cout << k << "\t" << A[k] << endl;
                    cout << A[i]*A[j]*A[k] << endl;
                }
            }
        }
    }

    return 0;
}