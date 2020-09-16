#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define el '\n'
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ "; for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") "; return os<<"}";}
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef long long ll; typedef pair<int,int> pi; 
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

// question link :-
// https://leetcode.com/contest/weekly-contest-206/problems/check-if-string-is-transformable-with-substring-sort-operations/

// nodes in the last level i.e (power of 2 >= 1e5);
const int N = 1<<20; 
vector <char> ST(2*N, '$');
int n = N; // size of array;

char setUtil(int si, int ss, int se, int i, char new_val){ 
	if(si >= 2*N) db(si, ss, se);
	if (i < ss || i > se)  return ST[si];

	if(ss == se) return ST[si] = new_val; 

	int mid = (ss + se)/2; 
	char minL = setUtil(2*si+1, ss, mid, i, new_val);
	char minR = setUtil(2*si+2, mid+1, se, i, new_val);
	if(minL == '$') return ST[si] = minR;
	if(minR == '$') return ST[si] = minL;
	return ST[si] = min(minL, minR);
}

void setValue(int i, char new_val) { 
	setUtil(0, 0, n-1, i, new_val);
}

char getMinSuffixUtil(int si, int ss, int se, int qs, int qe) { 
	if(si >= 2*N) db(si, ss, se);
	if (se < qs || ss > qe) return '$'; 
	
	if (qs <= ss && qe >= se) return ST[si]; 

	int mid = (ss + se)/2;
	char minL = getMinSuffixUtil(2*si+1, ss, mid, qs, qe);
	char minR = getMinSuffixUtil(2*si+2, mid+1, se, qs, qe);

	if(minL == '$') return minR;
	if(minR == '$') return minL;
	return min(minL, minR);
}

char getMinSuffix(int qs){
	return getMinSuffixUtil(0, 0, n-1, qs, N-1); 
}

void constructUtil(int si, int ss, int se){
	ST[si] = '$';
	if(ss == se) return;

	int mid = (ss + se)/2;
	constructUtil(2*si+1, ss, mid);
	constructUtil(2*si+2, mid+1, se);
}

void construct(){
	return constructUtil(0, 0, n-1); 
}

bool isTransformable() {
	construct();
	string s, t; cin>>s>>t;

	db(s.length(), t.length());

	queue <int> pos[10];
	for (int i = 0; i < t.length(); ++i){
		pos[t[i]-'0'].push(i);
	}
	
	for (int i = 0; i < s.length(); ++i){
		if(pos[s[i]-'0'].empty()) return false;
		int p = pos[s[i]-'0'].front();
		pos[s[i]-'0'].pop();
		setValue(p, s[i]);
		char mn = getMinSuffix(p+1);
		if(mn != '$' and mn < s[i]) return false;
	}

	return true;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T=1, tc = 1;
    // cin>>T; 
    while(T--){
        cout<<isTransformable()<<el;
    }
    return 0; 
}