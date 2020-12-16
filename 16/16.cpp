#include <bits/stdc++.h>

using namespace std;

int N = 20;

struct Target {
    string name;
    int a1;
    int b1;
    int a2;
    int b2;
};

vector<int> ans;

void f(const int i, const vector<int> &p, const vector<bool> &used, const vector<vector<bool>> &A) {
    if(i == N) {
        cout << "!!!" << endl;
        ans = p;
        return;
    }
    for(int j=0;j<N;j++) {
        if(used[j]) continue;
        if(!A[i][j]) continue;
        
        vector<int> p1(p);
        p1[i] = j;
        vector<bool> used1(used);
        used1[j] = true;
        f(i+1, p1, used1, A);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<bool> valid_value(1000, false);

    string line;
    regex valid_regex("(.*): (\\d*)-(\\d*) or (\\d*)-(\\d*)");
    std::smatch match;
    vector<Target> targets;
    while(getline(cin, line)) {
        if(line == "") break;
        // cout << line << endl;
        assert(regex_match(line, match, valid_regex));
        // cout <<  match[1] << " " << match[2] << " " << match[3] << " " << match[4] << " " << match[5] << endl;
        Target t;
        t.name = match[1].str();
        t.a1 = stoi(match[2].str());
        t.b1 = stoi(match[3].str());
        t.a2 = stoi(match[4].str());
        t.b2 = stoi(match[5].str());
        for(int k=t.a1; k<=t.b1; k++)
            valid_value[k]=true;
        for(int k=t.a2; k<=t.b2; k++)
            valid_value[k]=true;
        targets.push_back(t);
    }

    getline(cin, line);
    assert(line == "your ticket:");
    getline(cin, line);
    vector<int> myTicket;
    {
        while(regex_search(line, match, regex("(\\d{1,3})\\b"))){
            // cout << match[1] << endl;
            myTicket.push_back(stoi(match[1].str()));
            line = match.suffix();
        }
    }
    assert(myTicket.size() == N);
    getline(cin, line);
    assert(line == "");
    getline(cin, line);
    assert(line == "nearby tickets:");

    vector<vector<int>> valid_example(N, vector<int>());

    // sum of invalid values
    int error_rate = 0;
    while(getline(cin, line)) {
        vector<int> x;
        while(regex_search(line, match, regex("(\\d{1,3})\\b"))){
            // cout << match[1] << endl;
            x.push_back(stoi(match[1].str()));
            line = match.suffix();
        }
        bool ticket_valid = true;
        for(auto y:x){
            if(!valid_value[y]){
                error_rate += y;
                ticket_valid = false;
            }
        }
        assert(x.size() == N);
        if(ticket_valid)
            for(int i=0;i<N;i++)
                valid_example[i].push_back(x[i]);
    }
    cout << "(part 1) error_rate:" << error_rate << endl;

    vector<vector<bool>> A(N, vector<bool>(N, true)); // A[col ticket][listed];

    for(int col = 0; col < N; col++){
        // int col = 0; // col on ticket
        // vector<bool> possible(N, true); // col as listed
        for(auto y : valid_example[col]) {
            for(int j=0;j<N;j++){
                auto t = targets[j];
                bool in_bound = (t.a1 <= y && y<= t.b1) || (t.a2 <= y && y<= t.b2);
                if(!in_bound)
                    A[col][j] = false;
            }
        }
        // cout << "col=" << col << endl;
        // for(int i=0;i<N;i++)
        //     if(A[col][i])
        //         cout << targets[i].name << " ";
        // cout << endl;
    }

    for(int i=0;i<N;i++){
        cout << "col " << i << ":\t";
        for(int j=0;j<N;j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // find bipartite matching on 20x20
    vector<int> p(N, 0);
    vector<bool> used(N, false);
    f(0, p, used, A);

    int64_t prod = 1;
    for(int i=0;i<N;i++){
        cout << i << " -> " << ans[i] << " (" << targets[ans[i]].name << ")" << endl;
        assert(A[i][ans[i]]);

        if(targets[ans[i]].name.substr(0, 3) == "dep") {
            cout << myTicket[i] << endl;
            prod *= myTicket[i];
        }
    }

    cout << "(part 2) ans:" << prod << endl;

    return 0;
}
