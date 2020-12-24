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

// https://codeforces.com/contest/1415/problem/E
// nice editorila;

void solve1(){
	int n, k; cin>>n>>k;
    vi arr(n); cin>>arr;
    sort(rng(arr));

    if(k == 0){
    	int ans = 0;
    	for(int i = 0; i < n; ++i){
    		ans += arr[i] * i;
    	}
    	cout<<ans<<el;
    	return;
    }

    int posCnt = 0;
    vi rngIncSum = arr, rngSum = arr, batchIncSum = arr;
    for(int i = 0; i < n; ++i){
    	if(arr[i] >= 0){
    		posCnt++;
    	}
    	rngIncSum[i] *= i;
    	batchIncSum[i] *= i / (k + 1);
    	if(i){
    		rngIncSum[i] += rngIncSum[i - 1];
	    	rngSum[i] += rngSum[i - 1];
	    	batchIncSum[i] += batchIncSum[i - 1];
    	}	
    }

    db(rngSum);
    db(rngIncSum);
    db(batchIncSum);

    int ans = -1e18;
    for(int h = posCnt; h <= n; ++h){
    	int rem = n - h;
    	int ff = (rem + k - 1) / k;
    	int tot = rem + ff;

    	if(h < ff) continue;

    	int ta = (tot ? batchIncSum[tot - 1] : 0);

    	int up = h - ff;


    	int lastInc = rngIncSum[n - 1] - (up < n ? rngIncSum[n - 1 - up] : 0);
    	int lastSum = rngSum[n - 1] - (up < n ? rngSum[n - 1 - up] : 0);

    	int simpInc = lastInc - lastSum * (n - up);

    	ta += simpInc + lastSum * ff;

    	maxi(ans, ta);
    }

    db(ans);

    cout<<ans<<el;
}

void solve(){
    int n, k; cin>>n>>k;
    vi arr(n); cin>>arr;
    sort(rng(arr));

    if(k == 0){
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans += arr[i] * i;
        }
        cout<<ans<<el;
        return;
    }

    k++;

    int si = 0, s = 0;
    for(int i = 0; i < n; ++i){
        si += arr[i] * i;
        s += arr[i];
    }

    int bsi = 0, l = 0, ki = 0, h = 0, ans = si + bsi;

    while(l < n and s - arr[l] < 0){
        bsi += arr[l] * h;
        s -= arr[l];

        if(ki == k - 1){
            si -= arr[l] * h;
            h++;
        }
        else{
            si -= arr[l] * h + s;
        }

        l++;
        ki = (ki + 1) % k;
    }

    cout<<si + bsi<<el;
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