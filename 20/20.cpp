#include <bits/stdc++.h>

using namespace std;

const int TILE_SIZE = 10;

/*
 __1___
|      |
2      0
|__3___|

*/

string get_edge(int side, const vector<string> &tile) {
    bool flip = side >= 4;
    string ret;
    side %=4;
    int j=-1;

    if(side == 1)  ret = tile[0];
    else if(side == 3) ret = tile[TILE_SIZE-1];
    else if(side == 2) j = 0;
    else               j=TILE_SIZE-1;

    if(j!=-1){
        for(int i=0;i<TILE_SIZE;i++)
            ret += tile[i][j];
    }
    if(flip) reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    vector<vector<string>> tiles;
    vector<int> tile_id;

    // Parse input
    string line;
    regex regex("Tile (\\d*):");
    while(getline(cin, line)) {
        smatch match;
        if(!regex_match(line, match, regex)) break;

        vector<string> tile(TILE_SIZE);
        for(int i=0;i<TILE_SIZE;i++){
            cin >> tile[i]; assert(tile[i].size() == TILE_SIZE);
        }
        cin.ignore();
        tiles.push_back(tile);
        tile_id.push_back(stoi(match[1].str()));
        getline(cin, line); // empty line
    }
    cout << "Parsed " << tiles.size() << " tiles" << endl;

    // Get all the edges
    map<string, vector<pair<int,int>>> count;
    for(int i=0;i<tiles.size();i++) {
        for(int j=0;j<8;j++){
            string edge = get_edge(j, tiles[i]);
            cout << j << " " << edge << endl;
            count[edge].push_back({i, j});
        }
        cout << endl;
    }

    // Find 4 corners
    int64_t prod = 1;
    for(int i=0;i<tiles.size();i++) {
        int hit=0;
        for(int j=0;j<8;j++){
            string edge = get_edge(j, tiles[i]);
            if(count[edge].size() == 2) hit++;
        }
        if(hit == 4){
            cout << i << "\t" << tile_id[i] << endl;
            prod *= tile_id[i];
        }
    }
    cout << "part 1 ans:" << prod << endl;

    // for(auto [k,v]:count) {
    //     cout << k << "\t" << v.size() << endl;
    // }

    return 0;
}
