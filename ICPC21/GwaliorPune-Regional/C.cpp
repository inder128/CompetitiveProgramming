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


const int mod = 1e9 + 7;

int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}

int sub(int x, int y){
    return add(x, -y);
}

int mul(int x, int y){
    return (x * 1ll * y) % mod;
}

int binPow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x){
    return binPow(x, mod - 2);
}

int divide(int x, int y){
    return mul(x, inv(y));
}



void solve(){
    int n; cin >> n;
    int x = 0;
    string nums, dir; cin >> nums >> dir;
    int left = 0, right = 0, both = 0;
    vi cnt(7);
    for(int i = 0; i < n; ++i){
    	if(nums[i] != '?' and dir[i] != '?'){
    		x += (dir[i] == 'R' ? 1 : -1) * (nums[i] - '0');
    	}
    	else if(nums[i] == '?' and dir[i] == '?'){
    		both++;
    	}
    	else if(nums[i] == '?'){
    		if(dir[i] == 'L'){
    			left++;
    		}
    		else{
    			right++;
    		}
    	}
    	else if(dir[i] == '?'){
    		cnt[nums[i] - '0']++;
    	}
    }

    bool not0 = false;
    if(left == 0 and right == 0 and both == 1){
    	not0 = true;
    }

    int low = -6 * left + right;
    int high = 6 * right - left;
    low -= both * 6;
    high += both * 6;
    swap(low, high);
    low *= -1;
    high *= -1;

    int mx = 0;
    for(int i = 1; i <= 6; ++i){
    	mx += cnt[i] * i;
    }

    vi DP(2 * mx + 1);
    DP[mx] = 1;
    for(int i = 1; i <= 6; ++i){
    	int stp = 2 * i;
    	vi pre(2 * mx + 1);
    	for(int j = 0; j < 2 * mx + 1; ++j){
    		pre[j] = DP[j] + ((j - stp) >= 0 ? pre[j - stp] : 0);
    	}

    	vi newDP(2 * mx + 1);
    	for(int j = 0; j < 2 * mx + 1; ++j){
    		int l, r;
    		if(cnt[i] % 2){
    			int mxstp = (2 * mx - j) / i;
    			if(mxstp % 2 == 0 and mxstp) mxstp--;
    			r = j + min(mxstp, cnt[i]) * i;
    			mxstp = (j - 0) / i;
    			if(mxstp % 2 == 0 and mxstp) mxstp--;
    			l = j - min(mxstp, cnt[i]) * i;

    			if(l == j){
    				l = r;
    			}
    			else if(r == j){
    				r = l;
    			}
    		} 
    		else{
    			r = j + min((2 * mx - j) / stp, cnt[i] / 2) * stp;
    			l = j - min((j - 0) / stp, cnt[i] / 2) * stp;
    		}
    		newDP[j] = ((pre[r] - ((l - stp) >= 0 ? pre[l - stp] : 0)) > 0);
    	}

    	DP = newDP;
    }

    vi vis(2 * 6 * n + 1);
    for(int i = 0; i < 2 * mx + 1; ++i){
    	if(DP[i]){
    		vis[x + (i - mx) + 6 * n] = 1;
    	}
    }

    vi pre = vis;
    for(int i = 1; i < SZ(pre); ++i){
    	pre[i] += pre[i - 1];
    }
    auto get = [&](int l, int r){
    	maxi(l, 0), mini(r, SZ(pre) - 1);
    	if(l > r){
    		return 0ll;
    	}
    	return pre[r] - (l ? pre[l - 1] : 0ll);
    };

    int ans = 0;
    for(int i = 0; i < 2 * 6 * n + 1; ++i){
    	int sm = get(i + low, i + high);
    	if(not0 and vis[i]){
    		sm--;
    	}
    	if(sm > 0){
    		ans = add(ans, mul(i - 6 * n, i - 6 * n));
    		int z = i - 6 * n;
    	}
    }

    cout << ans << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}