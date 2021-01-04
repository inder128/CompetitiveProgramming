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

const int D = 5e5 + 5;
const int mod = 1e9 + 7;

vector <pi> basis(D); 

int sz = 0;

bool insertVector(pi newVector){
    
    while(newVector.F and basis[newVector.F].F){
        if(basis[newVector.F].S == 0){
            newVector.F = newVector.S;
            newVector.S = 0;
        }
        else{
            if(newVector.S == 0){
                newVector.F = basis[newVector.F].S;
            }
            else if(newVector.S == basis[newVector.F].S){
                newVector = {0, 0};
            }
            else{
                newVector = {min(newVector.S, basis[newVector.F].S), max(newVector.S, basis[newVector.F].S)};
            }
        }
    }
    if(newVector.F == 0){
        return false;
    }

    sz++;
    basis[newVector.F] = newVector;

    return true;
}



void solve(){
    int n, m; cin >> n >> m;
    vi ans;
    int r = 1;
    for(int i = 0; i < n; ++i){
    	pi nv = {0, 0};
    	int k; cin >> k;
    	if(k == 1){
    		cin >> nv.F;
    	}
    	else{
    		cin >> nv.F >> nv.S;
    	}
    	if(insertVector(nv)){
    		ans.pb(i);
    		r = (r * 2) % mod;
    	}
    }
    cout << r << " " << SZ(ans) << el;
    for(int i : ans){
    	cout << i + 1 << " ";
    }
    cout << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}