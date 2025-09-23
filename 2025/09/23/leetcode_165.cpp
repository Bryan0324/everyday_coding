#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1 = {0}, ver2 = {0};
        version1 += '.';
        version2 += '.';

        for(auto &i : version1)
        {
            if(i == '.')ver1.push_back(0);
            else
            {
                ver1.back() *= 10;
                ver1.back() += i-'0';
            }
        }
        for(auto &i : version2)
        {
            if(i == '.')ver2.push_back(0);
            else
            {
                ver2.back() *= 10;
                ver2.back() += i-'0';
            }
        }
        ver1.resize(max(ver1.size(), ver2.size()), 0);
        ver2.resize(max(ver1.size(), ver2.size()), 0);
        for(int i = 0; i < ver1.size(); i++)
        {
            if(ver1[i] < ver2[i])return -1;
            if(ver1[i] > ver2[i])return 1;
        }
        return 0;
    }
};