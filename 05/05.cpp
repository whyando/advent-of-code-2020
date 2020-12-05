#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<string> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    // F=low bit, B=high bit (7)
    // L=low bit, R=high bit (3)

    int highestId=-1;

    vector<int> hit((1<<10), false);

    for(int i=0;i<N;i++){
        int row=0;
        for(int j=0;j<7;j++) {
            if(A[i][j] == 'B')
                row += (1<<(6-j));
        }
        int col=0;
        for(int j=0;j<3;j++) {
            if(A[i][7+j] == 'R')
                col += (1<<(2-j));
        }
        int id = row*8 + col;
        cout << row << "\t" << col << "\t" << id << endl;
        highestId = max(highestId, id);
        hit[id] = true;
    }
    cout << "highestId:" << highestId << endl;

    for(int i=1;i<(1<<10)-1;i++){
        if(hit[i-1] && !hit[i] && hit[i+1])
            cout << "missing:" << i << endl;
    }

    return 0;
}
