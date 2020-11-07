#include <bits/stdc++.h>
using namespace std;

string fun(vector <vector <int>> adj, int n){
	set <int> newCheaters;
	set <pair <int, int>> edges;
	for (int i = 1; i <= n; ++i){
		for(int j : adj[i]){
			if(edges.count({j, i})){
				newCheaters.insert(i);
				newCheaters.insert(j);
			}
			else{
				edges.insert({i, j});
			}
		}
	}


	set <int> cheaters = newCheaters, childs;
	while(newCheaters.size()){
		set <int> tmpCheaters;
		for(int chtr : newCheaters){
			for(int ch : adj[chtr]){
				if(tmpCheaters.count(ch) or cheaters.count(ch)) continue;
				if(childs.count(ch)){
					tmpCheaters.insert(ch);
					childs.erase(ch);
				}
				else{
					childs.insert(ch);
				}
			}
		}
		newCheaters = tmpCheaters;
		for(int chtr : tmpCheaters) cheaters.insert(chtr);
	}

	string ans;
	for(int chtr : cheaters){
		string str = to_string(chtr);
		ans.insert(ans.end(), str.begin(), str.end());
		ans.push_back(',');
	}
	if(ans.size()) ans.pop_back();
	return ans;
}
 
int main(){
    // vector <vector <int>> adj = {{}, {2, 3}, {1, 3}, {}};
    // vector <vector <int>> adj = {{}, {2, 3, 4}, {1, 4}, {}, {3}};
    vector <vector <int>> adj = {{}, {2, 3, 7, 8}, {1, 3, 7}, {4}, {8}, {4}, {}, {5}, {5}};
    cout<<fun(adj, 8)<<endl;
    return 0;
}