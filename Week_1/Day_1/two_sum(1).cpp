#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;//stores {value, index}
        for (int i = 0; i < (int)nums.size(); ++i) {
            int comp = target - nums[i]; //number needed to reach target
            if (mp.find(comp) != mp.end()) //if complement exists
                return {mp[comp], i}; //return its index and current index
            mp[nums[i]] = i; //save current value for future lookups
        }
        return {};//no pair found
    }
};