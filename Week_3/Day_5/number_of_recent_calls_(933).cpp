#include<bits/stdc++.h>
using namespace std;
class RecentCounter {
public:
    vector<int> pingArr;
    RecentCounter() {
        pingArr.resize(0);
    }
    
    int ping(int t) {
        int result;
        pingArr.push_back(t);
        auto it = (t - 3000 >= 0)? lower_bound(pingArr.begin(), pingArr.end(), t - 3000) : lower_bound(pingArr.begin(), pingArr.end(), 0);
        result = pingArr.end() - it;
        return result;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */