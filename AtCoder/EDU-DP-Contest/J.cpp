#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<" : "<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; typedef vector <bool> vb;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// Expected value :-
// nice question 
// https://atcoder.jp/contests/dp/tasks/dp_j

int n; 
const int mxN = 301;
double DP[mxN][mxN][mxN];

double get(int c0, int c1, int c2){
    if(c0 == n) return 0;
    double &ans = DP[c0][c1][c2];
    if(ans != -1.0) return ans;
    ans = 1;
    vi cnt = {c0, c1, c2, n - (c0 + c1 + c2)};
    for(int c = 1; c <= 3; c++){
        if(cnt[c] == 0) continue;
        cnt[c]--, cnt[c-1]++;
        ans += ((cnt[c]+1)*get(cnt[0], cnt[1], cnt[2]))/n;
        cnt[c]++, cnt[c-1]--;
    }
    ans *= n, ans /= n - c0;
    return ans;
};

void solve(){
    for (int i = 0; i < mxN; ++i)
        for (int j = 0; j < mxN; ++j)
            for (int k = 0; k < mxN; ++k)
                DP[i][j][k] = -1.0;
    cin>>n;
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i){
        int x; cin>>x;
        c0 += (x == 0);
        c1 += (x == 1);
        c2 += (x == 2);
    }
    cout<<setprecision(14)<<fixed;
    cout<<get(c0, c1, c2)<<el;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        solve();
    }
    return 0; 
}