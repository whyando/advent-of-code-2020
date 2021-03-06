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

    int s_x=0,s_y=0;
    int w_x=10,w_y=1;
    for(int i=0;i<N;i++) {
        char d=dir[i];
        int a=amm[i];
        if(d == 'N')   w_y+=a;
        else if(d == 'S') w_y-=a;
        else if(d == 'E') w_x+=a;
        else if(d == 'W') w_x-=a;
        else if(d == 'L') {
            assert(a==90 || a==270 || a==180);
            for(int k=1;k<=a/90;k++) {
                int ph = w_y;
                w_y = w_x;
                w_x = -ph;
            }
        }
        else if(d == 'R') {
            assert(a==90 || a==270 || a==180);
            a = 360-a;
            for(int k=1;k<=a/90;k++) {
                int ph = w_y;
                w_y = w_x;
                w_x = -ph;
            }
        }
        else if(d == 'F') {
            s_x += w_x*a;
            s_y += w_y*a;
        }
        cout << s_x << " " << s_y << endl;
    }

    cout << s_x << " " << s_y << "\t" << abs(s_x) + abs(s_y) << endl;

    return 0;
}
