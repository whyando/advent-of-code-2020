#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<string>> A;
    vector<string> B;

    string s;
    while(getline(cin, s)) {
        if(s=="") {
            assert(B.size() != 0);
            A.push_back(B);
            B.clear();
        }
        else {
            B.push_back(s);
        }
    }
    assert(B.size() == 0);
    
    int total = 0;
    int total_all = 0;
    for(auto group : A) {
        map<char, int> m;
        for(auto entry : group){
            for(auto c:entry){
                m[c]++;
            }
        }

        int count=0; // all
        for(auto [k, v] : m) {
            if(v == group.size())
                count++;
        }
            
        cout << m.size() << endl;
        total += m.size();
        total_all += count;
    }

    cout << "total:" << total << endl;
    cout << "total_all:" << total_all << endl;

}
