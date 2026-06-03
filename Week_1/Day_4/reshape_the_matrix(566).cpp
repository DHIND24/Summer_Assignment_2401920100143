#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m*n != r*c) return mat;//reshape not possible(element countin new matrix must be greater than or equal to givern matrix)
        vector<vector<int>> result(r, vector<int>(c));
        for(int idx = 0; idx < m * n; idx++)result[idx / c][idx % c] = mat[idx / n][idx % n];//map old index to new index
    return result;
    }
};
/*
Approach:
- Treat both matrices as a single 1D array.
- Use the same index to access elements in the original and reshaped matrices.
- Map the index to row and column positions using division and modulo.
Time Complexity: O(m * n)
- Each element is visited exactly once.
Space Complexity: O(1)
- No extra space used apart from the required output matrix.
*/