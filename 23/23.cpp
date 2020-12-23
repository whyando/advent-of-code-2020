#include <bits/stdc++.h>

using namespace std;

int decr(int x){
    if(x == 1) return 9;
    return x-1;
}

int main() {
    // const vector<int> input = {3,8,9,1,2,5,4,6,7};
    const vector<int> input = {7,9,2,8,4,5,1,3,6};
    deque<int> v(input.begin(), input.end());

    for(int T=0;T<100;T++) {
        for(auto x : v)
            cout << x << " ";
        cout << endl;

        int a = v.front(); v.pop_front();
        int x = v.front(); v.pop_front();
        int y = v.front(); v.pop_front();
        int z = v.front(); v.pop_front();
        int t = decr(a);
        while(t == x || t == y || t == z)
            t = decr(t);
        auto k = find(v.begin(), v.end(), t);
        k = v.insert(k + 1, x);
        k = v.insert(k + 1, y);
        k = v.insert(k + 1, z);
        v.insert(v.end(), a);
    }

    for(auto x : v)
        cout << x << " ";
    cout << endl;

    return 0;
}
