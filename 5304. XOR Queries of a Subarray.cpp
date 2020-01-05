class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for(vector<int> que: queries){
            int i=que[0], j=que[1]; // start and end
            int num=0;
            for(; i<=j;i++)
                num^= arr[i];   // cummulative XOR
            res.push_back(num);
        }
        return res;
    }
};
