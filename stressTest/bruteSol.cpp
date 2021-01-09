#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
set<pair<int, int>> ok;    // set to store valid dimensions for a piece.
int dp[N][N];        // dp table for memoization.

int min_nonValid_area(int l, int b)     // function to calculate minimum non valid area for a chochlate
{   //  piece having dimension (l, r).
    if (dp[l][b] == -1) {
        if (ok.find({l, b}) != ok.end()) { // checking whether current piece is valid or not.
            return dp[l][b] = 0;        // If it is, them we can return zero for current dimension.
        }
        int ans = l * b;                // Base case, in worst case the whole piece is wasted.
        for (int i = 1; i < b; i++) {   //  (that is if we are not able to break it down further)
            ans = min(ans, min_nonValid_area(l, i) + min_nonValid_area(l, b - i));
            // Making all possible horizontal cuts, one by one and calculating
            //  the sum of minimum non valid area for both resulting pieces.
        }
        for (int i = 1; i < l; i++)
        {
            ans = min(ans, min_nonValid_area(i, b) + min_nonValid_area(l - i, b));
            // Making all possible vertical cuts, one by one and calculating
            //  the sum of minimum non valid area for both resulting pieces.
        }
        dp[l][b] = ans;
    }
    return dp[l][b];
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; ++i){
        int x, y; cin >> x >> y;
        ok.insert({x, y});
        ok.insert({y, x});
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)     // Filling dp table with -1, indicating that results are not computed yet.
            dp[i][j] = -1;
    }

    cout << min_nonValid_area(n, m) << "\n";
    return 0;
}
