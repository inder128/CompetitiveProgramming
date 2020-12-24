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


struct pt {
    double x, y;
};

vector <pt> up, down;

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
}


void solve(){
    up.clear(), down.clear();

    int n, q; cin >> n;  cin >> q;
    vector <pt> a(n);
    for(int i = 0; i < n; ++i){
    	cin >> a[i].x >> a[i].y;
    }

    convex_hull(a);

    for(int i = 0; i < SZ(down); ++i){
    	cout << down[i].x << " " << down[i].y << el;
    }
    for(int i = SZ(up) - 2; i >= 0; --i){
    	cout << up[i].x << " " << up[i].y << el;
    }

    map <int, pair <double, double>> rg;
    for(int i = -500; i <= 500; ++i){
    	rg[i] = {1, -1};
    }

    for(int i = 0; i < SZ(up) - 1; ++i){
    	if(up[i].x == up[i + 1].x){
    		rg[up[i].x].S = max(up[i].y, up[i + 1].y);
    	}
    	else{
    		double m = (up[i + 1].y - up[i].y) / (up[i + 1].x - up[i].x);
    		double c = up[i].y - m * up[i].x;
    		for(int x = up[i].x; x <= up[i + 1].x; ++x){
	    		rg[x].S = m * x + c;
	    	}
    	}    	
    }
    for(int i = 0; i < SZ(down) - 1; ++i){
    	if(down[i].x == down[i + 1].x){
    		rg[down[i].x].F = min(down[i].y, down[i + 1].y);
    	}
    	else{
    		double m = (down[i + 1].y - down[i].y) / (down[i + 1].x - down[i].x);
    		double c = down[i].y - m * down[i].x;
    		for(int x = down[i].x; x <= down[i + 1].x; ++x){
	    		rg[x].F = m * x + c;
	    	}
    	}    	
    }

    while(q--){
    	pt xy; cin >> xy.x >> xy.y;
    	bool safe = true;
    	if(rg[xy.x].F <= xy.y and xy.y <= rg[xy.x].S){
    		safe = false;
    	}
    	cout << xy.x << " " << xy.y << " is " << (safe ? "safe!" : "unsafe!") << el;
    }
    cout << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1, tc = 1;
    cin>>T;
    while(T--){
    	cout << "Case " << tc << el;
    	tc++;
        solve();
    }
    return 0;
}