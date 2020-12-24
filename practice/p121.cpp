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
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins--------------------------------*/


// https://codeforces.com/contest/467/problem/E


#define lsi (2*si + 1)
#define rsi (2*si + 2)
#define mid ((sl + sr) >> 1)
class segmentTree{
public :
	int size, n, NEUTRAL = -1e9;
	vi ST;
	segmentTree(int _n){
		n = _n;
		size = 1;
		while(size < n) size <<= 1;
		ST.assign(2 * size - 1, NEUTRAL);
	}

	void printUtil(int si, int sl, int sr){
		cout<<si<<" : "<<sl<<" - "<<sr<<" : "<<ST[si]<<el;

		if(sl == sr) return;

		printUtil(lsi, sl, mid);
		printUtil(rsi, mid + 1, sr);
	}
	void print(){
		return printUtil(0, 0, n - 1);
	}


	void updateUtil(int si, int sl, int sr, int i, int val){
		if(sl == sr){
			ST[si] = val;
			return;
		}

		if(i <= mid)
			updateUtil(lsi, sl, mid, i, val);
		else
			updateUtil(rsi, mid + 1, sr, i, val);

		ST[si] = max(ST[lsi], ST[rsi]);
	}
	void update(int i, int val){
		return updateUtil(0, 0, n - 1, i, val);
	}


	int getUtil(int si, int sl, int sr, int ql, int qr, int val){
		if(ST[si] <= val) return -1;
		if(sr < ql or qr < sl) return -1;

		if(sl == sr) return sl;


		int ans = getUtil(rsi, mid + 1, sr, ql, qr, val);
		if(ans == -1){
			ans = getUtil(lsi, sl, mid, ql, qr, val);
		}
		return ans;
	}
	int getRightMostGreater(int i, int val){
		return getUtil(0, 0, n - 1, 0, i, val);
	}
};


void solve(){
    int n; cin>>n;
    vi arr(n); cin>>arr;
    vi DP(n), last(n, -1);
    map <int, vi> occ;

    occ[arr[0]].pb(0);

    segmentTree segTree(n);

    for(int i = 1; i < n; ++i){
    	DP[i] = DP[i - 1];
    	last[i] = i - 1;
    	if( SZ(occ[arr[i]]) ){
    		segTree.update(occ[arr[i]].back(), i);
    		if(occ[arr[i]].back()){
    			int j = segTree.getRightMostGreater(occ[arr[i]].back() - 1, occ[arr[i]].back());
    			if(j != -1){
					int newDP = (j ? DP[j - 1] : 0) + 1;
					if(newDP > DP[i]){
						last[i] = j - 1;
						DP[i] = newDP;
					}
    			}
    		}
    	}

    	if( SZ(occ[arr[i]]) >= 3){
    		int j = occ[arr[i]][SZ(occ[arr[i]]) - 3];
    		int newDP = (j ? DP[j - 1] : 0) + 1;
			if(newDP > DP[i]){
				last[i] = j - 1;
				DP[i] = newDP;
			}
    	}

    	occ[arr[i]].pb(i);
    }

    vi ans;

    int curri = n - 1;
    while(curri != -1){
    	if(last[curri] != curri - 1){
    		ans.pb(arr[curri]);
    		ans.pb(arr[last[curri] + 1]);
    		ans.pb(arr[curri]);
    		ans.pb(arr[last[curri] + 1]);
    	}
    	curri = last[curri];
    }

    reverse(rng(ans));

    cout<<DP[n - 1] * 4<<el;

    for(int i : ans) cout<<i<<" "; cout<<el;
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