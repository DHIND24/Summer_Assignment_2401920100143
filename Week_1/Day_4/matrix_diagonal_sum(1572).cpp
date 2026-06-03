#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int primSum = 0, secSum = 0;//to store the pprimaray and secondary diagonal sum respectively
        for(int i=0; i<n; i++){
            primSum += mat[i][i];//primary diagonal element
            secSum += mat[i][n - i - 1];//secondary diagonal element
        }
        int result = primSum + secSum;
        if(n % 2 == 1) result -= mat[n/2][n/2];//remove double-counted center element
    return result;
    }
};
/*
Approach:
- Traverse the matrix once.
- Add primary diagonal elements to primSum.
- Add secondary diagonal elements to secSum.
- Add both sums.
- If n is odd, subtract the center element as it gets counted twice.
Time Complexity: O(n)
- Only diagonal elements are visited.
Space Complexity: O(1)
- Uses constant extra space.
*/