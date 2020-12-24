#include <bits/stdc++.h>

using namespace std;

int main() {
    set<pair<int,int>> is_black;

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
        if(is_black.count({x,y}) == 1) {
            is_black.erase({x,y});
        } else {
            is_black.insert({x,y});
        }
    }

    for(int t=1;t<=100;t++) {
        // Count adjacent black tiles
        // NOTE: Not necessary to make sure 'adj_black' contains a key for all current black tiles not adjacent to any other black tile, since those tiles are turned to white anyway
        map<pair<int,int>, int> adj_black;
        for(auto [x,y]:is_black) {
            adj_black[{x+1,y}]++;
            adj_black[{x-1,y}]++;
            adj_black[{x,y+1}]++;
            adj_black[{x,y-1}]++;
            adj_black[{x+1,y-1}]++;
            adj_black[{x-1,y+1}]++;
        }

        // Flip tiles, based on adjacency rules
        set<pair<int,int>> is_black_next;
        for(auto [key,num_adj]:adj_black) {
            bool flip;
            if(is_black.count(key)){
                flip = (num_adj == 0 || num_adj > 2);
                if(!flip)
                    is_black_next.insert(key);
            } else {
                flip = (num_adj == 2);
                if(flip)
                    is_black_next.insert(key);
            }
        }
        swap(is_black, is_black_next);
    }
    cout << is_black.size() << endl;

    return 0;
}
