// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


#define ll long long
// User function Template for C++

const int M = 1e5;
int ccurr;
int p = 7; 
vector <int> pp(M);

const int mod = 1e9 + 9;

int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}

int sub(int x, int y){
    return add(x, -y);
}

int mul(int x, int y){
    return (x * 1ll * y) % mod;
}

int binPow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x){
    return binPow(x, mod - 2);
}

int divide(int x, int y){
    return mul(x, inv(y));
}


class Solution {
  public:
    ll calculate(vector<int> A, int N, int K) {
        // code here
        if(pp[0] == 0){
            pp[0] = 1;
            for(int i = 1; i < M; ++i){
                pp[i] = mul(pp[i - 1], p);
            }
            for(int i = 0; i < M; ++i){
                ccurr = add(ccurr, pp[i]);
            }
        }
        

        map <int, int> hash;
        int curr = ccurr;
        hash[curr] = 1;

        ll ans = 0;

        vector <int> freq(M);
        for(int a : A){
            a--;
            curr = sub(curr, mul(freq[a] + 1, pp[a]));
            freq[a] = (freq[a] - 1 + K) % K;
            curr = add(curr, mul(freq[a] + 1, pp[a]));
            ans += hash[curr];
            hash[curr]++;
        }

        return ans;
    }
};


// { Driver Code Starts.

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        auto ans = ob.calculate(A, N, K);
        cout << ans << endl;
    }
    return 0;
}
  // } Driver Code Ends