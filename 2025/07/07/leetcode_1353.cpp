#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        events.push_back({(int)1e6, 1});

        int i = 0, ans = 0, in = 0;
        priority_queue<int, vector<int>, greater<>> back;
        back.push(1e6);
        for(int now = 0; now < 1e5+1 && (i+1 < events.size() || !back.empty()); now++)
        {
            
            if(events[i][0] == now)for(; events[i][0] == now; i++)
            {
                back.push(events[i][1]+1);
                in++;
            }
            while(back.top() == now)
            {
                in--;
                back.pop();
            }
            if(in > 0)
            {
                ans++;
                in--;
                back.pop();
            }
        }
        return ans;
    }
};