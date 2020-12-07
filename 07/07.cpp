#include <bits/stdc++.h>

using namespace std;


set<string> holds_shinygold;
map<string, vector<string>> direct_parent;
map<string, vector<pair<string,int>>> child;

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

map<string, int> dfs_state;
vector<string> exit_order;

void dfs(string x) {
    if(dfs_state[x] != 0) return;

    cout << "ENTER " << x << endl;
    dfs_state[x] = 1;

    for(auto y : child[x])
        dfs(y.first);

    cout << "EXIT " << x << endl;
    exit_order.push_back(x);
    dfs_state[x] = 2;
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
        if(contents != " no other bags.") {
            std::smatch res;
            std::regex regex("(\\d*) (\\w*) (\\w*) bags?");

            string::const_iterator searchStart( contents.cbegin() );
            while(std::regex_search(searchStart, contents.cend(), res, regex)) {
                string desc = res.str(2) + res.str(3);
                string count = res.str(1);
                cout << desc << " " << count << endl;
                direct_parent[desc].push_back(m1 + m2);
                child[m1+m2].push_back({desc,stoi(count)});

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

    dfs("shinygold");

    map<string, int> num_bags_inside;

    for(auto s : exit_order) {
        for(auto y:child[s]) {
            num_bags_inside[s] += y.second*(num_bags_inside[y.first] + 1);
        }
    }
    cout << num_bags_inside["shinygold"] << endl;

    return 0;
}
