#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

int main()
{

    int low = 0, high = 1e9;

    int x = (low+high)/2;

    auto guess = [&]()
    {
        cout << "? " << x << endl;
        string tmp;
        cin >> tmp;
        bool smaller = tmp == "YES";
        if(smaller)low = x;
        else high = x;
        x = (low+high)/2;
    };
    while(high != x && x != low)guess();
    cout << "! " << high;
}