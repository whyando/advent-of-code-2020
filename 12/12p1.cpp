#include <bits/stdc++.h>

using namespace std;

// E -> N -> W -> S
const vector<pair<int,int>> compass = {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<char> dir(N);
    vector<int> amm(N);
    for(int i=0;i<N;i++){
        string s; cin >> s;
        dir[i] = s[0];
        amm[i] = stoi(s.substr(1));
        //cout << dir[i] << " " << amm[i] << endl;
    }

    int x=0,y=0,rot=0;
    for(int i=0;i<N;i++) {
        char d=dir[i];
        int a=amm[i];
        if(d == 'N')   y+=a;
        else if(d == 'S') y-=a;
        else if(d == 'E') x+=a;
        else if(d == 'W') x-=a;
        else if(d == 'L') {
            assert(a==90 || a==270 || a==180);
            rot+=(a/90);
        }
        else if(d == 'R') {
            assert(a==90 || a==270 || a==180);
            rot-=(a/90);
        }
        else if(d == 'F') {
            rot = ((rot%4)+4)%4;
            x += compass[rot].first*a;
            y += compass[rot].second*a;
        }
    }

    cout << x << " " << y << "\t" << abs(x) + abs(y) << endl;

    return 0;
}
