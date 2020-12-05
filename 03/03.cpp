#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H; cin >> H;
    vector<string> A(H);
    for(int i=0;i<H;i++)
        cin >> A[i];
    for(int i=0;i<H;i++)
        cout << A[i] << endl;

    int W = A[0].size();

    int di = 2;
    int dj = 1;

    int hit = 0;
    for(int i=0;di*i<H;i++){
        if (A[di*i][(dj*i)%W] == '#') {
            hit++;
        }
    }
    cout << hit << endl;

    return 0;
}
