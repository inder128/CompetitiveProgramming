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
	str.pb('a' - 1);
	int n = str.size();
	vi pos(n);
	for(int i = 0; i < n; ++i){
		pos[i] = str[i] - 'a' + 1;
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
		for(int i = 0; i < n; ++i){
			sortVal[i] = pos[ordInds[i]];
		}
		countSort(ordInds, sortVal);
		
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

	vi sortedInds(n);
	for(int i = 0; i < n; ++i){
   		sortedInds[pos[i]] = i;
   	}
	return sortedInds;
}

void solve(){
    string str; cin>>str;
   	vi sortedInds = get(str);

   	int n = str.size();

   	int q; cin>>q;
   	while(q--){
   		string pat; cin>>pat;
   		int len = pat.length();

   		int low, high;

   		// invarients;
   		int l = -1; // str[sortedInds[l] ... + k] <= pat
   		int r = n; // str[sortedInds[l] ... + k] > pat

   		while(l + 1 < r){
   			int m = (l + r) >> 1;

   			int i = 0;
   			while(i < len and str[sortedInds[m] + i] == pat[i]) i++;

   			if(i == len or str[sortedInds[m] + i] < pat[i]){
   				l = m;
   			}
   			else{
   				r = m;
   			}
   		}

   		high = l;


   		// invarients;
   		l = -1; // str[sortedInds[l] ... + k] < pat
   		r = n; // str[sortedInds[l] ... + k] >= pat

   		while(l + 1 < r){
   			int m = (l + r) >> 1;

   			int i = 0;
   			while(i < len and str[sortedInds[m] + i] == pat[i]) i++;

   			if(i == len or str[sortedInds[m] + i] > pat[i]){
   				r = m;
   			}
   			else{
   				l = m;
   			}
   		}


   		low = r;

   		cout<<(high - low + 1)<<el;
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