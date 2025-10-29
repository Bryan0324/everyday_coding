#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) 
    {
        if(n == 1)return 1;
        return (1<<(__lg(n)+1)) - 1;   
    }
};