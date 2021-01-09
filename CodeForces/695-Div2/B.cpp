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

int n;
vi arr;


bool hill(int i){
	if(i <= 0 or i >= n - 1){
		return false;
	}
	return arr[i] > arr[i - 1] and arr[i] > arr[i + 1];
};

bool val(int i){
	if(i <= 0 or i >= n - 1){
		return false;
	}
	return arr[i] < arr[i - 1] and arr[i] < arr[i + 1];
};

int  get(int i, int v){
	int x = arr[i];

	int ld = 0;
	ld += hill(i - 1);
	ld += hill(i);
	ld += hill(i + 1);
	ld += val(i - 1);
	ld += val(i);
	ld += val(i + 1);

	arr[i] = v;


	ld -= hill(i - 1);
	ld -= hill(i);
	ld -= hill(i + 1);
	ld -= val(i - 1);
	ld -= val(i);
	ld -= val(i + 1);

	arr[i] = x;

	return ld;
};


void solve(){
    cin >> n;
    arr.resize(n);
    cin >> arr;

    int c = 0;
    for(int i = 0; i < n; ++i){
    	c += hill(i);
    	c += val(i);
    }


    int d = 0;
    for(int i = 0; i < n; ++i){
    	if(i > 0){
    		maxi(d, get(i, arr[i - 1]));
    		maxi(d, get(i, arr[i - 1] + 10));
    		maxi(d, get(i, arr[i - 1] - 10));
    	}
    	if(i < n - 1){
    		maxi(d, get(i, arr[i + 1]));
    		maxi(d, get(i, arr[i + 1] + 10));
    		maxi(d, get(i, arr[i + 1] - 10));
    	}
    }


    cout << c - d << el;
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