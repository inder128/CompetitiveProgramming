
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
#include <assert.h>
#include <array>

using namespace std;

template<typename M, typename N>
istream& operator>>(istream&is, pair<M,N> & p){is >> p.first >> p.second; return is;}
template<typename M>
istream& operator>>(istream&is, vector<M> & v){for(auto &it:v) is >> it; return is; }
template<typename M>
istream& operator>>(istream&is, vector<vector<M>> & v){for(auto &it:v) is >> it; return is; }
template<typename M, typename N>
ostream& operator<<(ostream&os, const pair<M,N> &p){os << p.first << ' ' << p.second << '\n';return os;}
template<typename M>
ostream& operator<<(ostream&os, const vector<M> &v){for(auto it: v)os << it << ' ';cout << '\n';return os;}
template<typename M>
ostream& operator<<(ostream&os, const vector<vector<M>> &v){for(auto it: v)os << it;return os;}

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mn(x) *min_element((x).begin(),(x).end())
#define mx(x) *max_element((x).begin(),(x).end())
#define acc(x) accumulate((x).begin(),(x).end(),0ll)
#define unique(x) sort(all(x)); x.erase(unique(all(x)),x.end());
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef  unsigned long long  ull;
typedef long double ld;
typedef complex<long double> cd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

const ld pi=acos(-1);
const ll inf=(ll)1e9+10;
const int mod=1000000007;
//const int mod=998244353;

int n, m, k;
const int N=2e3+10;

int dp[N][(1<<9)+10];
int dont[N][N];


int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, e, k;
    cin >> n >> e >> k;
    for(int i=0, u, v; i<k; i++){
        cin >> u >> v;
        dont[u][v]=1;
    }
    e=min(e,n-1);
    const int c=1<<(2*e+1);
    int con=0;
    for(int i=0; i<=e; i++){
        con|=(1<<i);
    }
    dp[0][con]=1;
    for(int i=1; i<=n; i++){
        for(int k=0; k<c; k++){
            bool cond=true;
            for(int p=0; p<2*e+1; p++){
                int pos=i-1-(e-p);
                if(pos<0 && pos>n)continue;
                if(k>>p&1)continue;
                else if(cond){
                    if(pos<i-e){
                        break;
                    }
                    else if(pos==i-e){
                        if(dont[i][pos])break;
                        (dp[i][(k|(1<<p))>>1]+=dp[i-1][k])%=mod;
                        break;
                    }
                    else{
                        if(!dont[i][pos])
                            (dp[i][(k|(1<<p))>>1]+=dp[i-1][k])%=mod;
                        if(!dont[i][i+e])
                            (dp[i][(k>>1)|(1<<(2*e))]+=dp[i-1][k])%=mod;
                    }
                    cond=false;
                }
                else{
                    if(!dont[i][pos])
                        (dp[i][(k|(1<<p))>>1]+=dp[i-1][k])%=mod;
                }
            }
        }
    }
    con=0;
    for(int i=e; i>=max(0,e-n+1); i--){
        con|=(1<<i);
    }

    cout << dp[n][con] << el;
    return 0;
}