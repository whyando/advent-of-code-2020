#include <bits/stdc++.h>

using namespace std;

// Vector hasher: https://stackoverflow.com/a/27216842
std::size_t vec_hash(std::deque<int> const& vec) {
  std::size_t seed = vec.size();
  for(auto& i : vec) {
    seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  return seed;
}

bool f(deque<int> &deck1, deque<int> &deck2) {
    set<size_t> seen;
    while(true)
    {
        // check end conditions
        // - repeated state
        // - 0 cards
        if(deck1.size() == 0) return false;
        if(deck2.size() == 0) return true;

        auto h = vec_hash(deck1);
        if(seen.count(h) != 0) return true;
        seen.insert(h);

        // draw
        int a = deck1.front(); deck1.pop_front();
        int b = deck2.front(); deck2.pop_front();

        bool a_win_round;
        if(a <= deck1.size() && b <= deck2.size()) {
            // recurse
            deque<int> deck11(deck1.begin(), deck1.begin()+a);
            deque<int> deck22(deck2.begin(), deck2.begin()+b);
            a_win_round = f(deck11, deck22);
        } else {
            // high card wins round
            a_win_round = (a >= b);
        }
        
        if(a_win_round) {
            deck1.push_back(a);
            deck1.push_back(b);
        } else {
            deck2.push_back(b);
            deck2.push_back(a);
        }    
    }
}

int main() {
    vector<int> input1 = {44,47,29,31,10,40,50,27,35,30,38,11,14,9,42,1,26,24,6,13,8,15,21,18,4};
    vector<int> input2 = {17,22,28,34,32,23,3,19,36,12,45,37,46,39,49,43,25,33,2,41,48,7,5,16,20};
    // vector<int> input1 = {9,2,6,3,1};
    // vector<int> input2 = {5,8,4,7,10};
    deque<int> deck1(input1.begin(), input1.end()), deck2(input2.begin(), input2.end());
    int N = deck1.size() + deck2.size();

    f(deck1, deck2);

    int score = 0;
    for(int i=0;i<N;i++)
        score += (N-i)*deck1[i];

    cout << score << endl;

    return 0;
}
