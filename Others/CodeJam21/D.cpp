#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
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

int q(int i, int j, int k){
    cout << i << " " << j << " " << k << endl;
    int ans; cin >> ans;
    assert(ans != -1);
    return ans;
}


void solve(int n){


    vi a{1, 2};
    for(int i = 3; i <= n; ++i){
        int x = (i - 3) / 3;

        int l = 0, r = i - 2;
        while(l <= r){
            if(l == r){
                if(l == 0){
                    r++;
                }
                else{
                    l--;
                }
            }

            int x = (r - l + 1 - 2) / 3;
            int i1 = l + x, i2 = l + x + 1 + x;

            int j = q(a[i1], a[i2], i);


            if(j == a[i1]){
                r = i1 - 1;
            }   
            else if(j == i){
                l = i1 + 1, r = i2 - 1;
            }   
            else{
                l = i2 + 1;
            }      
        }

        a.insert(a.begin() + l, i);
    }

    for(int i : a){
        cout << i << " ";
    }
    cout << endl;

    int v; cin >> v;
    assert(v != -1);
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, n, q;
    cin >> T >> n >> q;
    while(T--){
        solve(n);
    }
    return 0;
}