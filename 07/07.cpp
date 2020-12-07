#include <bits/stdc++.h>

using namespace std;


set<string> holds_shinygold;
map<string, vector<string>> direct_parent;

void f(string x) {
    if (holds_shinygold.count(x) != 0)
        return;
    holds_shinygold.insert(x);
    cout << x << endl;

    if(direct_parent.contains(x) != 0) {
        for(auto y : direct_parent[x]) {
            f(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int N; cin >> N;
    vector<string> A(N);
    for(int i=0;i<N;i++) {
        string m1, m2;
        string bags;
        string contain;
        string contents;
        cin >> m1 >> m2 >> bags >> contain;
        getline(cin,contents);

        cout << m1 << m2 << ":" << endl; // << contents << endl;
        vector<string> v;
        if(contents != " no other bags."){
            std::smatch res;
            std::regex regex("(\\d*) (\\w*) (\\w*) bags?");

            string::const_iterator searchStart( contents.cbegin() );
            while(std::regex_search(searchStart, contents.cend(), res, regex)) {
                string desc = res.str(2) + res.str(3);
                cout << desc << " " << res[1] << endl;
                direct_parent[desc].push_back(m1 + m2);

                searchStart = res.suffix().first;
            }
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "direct parent:" << endl;
    for(auto [k, v] : direct_parent) {
        cout << k << ":";
        for(auto x : v) {
            cout << x << ",";
        }
        cout << endl;
    }
    cout << endl;

    cout << "START" << endl;
    for(auto x : direct_parent["shinygold"]) {
        f(x);
    }
    cout << holds_shinygold.size() << endl;

    return 0;
}
