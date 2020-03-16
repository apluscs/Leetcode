class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int N = mat.size(), M = mat[0].size();
        for(int j = 0; j != M; ++j) // first row 
            helper(0, j, mat);
        for(int i = 1; i != N; ++i) // first column starting at i = 1
            helper(i, 0, mat);
        return mat;
    }
    
    void helper(int si, int sj, vector<vector<int>>& mat){
        int N = mat.size(), M = mat[0].size(), i = si, j = sj;
        vector<int> nums;
        while(i != N && j != M){    // go diagonally
            nums.push_back(mat[i][j]);
            i++;    j++;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i != nums.size(); ++i){
            mat[si + i][sj + i] = nums[i];
        }
    }
};
