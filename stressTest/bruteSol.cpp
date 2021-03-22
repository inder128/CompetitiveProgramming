#include <bits/stdc++.h>
using namespace std;

#define endl  '\n'
#define w(x)  int x; cin>>x; while(x--)
#define int long long

const int N = 5e5 + 10;
const int K = 55;
int dp[N][K];
const int mod = 1e9 + 7;


void calc()
{
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (i <= 1) {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = dp[i - 1][j] + dp[i - 2][j];
            if (j && i > 2) dp[i][j] += dp[i - 3][j - 1];
            dp[i][j] %= mod;
        }
    }
}


void solve()
{
    int n, k;
    cin >> n >> k;

    int ans = dp[n][k];
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    calc();
    w(T) {
        solve();
    }
    return 0;
}