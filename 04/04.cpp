#include <bits/stdc++.h>

using namespace std;

vector<map<string, string>> passport_fields;

bool validate_numeric(string s, int len) {
    if(s.length() != len) return false;
    for(int i=0;i<len;i++)
        if(!(s[i]>='0' && s[i] <='9'))
            return false;
    return true;
}

bool is_hex(char c){
    return (c>='0'&&c<='9')||(c>='a'&&c<='f');
}

bool is_valid_passport_1(map<string, string> &p) {
    if (!p.contains("byr")) return false;
    if (!p.contains("iyr")) return false;
    if (!p.contains("eyr")) return false;
    if (!p.contains("hgt")) return false;
    if (!p.contains("hcl")) return false;
    if (!p.contains("ecl")) return false;
    if (!p.contains("pid")) return false;
    // if (!p.contains("cid")) return false;
    return true;
}

bool byr_valid(string s){
    if(!validate_numeric(s, 4)) return false;
    int year = stoi(s);
    if(!(1920 <= year && year <= 2002)) return false;
    return true;
}

bool iyr_valid(string s){
    if(!validate_numeric(s, 4)) return false;
    int year = stoi(s);
    if(!(2010 <= year && year <= 2020)) return false;
    return true;
}

bool eyr_valid(string s){
    if(!validate_numeric(s, 4)) return false;
    int year = stoi(s);
    if(!(2020 <= year && year <= 2030)) return false;
    return true;
}

bool hgt_valid(string s){
    string unit = s.substr(s.size() - 2);
    if(!(unit=="cm" || unit=="in")) return false;
    int amm = stoi(s.substr(0, s.size() - 2));
    if(unit == "cm") {
        if(!(150 <= amm && amm <= 193)) return false;
    } else if (unit == "in") {
        if(!(59 <= amm && amm <= 76)) return false;
    }
    return true;
}

bool hcl_valid(string s){
    if(!(s.size() ==7 && s[0] == '#' && is_hex(s[1]) && is_hex(s[2]) && is_hex(s[3]) && is_hex(s[4]) && is_hex(s[5]) && is_hex(s[6])))
        return false;
    return true;
}

bool ecl_valid(string ecl){
    if(!(ecl == "amb"||ecl=="blu"||ecl=="brn"||ecl=="gry"||ecl=="grn"||ecl=="hzl"||ecl=="oth")) return false;
    return true;
}

bool pid_valid(string s){
    return validate_numeric(s, 9);
}

void populate(int passport_id, string key, string val) {
    bool valid;
    if(key == "byr")  valid = byr_valid(val);
    else if(key == "iyr")  valid = iyr_valid(val);
    else if(key == "eyr")  valid = eyr_valid(val);
    else if(key == "hgt")  valid = hgt_valid(val);
    else if(key == "hcl")  valid = hcl_valid(val);
    else if(key == "ecl")  valid = ecl_valid(val);
    else if(key == "pid")  valid = pid_valid(val);
    else if(key == "cid")  valid = true;    
    else {
        cout << "unknown key: "<< key << endl;
        exit(0);
    }

    cout << passport_id << "\t" << key << "\t" << val << "\t" << valid << endl;
    if(valid)
      passport_fields[passport_id][key] = val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int passport_id = 0;
    passport_fields.push_back(map<string,string>());
    string s;
    while(getline(cin,s)) {
        if(s == "") {
            passport_id++;
            passport_fields.push_back(map<string,string>());
            continue;
        }
        size_t last = 0;
        size_t next = 0;
        while ((next = s.find(' ', last)) != string::npos) {
            string item = s.substr(last, next-last);
            populate(passport_id, item.substr(0, 3), item.substr(4));
            last = next + 1;
        }
        string item = s.substr(last);
        populate(passport_id, item.substr(0, 3), item.substr(4));
    }

    int valid = 0;
    for(auto p : passport_fields) {
        if(is_valid_passport_1(p))
            valid++;
    }
    cout << "VALID:" << valid << endl;

    return 0;
}
