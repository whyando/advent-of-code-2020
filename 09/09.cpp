#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    int target;
    for(int i=25;i<N;i++) {
        // is A[i] = A[i-a]+A[i-b] for 1 <= a < b <= 25
        bool valid=false;
        for(int a=1;a<=25;a++) {
            for(int b=a+1;b<=25;b++) {
                if(A[i] == A[i-a] + A[i-b]){
                    valid = true;
                    break;
                }
            }
            if(valid) break;
        }

        if(!valid) {
            cout << A[i] << endl;
            target = A[i];
        }
    }

    // part2
    int sum = 0;
    int i = 0;
    int j = 0; // next
    while(true) {
        cout << i << "\t" << j << "\t" << sum << endl;
        if(sum == target) {
            cout << "!!\t" << A[i] << "\t" << A[j-1] << "\t" << sum << endl;
            int64_t min=INT64_MAX,max=0;
            for(int k=i;k<j;k++){
                min = std::min(min, A[k]);
                max = std::max(max, A[k]);
            }
            cout << min << " " << max << " " << min+max << endl;

            break;
        } else if(sum < target) {
            sum += A[j];
            j++;
        } else if (target < sum) {
            sum -= A[i];
            i++;
        }
    }

    return 0;
}
