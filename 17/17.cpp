#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<string> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    
    int M = N + 6*2;
    int O = M/2;
    vector<vector<vector<bool>>> X(M, vector<vector<bool>>(M, vector<bool>(M,false))); // x[z][y][x]
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            if(A[i][j] == '#')
                X[O][O+i-N/2][O+j-N/2] = true;
        }

    for(int t=1;t<=6;t++) {
        // Debug
        // for(int z=0;z<M;z++) {
        //     if(abs(z-O)>=t) continue;
        //     cout << "z=" << z-O << endl;
        //     for(int y=0;y<M;y++){
        //         for(int x=0;x<M;x++)
        //             cout << X[z][y][x] << " ";
        //         cout << endl;
        //     }
        //     cout << endl;
        // }

        int total = 0;
        vector<vector<vector<bool>>> X_next(M, vector<vector<bool>>(M, vector<bool>(M,false)));
        for(int z=0;z<M;z++){
        for(int y=0;y<M;y++){
        for(int x=0;x<M;x++){
            int adj=0;
            for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
            for(int dz=-1;dz<=1;dz++){
                if(dx == 0 && dy == 0 && dz == 0) continue;
                int x1=x+dx; int y1=y+dy; int z1=z+dz;
                if(!(0 <= x1 && x1 < M && 0 <= y1 && y1 < M && 0 <= z1 && z1 < M)) continue;
                if(X[z1][y1][x1]) adj++;
            }}}
            if(X[z][y][x])
                X_next[z][y][x] = (adj == 2 || adj == 3);
            else
                X_next[z][y][x] = (adj == 3);
            total += X_next[z][y][x];
        }}}

        cout << "t=" << t << "\t" << total << endl;
        swap(X, X_next);
    }

    return 0;
}
