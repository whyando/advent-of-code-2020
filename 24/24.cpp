#include <bits/stdc++.h>

using namespace std;

int main() {
    map<pair<int,int>, int> flip;

    string line;
    while(getline(cin,line)) {
        map<string,int> cnt;
        for(int i=0;i<line.size();i++) {
            string dir;
            if(line[i] == 'n' || line[i] == 's') {
                dir = string(1,line[i])+string(1,line[i+1]);
                i++;
            }
            else {
                dir = string(1,line[i]);
            }
            cnt[dir]++;
        }

        int x = cnt["e"] - cnt["w"] - cnt["nw"] + cnt["se"];
        int y = cnt["ne"] - cnt["sw"] + cnt["nw"] - cnt["se"];

        flip[{x,y}]++;
    }

    int black = 0;
    for(auto [k,v]:flip){
        cout << k.first << "," << k.second << ":\t" << v << endl;
        if(v%2 == 1)
            black++;
    }

    cout << black << endl;

    return 0;
}
