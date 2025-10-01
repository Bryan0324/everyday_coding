#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinked = 0, empty = 0;
        while(numBottles != 0)
        {
            drinked += numBottles;
            empty +=  numBottles % numExchange;
            numBottles /= numExchange;
            numBottles += empty / numExchange;
            empty %= numExchange;
        }
        return drinked;
    }
};