#include <bits/stdc++.h> 
using namespace std; 

#define deb3(x,y,z) cout<<#x<<"="<<x<<", "<<#y<<"="<<y<<", "<<#z<<"="<<z<<endl
#define st first
#define ed second

int main() { 
    vector <pair<int, int>> a = {{9, 10}, {15, 17}, {20, 21}}; 
    vector <pair<int, int>> b = {{10, 11}, {16, 18}, {22, 23}};
    int n = a.size(), m = b.size(), t = 1; 
    
    int i = 0, j = 0, ans = 0;
    int end = min(n ? a[0].st : INT_MAX, m ? b[0].st : INT_MAX);

    while(i<n or j<m){
        if(i<n and (j==m or a[i].st <= b[j].st)){
            if(a[i].st > end){
                ans += (a[i].st - end)/t;
                deb3(i, a[i].st, end);
            }
            end = max(end, a[i].ed);
            i++;
        }
        else{
            if(b[j].st > end){
                ans += (b[j].st - end)/t;
                deb3(j, b[j].st, end);
            }
            end = max(end, b[j].ed);
            j++;
        }
    }

    cout<<ans<<endl;
    return 0; 
}