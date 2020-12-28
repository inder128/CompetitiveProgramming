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

class sparseTable{
public:
	vvi spt;
	vi arr, numLog;
	int k, n;

	sparseTable(vi &arr_){
		build(arr);
	}

	sparseTable(){
	}

	void build(vi &arr_){
		arr = arr_;
		n = arr.size();

		numLog.resize(n + 1);
		numLog[1] = 0;
		for(int i = 2; i <= n; ++i){
			numLog[i] = numLog[i / 2] + 1;
		}

		k = numLog[n];

		spt = vvi(k + 1, vi(n));
		iota(rng(spt[0]), 0);
		for(int b = 1; b <= k; ++b){
			for(int i = 0, j = i + (1 << b) - 1; j < n; ++i, ++j){
				int s1 = spt[b - 1][i], s2 = spt[b - 1][i + (1 << b) / 2];
				spt[b][i] = compare(s1, s2);
			}
		}
	}

	int compare(int s1, int s2){
		return (arr[s1] < arr[s2] ? s1 : s2);
	}

	int get(int l, int r){
		int lg = numLog[r - l + 1];
		return compare(spt[lg][l], spt[lg][r - (1 << lg) + 1]);
	}

	int getVal(int l, int r){
		return arr[get(l, r)];
	}
};	


class suffixArray{
public:
	string str;
	int n;
	// posSuffs[i] -> position of suffix str[i..n - 1] in sortedSuffs;
	// sortedSuffs[i] -> suffix str[sortedSuffs[i]..n - 1] is lexicographically i'th suffix;
	// lcp[i] -> length of longest common prefix of str[sortedSuffs[i]..n - 1] and str[sortedSuffs[i + 1]..n - 1];
	vi posSuffs, sortedSuffs, lcp;
	sparseTable spt;

	suffixArray(string str_){
		str = str_ + " ";
		n = str.length();
		posSuffs.resize(n);
		sortedSuffs.resize(n);
		lcp.resize(n - 1);

		buildPosSuffs();
		buildSortedSuffs();
		buildLCP();
		spt.build(lcp);
	}

	void buildPosSuffs(){
		for(int i = 0; i < n; ++i){
			posSuffs[i] = str[i] - 32;
		}
		int k = 0;
		while((1 << k) < n){
			// k -> k + 1;
			vi ordInds(n), sortVal(n);
			for(int i = 0; i < n; ++i){
				ordInds[i] = i;
			 	sortVal[i] = posSuffs[(i + (1 << k)) % n];
			}
			countSort(ordInds, sortVal);
			for(int i = 0; i < n; ++i){
				sortVal[i] = posSuffs[ordInds[i]];
			}
			countSort(ordInds, sortVal);
			
			vi newPosSuffs(n);
			newPosSuffs[ordInds[0]] = 0;
			for(int i = 1; i < n; ++i){
				int lastSt = ordInds[i - 1], currSt = ordInds[i];
				if(posSuffs[lastSt] == posSuffs[currSt] and 
				   posSuffs[lastSt + (1 << k)] == posSuffs[currSt + (1 << k)]){
					newPosSuffs[currSt] = newPosSuffs[lastSt];
				}
				else{
					newPosSuffs[currSt] = newPosSuffs[lastSt] + 1;
				}
			}
			posSuffs = newPosSuffs;
			if(posSuffs[ordInds.back()] == n - 1) break;
			k++;
		}
	}

	void buildSortedSuffs(){
		for(int i = 0; i < n; ++i){
	   		sortedSuffs[posSuffs[i]] = i;
	   	}
	}

	void buildLCP(){
		int k = 0;
	   	for(int i = 0; i < n - 1; ++i){
	   		int posi = posSuffs[i];
	   		assert(posi > 0);

	   		// str[i .. n - 1] is at position posi in sortedSuffs array;
	   		int previ = sortedSuffs[posi - 1];
	   		
	   		while(str[i + k] == str[previ + k]) k++;

	   		lcp[posi - 1] = k;

	   		k = max(k - 1, 0ll);
	   	}
	}

	int commonPrefix(int i, int j){
		if(i == j) return n - 1 - i;
		if(posSuffs[i] > posSuffs[j]) swap(i, j);
		return spt.getVal(posSuffs[i], posSuffs[j] - 1);
	}

	int commonPrefix(int l1, int r1, int l2, int r2){
		int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
		return min({len1, len2, commonPrefix(l1, l2)});
	}


	void countSort(vi &val, vi ord){
		int sz = val.size();
		int mx = *max_element(rng(ord)) + 1;

		vi cnt(mx);
		for(int i = 0; i < sz; ++i){
			cnt[ord[i]]++;
		}
		vi preCnt(mx);
		for(int i = 1; i < mx; ++i){
			preCnt[i] = preCnt[i - 1] + cnt[i - 1];
		}

		vi newVal(sz);
		for(int i = 0; i < sz; ++i){
			newVal[preCnt[ord[i]]] = val[i];
			preCnt[ord[i]]++;
		}

		val = newVal;
	}
};




void solve(){
	string str;
	int n, m; cin>>n>>m;
	for(int i = 0; i < n; ++i){
		int x; cin>>x;
		str.pb(x - 1 + '0');
	}
	// db(str);

	
	suffixArray suffArr(str);


	vi h = suffArr.lcp;
	int ans = n, st = 0, len = n;

	// db(h, suffArr.sortedSuffs);

	vi nextSmaller(n);
	stack <int> stk;
	for(int i = n - 1; i >= 0; --i){
		while(stk.size() and h[stk.top()] >= h[i]){
			stk.pop();
		}
		nextSmaller[i] = (stk.size() ? stk.top() : n);
		stk.push(i);
	}
	while(stk.size()) stk.pop();

	for(int i = 0; i < n; ++i){
		while(stk.size() and h[stk.top()] >= h[i]){
			stk.pop();
		}
		int psm = (stk.size() ? stk.top() : n);
		int currScore = (nextSmaller[i] - psm) * h[i];
		if(currScore > ans){
			ans = currScore;
			st = suffArr.sortedSuffs[i];
			len = h[i];
		}
		stk.push(i);
	}

	cout<<ans<<el<<len<<el;
	for(int i = st; i < len + st; ++i){
		cout<<(int)(str[i] - '0' + 1)<<" ";
	}
	cout<<el;
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