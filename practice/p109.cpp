#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define int long long
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// https://codeforces.com/contest/1455/problem/E
// nice explanation by neal_wu;

void solve(){
    array <int, 4> tX, tY, X, Y;
    for(int i = 0; i < 4; ++i){
        cin>>tX[i]>>tY[i];
    }

    array <int, 4> perm{0, 1, 2, 3};

    auto cost = [&](int k){
        array <int, 4> nX = X, nY = Y;

        // similar trick in 3rd question of google kickstart H 20;
        nX[1] -= k;
        nX[3] -= k;
        nY[2] += k;
        nY[3] += k;
        sort(rng(nX));
        sort(rng(nY));

        int cst = 0;
        for(int i = 0; i < 4; ++i){
            cst += abs(nX[i] - nX[1]);
            cst += abs(nY[i] - nY[1]);
        }

        return cst;
    };

    int ans = LLONG_MAX;

    do{
        
        for(int i = 0; i < 4; ++i){
            X[i] = tX[perm[i]];
            Y[i] = tY[perm[i]];
        }

        int l = -1, r = 1e9 + 8;

        // invarients;
        // cost(r + 1) > cost(r);
        // cost(l) <= cost(l + 1);
        // rightmost most r;

        // ternary search;
        while(l + 1 < r){
            int m = (l + r) >> 1;
            if(cost(m + 1) > cost(m)){
                r = m;
            }
            else{
                l = m;
            }
        }

        mini(ans, cost(r));

    }while(next_permutation(rng(perm)));


    cout<<ans<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}