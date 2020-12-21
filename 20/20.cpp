#include <bits/stdc++.h>

using namespace std;

const int TILE_SIZE = 10;

/*
 __1___
|      |
2      0
|__3___|

*/

void rotate_tile(vector<string> &tile){
    vector<string> tile1(tile);
    for(int i=0;i<TILE_SIZE;i++){
        for(int j=0;j<TILE_SIZE;j++){
            int i1 = j;
            int j1 = TILE_SIZE-1-i;
            tile1[i1][j1] = tile[i][j];
        }
    }
    tile = tile1;
}

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
    const int NUM_TILE = sqrt(tiles.size());
    cout << "Parsed " << tiles.size() << " tiles (" << NUM_TILE << "x" << NUM_TILE << ")" << endl;

    // Get all the edges
    map<string, vector<pair<int,int>>> count;
    for(int i=0;i<tiles.size();i++) {
        for(int j=0;j<8;j++){
            string edge = get_edge(j, tiles[i]);
            // cout << j << " " << edge << endl;
            count[edge].push_back({i, j});
        }
        // cout << endl;
    }

    auto is_edge = [&count](int j, vector<string> &tile) {
        string edge = get_edge(j, tile);
        return count[edge].size() == 2;
    };

    
    // Construct full image
    const int SZ = 1 + NUM_TILE*(TILE_SIZE-1);
    vector<bool> used(tiles.size(), false);
    vector<string> img(SZ, string(SZ, ' '));

    auto place_tile = [&img](int i, int j, const vector<string> &tile){
        int i_start = i*(TILE_SIZE-1);
        int j_start = j*(TILE_SIZE-1);
        for(int i=0; i < TILE_SIZE;i++){
            for(int j=0; j<TILE_SIZE;j++){
                img[i_start+i][j_start+j] = tile[i][j];
            }
        }
    };

    // Find ANY corner
    int corner;
    for(int i=0;i<tiles.size();i++) {
        int hit=0;
        for(int j=0;j<8;j++) hit += is_edge(j, tiles[i]);
        if(hit == 4) {
            corner = i;
            break;
        }
    }

    // rotate corner until top-left is edge
    while(!(
        is_edge(1, tiles[corner]) && is_edge(2, tiles[corner])
    )){
        rotate_tile(tiles[corner]);
    }
    place_tile(0, 0, tiles[corner]);
    used[corner] = true;
    for(int i=0;i<SZ;i++)
        cout << img[i] << endl;
    cout << endl;

    for(int i=0;i<1;i++){
        for(int j=0;j<NUM_TILE;j++){
            if(i==0&&j==0) continue;
            string left_edge;
            int ii = i*(TILE_SIZE-1);
            int jj = j*(TILE_SIZE-1);
            for(int i2=0;i2<TILE_SIZE;i2++)
                left_edge += img[ii+i2][jj];
            cout << left_edge << endl;
            vector<pair<int,int>> z = count[left_edge];
            assert(z.size() >= 4);
            int w = 0;
            while(used[z[w].first]) w++;

            // place tile W
            while(!is_edge(2, tiles[w])) {
                rotate_tile(tiles[w]);
                cout << "!" << endl;
            }
        }
    }

    return 0;
}
