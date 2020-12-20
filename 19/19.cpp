#include <bits/stdc++.h>

using namespace std;

const int MAX_RULES = 132;

// children
vector<vector<int>> chi(MAX_RULES);
vector<vector<int>> alt_chi(MAX_RULES);
vector<string> leaf_val(MAX_RULES);

// dfs
vector<int> dfs_state;
vector<int> exit_order;

void dfs1(int i) {
    if(dfs_state[i] != 0) return;
    dfs_state[i] = 1;

    for(auto y : chi[i]) dfs1(y);
    for(auto y : alt_chi[i]) dfs1(y);

    dfs_state[i] = 2;
    exit_order.push_back(i);
}

vector<int> match_len;

bool does_match(int rule_id, string s);

bool does_match_w(int rule_id, string s){
    bool ans = does_match(rule_id, s);
    // cout << "does_match(" << rule_id << "," << s << ") = " << ans << endl;
    return ans;
}

bool does_match(int rule_id, string s) {
    if(match_len[rule_id] != s.length()) return false;
    if(chi[rule_id].size() == 0) return s == leaf_val[rule_id];

    bool match = true;
    int next = 0;
    for(auto y : chi[rule_id]) {
        if(does_match_w(y, s.substr(next, match_len[y])))
            next += match_len[y];
        else {
            match = false;
            break;
        }
    }
    if(match) {
        assert(next == s.length());
        return true;
    }

    if(alt_chi[rule_id].size() == 0) return false;
    match = true;
    next = 0;
    for(auto y : alt_chi[rule_id]) {
        if(does_match_w(y, s.substr(next, match_len[y])))
            next += match_len[y];
        else {
            match = false;
            break;
        }
    }
    if(match) {
        assert(next == s.length());
        return true;
    }
    return false;
}

bool does_match_0(int rule_id, string s) {
    if(s.size()%8!=0) return false; // |42| = |31| = 8
    int n = s.size()/8;
    for(int a=2;a<n;a++) {
        int b=n-a;
        if(!(b>=1 && a>b)) continue;

        bool match = true;
        int next = 0;
        for(int k=1;k<=a;k++){
            if(does_match_w(42, s.substr(next, match_len[42])))
                next += match_len[42];
            else {
                match = false;
                break;
            }
        }
        for(int k=1;k<=b;k++){
            if(does_match_w(31, s.substr(next, match_len[31])))
                next += match_len[31];
            else {
                match = false;
                break;
            }
        }
        if(match) {
            assert(next == s.length());
            return true;
        }
    }
    return false;
}

int main() {
    // read input
    string line;
    regex regex4("(\\d*): \"(.)\"");

    regex regex15("(\\d*): (\\d*)");
    regex regex2("(\\d*): (\\d*) (\\d*)");
    regex regex3("(\\d*): (\\d*) (\\d*) (\\d*)");
    
    regex regex0("(\\d*): (\\d*) [|] (\\d*)");
    regex regex1("(\\d*): (\\d*) (\\d*) [|] (\\d*) (\\d*)");
    while(getline(cin, line)) {
        if(line == "") break;
        smatch match;
        int rule_id;
        if(regex_match(line, match, regex0)) {
            rule_id = stoi(match[1].str());
            chi[rule_id].push_back(stoi(match[2].str()));
            alt_chi[rule_id].push_back(stoi(match[3].str()));
        } else if(regex_match(line, match, regex1)) {
            rule_id = stoi(match[1].str());
            chi[rule_id].push_back(stoi(match[2].str()));
            chi[rule_id].push_back(stoi(match[3].str()));
            alt_chi[rule_id].push_back(stoi(match[4].str()));
            alt_chi[rule_id].push_back(stoi(match[5].str()));
        } else if(regex_match(line, match, regex15)) {
            rule_id = stoi(match[1].str());
            chi[rule_id].push_back(stoi(match[2].str()));
        } else if(regex_match(line, match, regex2)) {
            rule_id = stoi(match[1].str());
            chi[rule_id].push_back(stoi(match[2].str()));
            chi[rule_id].push_back(stoi(match[3].str()));
        } else if(regex_match(line, match, regex3)) {
            rule_id = stoi(match[1].str());
            chi[rule_id].push_back(stoi(match[2].str()));
            chi[rule_id].push_back(stoi(match[3].str()));
            chi[rule_id].push_back(stoi(match[4].str()));
        }else if(regex_match(line, match, regex4)) {
            rule_id = stoi(match[1].str());
            leaf_val[rule_id] = match[2].str();
            assert(leaf_val[rule_id].size() == 1);
        } else {
            cout << "Couldn't parse input line '" << line << "'" << endl;
            exit(0);
        }
        assert(alt_chi[rule_id].size() == 0 || chi[rule_id].size() == alt_chi[rule_id].size());
    }
    int N = chi.size();
    cout << "Parsed " << N << " rules" << endl;

    // do dfs for topological order
    dfs_state = vector<int>(N, 0);
    dfs1(0);

    match_len = vector<int>(N, 0);

    for(int i=0;i<exit_order.size();i++) {
        int rule = exit_order[i];
        if(leaf_val[rule] != "") {
            match_len[rule] = 1;
            continue;
        }
        int len1=0,len2=0;
        for(auto y:chi[rule])
            len1 += match_len[y];
        for(auto y:alt_chi[rule])
            len2 += match_len[y];
        assert(len2 == 0 || len1 == len2);
        match_len[rule] = len1;
    }

    int count = 0;
    while(getline(cin, line)) {
        bool ans = does_match_0(0, line);
        cout << ans << "\t" << line << endl;
        count += ans;
    }
    cout << "count:" << count << endl;

    return 0;
}
