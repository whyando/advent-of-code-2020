#include <bits/stdc++.h>

using namespace std;

// Run to completion/infinite loop
bool is_loop(const vector<string> &cmd, const vector<int> &param1) {
    int ip = 0;
    int acc = 0;
    set<int> cmd_run;
    while(true) {
        if(ip == cmd.size()){
            cout << "ip="<<ip << " acc=" << acc << endl;
            return false;
        }
        if(cmd_run.count(ip)){
            // cout << "LOOP detected" << endl;
            return true;
        }
        cmd_run.insert(ip);

        if(cmd[ip]=="nop") {
            ip += 1;
        } else if (cmd[ip]=="acc") {
            acc += param1[ip];
            ip += 1;
        } else if (cmd[ip]=="jmp") {            
            ip += param1[ip];
        } else {
            cout << "error: unknown code '" << cmd[ip] << "'" << endl;
            exit(0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<string> cmd(N);
    vector<int> param1(N);
    for(int i=0;i<N;i++){
        cin >> cmd[i] >> param1[i];
    }

    for(int i=0;i<N;i++){
        string prev = cmd[i];
        if(cmd[i] == "nop") cmd[i] = "jmp";
        else if(cmd[i] == "jmp") cmd[i] = "nop";

        is_loop(cmd, param1);
        // cout << i << "\t" << is_loop(cmd, param1) << endl;
        
        cmd[i] = prev;
    }
    

    return 0;
}
