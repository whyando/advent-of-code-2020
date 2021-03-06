#include <bits/stdc++.h>

using namespace std;

int64_t build_mask(string s, char t) {
    assert(s.size() == 36);
    int64_t mask=0;
    for(auto c :s) {
        mask*=2;
        if(c==t)
            mask+=1;        
    }
    return mask;
}

map<int64_t, int64_t> mem;

void f(int64_t index, int64_t mask, int64_t val, int i) {
    if(i == 36) {
        mem[index]=val; return;
    }
    if(mask&(1ll<<i)){
        f(index|(1ll<<i), mask, val, i+1);
        f(index&(~(1ll<<i)), mask, val, i+1);
        return;
    }
    f(index, mask, val, i+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t mask0=0;
    int64_t mask1=0;
    int64_t maskX=0;

    // IO
    regex mask_regex("mask = ([X01]{36})");
    regex mem_regex("mem\\[(\\d*)\\] = (\\d*)");
    std::smatch res;
    string line;
    while(getline(cin, line)) {
        // cout << line << endl;
        if(regex_match(line, res, mask_regex)) {
            cout << "mask " << res[1] << endl;
            mask0 = build_mask(res[1].str(), '0');
            mask1 = build_mask(res[1].str(), '1');
            maskX = build_mask(res[1].str(), 'X');
        } else if(regex_match(line, res, mem_regex)) {
            cout << "memset " << res[1] << " " << res[2] << endl;
            int64_t index = stoi(res[1].str());
            int64_t x = stoi(res[2].str());

            // apply masks - part1
            // x |= mask1;
            // x &= ~mask0;
            // cout << "setting " << index << " to " << x << endl;
            // mem[index] = x;

            index|=mask1;

            f(index, maskX, x, 0);
        } else {
            cout << "Couldn't parse line" << endl;
            exit(-1);
        }
    }

    int64_t sum = 0;
    for(auto [k,v]:mem){
        // cout << k << ":" << v << endl;
        sum += v;
    }
    cout << "sum=" << sum << endl;

    return 0;
}
