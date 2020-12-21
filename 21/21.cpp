#include <bits/stdc++.h>

using namespace std;

// String splitting utilty: https://stackoverflow.com/a/37454181
vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

struct Food {
    // ingredients
    vector<string> ingre;
    // (known) allergens
    vector<string> alleg;
};

int main() {
    vector<Food> foods;
    string line;
    const regex line_regex("(.*) \\(contains (.*)\\)");
    while(getline(cin, line)) {
        smatch match;
        assert(regex_match(line, match, line_regex));

        Food f;
        f.ingre = split(match[1].str(), " ");
        f.alleg = split(match[2].str(), ", ");
        foods.push_back(f);
    }

    set<string> all_ingre;
    set<string> all_alleg;
    for(auto f:foods) {
        for(auto i:f.ingre)
            all_ingre.insert(i);
        for(auto a:f.alleg)
            all_alleg.insert(a);
    }
    cout << all_alleg.size() << " " << all_ingre.size() << endl;

    // m[i,a] = { is ingredient i cleared from containing allergen a }
    map<pair<string, string>, bool> m;

    for(auto f:foods) {
        // If f contains allergen a, => each ingredient not in f cannot contain that allergen
        
        // for each ingredient not in f
        for(auto i:all_ingre){
            bool f_contains = find(f.ingre.begin(), f.ingre.end(), i) != f.ingre.end();
            if(f_contains) continue;

            for(auto a:f.alleg) {
                m[{i, a}] = true;
            }
        }
    }

    map<string, bool> no_allergen;
    for(auto a:all_alleg)
        cout << a << " ";
    cout << endl;
    for(auto i:all_ingre){
        int count = 0;
        for(auto a:all_alleg)
            count += m[{i ,a}];
        if(count == all_alleg.size())
            no_allergen[i] = true;

        if(count != all_alleg.size()){
            cout << i << ":\t";
            for(auto a:all_alleg)
                cout << !m[{i ,a}] << " ";
            cout << endl;
        }
    }

    int ans=0;
    for(auto f:foods) {
        for(auto i:f.ingre){
            if(no_allergen[i])
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
