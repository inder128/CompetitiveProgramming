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

void solve(){
	int n, m;  cin >> n >> m;
    set <pi> lr;
    for (int i = 0; i < n; ++i){
    	int l, r; cin >> l >> r;
    	lr.insert({l, r});
    }

    auto insert = [&](int l, int r) {
        if(r >= l){
            lr.insert({l, r});
        }
    };

    for (int i = 0; i < m; ++i){
    	int x; cin >> x;
        int y;

    	auto itr = lr.lower_bound({x, 1e18 + 1});
        if(lr.end() == itr) {
            auto [l, r] = *prev(itr);
            mini(x, r);
            y = x;
            lr.erase({l, r});
            insert(l, x - 1);
            insert(x + 1, r);
        }
        else{
            auto [l, r] = *itr;
            if((*lr.begin()) == pi(l, r)) {
                lr.erase({l, r});
                y = l;
                insert(l + 1, r);
            }
            else{
                auto itrl = prev(itr);
                auto [l1, r1] = *itrl;
                if(l1 <= x and x <= r1){
                    y = x;
                    lr.erase({l1, r1});
                    insert(l1, x - 1);
                    insert(x + 1, r1);
                }
                else{
                    if(x - r1 <= l - x){
                        y = r1;
                        lr.erase({l1, r1});
                        insert(l1, r1 - 1);
                    }
                    else{
                        y = l;
                        lr.erase({l, r});
                        insert(l + 1, r);
                    }
                }
            }
        }
            

        cout << y << " ";
    }
    cout << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin >> T;
    while(T--){
        cout << "Case #" << tc << ": ";
        tc++;
        solve();
    }
    return 0;
}