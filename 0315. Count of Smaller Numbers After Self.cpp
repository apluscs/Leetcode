class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        vector<int> bit(n+1),res(n);
        for(int i=n-1;i!=-1;--i){
            int num=nums[i];
            auto it=lower_bound(temp.begin(),temp.end(),num);
            int pos=it-temp.begin();  // last index before for occurence of num in temp
            res[i] = getSum(bit,pos);   // +1 to adjust to BIT
            insert(bit,pos+1);  // index of num in temp
        }
        return res;
        
    }
    
    int getSum(vector<int>& nums, int i){
        int n=nums.size(),res=0;
        while(i>0){
            
            res+=nums[i];
            i -= (i & -i);
        }
        return res;
    }
    
    void insert(vector<int>& nums, int i){
        int n=nums.size();
        while(i<n){
            // cout<<i<<endl;
            nums[i]++;
            i += (i & -i);
        }
    }
    
    
};
