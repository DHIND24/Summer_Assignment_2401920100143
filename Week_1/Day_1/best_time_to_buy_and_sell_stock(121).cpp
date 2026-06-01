#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        for(int price : prices){
            minPrice = min(price, minPrice);//update lowest buying price
            maxProfit = max(maxProfit, price - minPrice);//profit if sold today
        }
    return maxProfit;
    }
};
/*
Approach:
- Track the minimum stock price seen so far.
- For each price, calculate the profit if sold on that day.
- Keep updating the maximum profit.
Time Complexity: O(n)
- Single traversal of the array.
Space Complexity: O(1)
- Uses only constant extra space.
*/