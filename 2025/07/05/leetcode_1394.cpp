#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[501] = {0};
        for(auto &i : arr) cnt[i]++;
        
        for(size_t i = 500; i >= 1; i--)if(cnt[i] == i)return i;
        return -1;
    }
};