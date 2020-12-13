#include <bits/stdc++.h>

using namespace std;

//safe_mod_mult
int64_t smm(int64_t a,int64_t b, int64_t mod) {
	while (a < 0)
		a += mod;
	while (b < 0)
		b += mod;
 
	a %= mod;	
	int64_t sum = 0;
	while (b != 0) {
		if (b & 1) {
			sum = (sum+a)%mod;
		}
		b /= 2;
		a = (a*2)%mod;
	}
	return sum;
}


// https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
// extended algorithm algorithm
int64_t gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    x = 1, y = 0;
    int64_t x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int64_t q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

// assuming N,M coprime
// there's precisely 1 integer 0 <= v < N*M
// such that v == x MOD N AND v == y MOD M
int64_t crt(const int64_t x, const int64_t N, const int64_t y, const int64_t M) {
    cout << "crt(" << x << "," << N << "," << y << "," << M << ")" << endl;
    int64_t r,s;
    assert(gcd(N, M, r, s) == 1);
    assert(r*N + s*M == 1);
    cout << "r=" << r << " s=" << s << endl;

    //int64_t v = (M*s*x + r*y*N) % (N*M);
    int64_t v = (smm(smm(M,s, N*M), x, N*M) + smm(smm(r,y, N*M), N, N*M))%(N*M);
    if(v<0) v+= N*M;

    cout << v << " " << v%N << " " << v%M << endl;
    assert(v % N == x);
    assert(v % M == y);
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int S, N; cin >> S >> N;
    vector<int64_t> A(N);
    for(int i=0;i<N;i++) {
        string s; cin >> s;
        if(s == "x")
            A[i] = 0;
        else
            A[i] = stoi(s);
    }
    
    // part1
    /*
    int best = -1;
    int bestVal = INT_MAX;
    for(int i=0;i<N;i++) {
        if(A[i]==0) continue;
        // round up
        int T = (S+A[i]-1)/A[i]*A[i];
        if (T < bestVal){
            bestVal = T;
            best = A[i];
        }
        // cout << A[i] << " " << T << endl;
    }

    cout << best << " " << bestVal << endl;
    cout << (bestVal-S)*best << endl;
    */

    // part2
    int64_t v = 0;
    int64_t mod = 1;
    for(int i=0;i<N;i++) {
        if(A[i]==0) continue;
        // cout << "X mod " << A[i] << " = " << i%A[i] << endl;
        cout << "X + " << i << " mod " << A[i] << " = " << 0 << endl;

        v = crt(v, mod, (A[i]-i%A[i])%A[i], A[i]);
        mod *= A[i];
        cout << v << "\t" << mod << endl << endl;
    }
    
    

    return 0;
}
