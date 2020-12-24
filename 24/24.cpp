#include <bits/stdc++.h>

using namespace std;

int main() {
    map<pair<int,int>, bool> is_black;

    // Parse input
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
        
        // represent each point uniquely as pair [x,y]
        int x = cnt["e"] - cnt["w"] - cnt["nw"] + cnt["se"];
        int y = cnt["ne"] - cnt["sw"] + cnt["nw"] - cnt["se"];

        // flip
        is_black[{x,y}] = !is_black[{x,y}];
    }

    for(int t=1;t<=100;t++) {
        // Count adjacent black tiles
        // Make sure 'adj_black' contains a key for all current black tiles as well as any tile adjacent to a black tile
        map<pair<int,int>, int> adj_black;
        for(auto [k,v]:is_black) {
            if(!v) continue;
            auto [x,y]=k;
            adj_black.insert({{x,y}, 0}); // fails if element exists
            adj_black[{x+1,y}]++;
            adj_black[{x-1,y}]++;
            adj_black[{x,y+1}]++;
            adj_black[{x,y-1}]++;
            adj_black[{x+1,y-1}]++;
            adj_black[{x-1,y+1}]++;
        }

        // Flip tiles, based on adjacency rules
        int num_black=0;
        map<pair<int,int>, bool> is_black_next = is_black;
        for(auto [k,num_adj]:adj_black) {
            auto [x,y]=k;
            bool flip;
            if(is_black[{x,y}]){
                flip = (num_adj == 0 || num_adj > 2);
            } else {
                flip = (num_adj == 2);
            }
            if(flip)
                is_black_next[{x,y}] = !is_black_next[{x,y}];
            num_black += is_black_next[{x,y}];
        }
        cout << "Day " << t << ":" << num_black << endl;

        swap(is_black, is_black_next);
    }

    return 0;
}
