#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m * n);//stores elements in spiral order
        int k = 0;
        int rowStart = 0, rowEnd = m - 1;//top and bottom boundaries
        int colStart = 0, colEnd = n - 1;//left and right boundaries
        while(rowStart <= rowEnd && colStart <= colEnd){
            for(int col = colStart; col <= colEnd; col++) ans[k++] = matrix[rowStart][col];//traverse top row
            rowStart++;//move top boundary down

            for(int row = rowStart; row <= rowEnd; row++) ans[k++] = matrix[row][colEnd];//traverse right column
            colEnd--;//move right boundary left

            if(rowStart <= rowEnd){
                for(int col = colEnd; col >= colStart; col--) ans[k++] = matrix[rowEnd][col];//traverse bottom row
                rowEnd--;//move bottom boundary up
            }

            if(colStart <= colEnd) {
                for(int row = rowEnd; row >= rowStart; row--) ans[k++] = matrix[row][colStart];//traverse left column
                colStart++;//move left boundary right
            }
        }
    return ans;
    }
};
/*
Approach:
- Maintain four boundaries: rowStart, rowEnd, colStart, and colEnd.
- Traverse the matrix layer by layer in spiral order.
- After each traversal, shrink the corresponding boundary.
- Continue until all elements are visited.
Time Complexity: O(m * n)
- Each element is visited exactly once.
Space Complexity: O(1)
- Excluding the output vector.
*/