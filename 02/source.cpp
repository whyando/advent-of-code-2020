#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ret = 0;
    for(int i=0;i<1000;i++){
        int x,y;
        char e1, e2;
        char d;
        string s;
        cin >> x >> e1 >> y >> d >> e2 >> s;
        cout << x << endl;
        cout << y << endl;
        cout << d << endl;
        cout << s << endl;
        
        int count = 0;
        // for(auto c : s){
        //     if (c == d)
        //         count++;
        // }
        // if (x<=count&&count<=y){
        //     cout  << "!" << endl;
        //     ret++;
        // }
        if (s[x-1] == d)
            count++;
        if(s[y-1] == d)
            count++;
        if(count == 1)
            ret++;
    }
    cout << ret << endl;

    return 0;
}