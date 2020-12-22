#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> input1 = {44,47,29,31,10,40,50,27,35,30,38,11,14,9,42,1,26,24,6,13,8,15,21,18,4};
    vector<int> input2 = {17,22,28,34,32,23,3,19,36,12,45,37,46,39,49,43,25,33,2,41,48,7,5,16,20};
    deque<int> deck1(input1.begin(), input1.end()), deck2(input2.begin(), input2.end());
    int N = deck1.size() + deck2.size();

    int t=0;
    while(deck1.size() != 0 && deck1.size() != N){
        int a = deck1.front(); deck1.pop_front();
        int b = deck2.front(); deck2.pop_front();
        if(a > b) {
            deck1.push_back(a);
            deck1.push_back(b);
        } else {
            deck2.push_back(b);
            deck2.push_back(a);
        }
        t++;
    }
    cout << t << endl;
    int score = 0;
    for(int i=0;i<N;i++){
        score += (N-i)*deck1[i];
    }
    cout << score << endl;

    return 0;
}
