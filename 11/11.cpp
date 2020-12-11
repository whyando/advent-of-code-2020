#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H; cin >> H;
    vector<string> A(H);
    for(int i=0;i<H;i++)
        cin >> A[i];
    int W=A[0].size();

    while(true){
        vector<vector<int>> adj(H, vector<int>(W, 0));
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++) {
                adj[i][j] = 0;
                for(auto [di, dj] : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}}) {
                    int i1 = i +di; int j1 = j+dj;
                    if(i1 >=0 && i1<H && j1>=0 && j1<W) 
                        adj[i][j] += (A[i1][j1] == '#');                
                }
            }
        }

        int swaps=0;
        int people=0;
        for(int i=0;i<H;i++) {
            for(int j=0;j<W;j++){
                if(A[i][j] == 'L' && adj[i][j] == 0) {
                    A[i][j] = '#';
                    swaps++;
                }
                else if (A[i][j] == '#' && adj[i][j] >= 4) {
                    A[i][j] = 'L';
                    swaps++;
                }

                people += (A[i][j] == '#');
            }
        }

        cout << swaps << " " << people << endl;
        // for(int i=0;i<H;i++)
        //     cout << A[i] << endl;
        // cout << endl;

        if(swaps == 0)
            break;

    }

    return 0;
}
