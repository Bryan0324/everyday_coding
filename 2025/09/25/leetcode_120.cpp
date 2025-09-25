#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        for(int level = triangle.size()-2; level >= 0; level--)
        {
            for(int i = 0; i <= level; i++)
            {
                dp[level][i] += min(dp[level+1][i], dp[level+1][i+1]);
            }
        }
        return dp[0][0];
    }
};