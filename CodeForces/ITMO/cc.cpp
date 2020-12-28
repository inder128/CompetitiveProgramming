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
};


void countSort(vi &val, vi ord){
	int n = val.size();
	int sz = *max_element(rng(ord)) + 1;
	vi cnt(sz);
	for(int i = 0; i < n; ++i){
		cnt[ord[i]]++;
	}
	vi preCnt(sz);
	for(int i = 1; i < sz; ++i){
		preCnt[i] = preCnt[i - 1] + cnt[i - 1];
	}

	vi tmpVal(n);
	for(int i = 0; i < n; ++i){
		tmpVal[preCnt[ord[i]]] = val[i];
		preCnt[ord[i]]++;
	}

	val = tmpVal;
}

vi get(string &str){
	// strictly less than least character;
	str.pb('$');
	int n = str.size(); 
	vi pos(n);
	for(int i = 0; i < n; ++i){
		pos[i] = str[i] - '$';
	}
	int k = 0;
	while((1 << k) < n){
		// k -> k + 1;
		vi ordInds(n), sortVal(n);
		for(int i = 0; i < n; ++i){
			ordInds[i] = i;
		 	sortVal[i] = pos[(i + (1 << k)) % n];
		}
		countSort(ordInds, sortVal);
		db(ordInds, sortVal);
		for(int i = 0; i < n; ++i){
			sortVal[i] = pos[ordInds[i]];
		}
		countSort(ordInds, sortVal);
		db(ordInds, sortVal);
		
		vi newPos(n);
		newPos[ordInds[0]] = 0;
		for(int i = 1; i < n; ++i){
			int lastSt = ordInds[i - 1];
			int currSt = ordInds[i];
			if(pos[lastSt] == pos[currSt] and pos[lastSt + (1 << k)] == pos[currSt + (1 << k)]){
				newPos[ordInds[i]] = newPos[ordInds[i - 1]];
			}
			else{
				newPos[ordInds[i]] = newPos[ordInds[i - 1]] + 1;
			}
		}
		pos = newPos;
		if(pos[ordInds.back()] == n - 1) break;
		k++;
	}
	return pos;
}




void solve(){
	string b; cin>>b;
	vi pos = get(b);
	int n = b.length();
	vi sortedInds(n);
	for(int i = 0; i < n; ++i){
   		sortedInds[pos[i]] = i;
   	}

   	// lcp array;
   	vi lcp(n);
   	int k = 0;
   	for(int i = 0; i < n - 1; ++i){
   		int posi = pos[i];
   		assert(posi > 0);
   		// suff[i .. n - 1] is at position posi in sorted array;
   		int previ = sortedInds[posi - 1];
   		
   		while(b[i + k] == b[previ + k]) k++;

   		lcp[posi - 1] = k;

   		k = max(k - 1, 0ll);
   	}

   	db(lcp);
   	db(pos);




   	sparseTable spt(lcp);

   	cin>>n;
   	vector <pi> lr(n);
   	for(int i = 0; i < n; ++i){
   		cin>>lr[i].F>>lr[i].S;
   		lr[i].F--, lr[i].S--;
   	}

   	sort(rng(lr), [&](const pi &r1, const pi &r2){
   		int pos1 = pos[r1.F], pos2 = pos[r2.F];
   		int len1 = r1.S - r1.F + 1, len2 = r2.S - r2.F + 1;

   		int cp; // common prefix;
   		if(pos1 == pos2){
   			cp = min(len1, len2);
   		}
   		else{
   			cp = lcp[spt.get(min(pos1, pos2), max(pos1, pos2) - 1)];
   		}

   		if(cp >= max(len1, len2)){
   			if(len1 == len2) return r1 < r2;
   			return len1 < len2;
   		}

   		if(cp >= min(len1, len2)){
   			return len1 < len2;
   		}

   		return pos1 < pos2;
   	});

   	for(int i = 0; i < n; ++i){
   		cout<<lr[i].F + 1<<" "<<lr[i].S + 1<<el;
   	}
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