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
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/


// https://www.codechef.com/problems/GUESSPRM
// check editorial;


int inv(int a, int b){
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}


// Chinease Reminder Theorum;
// pr -> vecrtor of {{p1, r1}, {p2, r2}, ---, {pn, rn}};
// return x such that (x % pi = pi) for all 0 <= i < n;
int CRT(vector <pi> pr){
    int n = SZ(pr);

    int m = 1; // p1 * p2 * --- * pn;
    for(pi p : pr){
        m *= p.F;
    }

    // ((x1) + (x2 * p1) + ----- + (xn * p1 * -- * p(n - 1))) % m;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int curr = 1; 
        for(int j = 0; j < i; ++j){
            curr *= pr[j].F;
            curr *= inv(pr[j].F, pr[i].F);
            curr %= m;
        }
        ans = (ans + curr * (pr[i].S - ans + m)) % m;
    }

    return ans;
}


int q(int x){
    cout<<1<<" "<<x<<endl;
    int y; cin>>y;
    return y;
}


void solve(){
    int r = q(31623);
    int mul = 31623 * 31623 - r;

    int muld = mul;

    vector <pi> pr;
    for(int i = 2; i * i <= mul; ++i){
        if(mul % i) continue;
        if(i > r){
            pr.pb({i, -1});
        }
        while(mul % i == 0){
            mul /= i;
        }
    }
    if(mul > max(1ll, r)){
        pr.pb({mul, -1});
    }

    // see last four submissions;
    if(SZ(pr) == 1){
        cout<<2<<" "<<pr[0].F<<endl;
        string str; cin>>str;
        return;
    }


    set <int> taken;
    for(int i = 0; i < SZ(pr); ++i){
        for(int j = 0; j <= i; ++j){
            if(taken.count(j * j % pr[i].F)) continue;
            pr[i].S = j;
            taken.insert(j * j % pr[i].F);
            break;
        }
    }

    // x will be zero when SZ(pr) == 1 and x should be positive;
    int x = CRT(pr);

    int ans = q(x);
    assert(ans >= 0);

    for(pi p : pr){
        if(x * x % p.F == ans){
            cout<<2<<" "<<p.F<<endl;
        }
    }

    string str; cin>>str;
    assert(str == "Yes");
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