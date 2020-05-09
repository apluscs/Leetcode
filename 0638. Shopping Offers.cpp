class Solution {
public:
    int n;
    unordered_map<string,int> m;
    vector<int> price;
    vector<vector<int>> special;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n=needs.size();
        this->price=price;
        this->special=special;
        return minPrice(needs);
    } 
    
    int minPrice(vector<int> needs){
        string id=getID(needs);
        // cout<<id<<endl;
        if(m.count(id))return m[id];
        int res=0;
        for(int i=0;i!=n;++i)res+=needs[i]*price[i];
        // cout<<id<<" "<<res<<endl;
        for(auto sp:special){
            auto temp=needs;
            for(int j=0;j!=n;++j){
                temp[j]-=sp[j]; // offer takes care of sp[j] many
            }
            if(*min_element(temp.begin(),temp.end())<0)continue;    // cannot use this offer
            res=min(res,minPrice(temp)+sp[n]);  // rest of needs + price of offer
        }
        
        m[id]=res;
        // cout<<id<<" "<<res<<endl;
        return res;
    }
    
    string getID(vector<int>& needs){
        string res="";
        for(int need:needs){
            res+=to_string(need)+" ";
        }
        return res;
    }
};
