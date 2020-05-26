class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
        unordered_map<string,vector<Transaction>> m;
        for(string t:transactions){
            Transaction tr(t);
            m[tr.name].push_back(tr);
        }
        for(auto p:m){  // name,
            auto& v=p.second;
            sort(v.begin(),v.end());
            int n=v.size();
            
            for(int j=0;j!=n;++j){
                bool b=v[j].amt>1000;
                int i=j-1;
                while(!b&&i!=-1&& v[j].time-v[i].time<=60){
                    if(v[j].city!=v[i].city) b=true;
                    // cout<<v[i].city<<" ";
                    i--;
                } 
                i=j+1;
                while(!b &&i!=n &&v[i].time-v[j].time<=60){
                    if(v[j].city!=v[i].city) b=true;
                     // cout<<v[i].city<<" ";
                    i++;
                } 
                if(b)res.push_back(v[j].s);
                // cout<<v[j].time<<","<<v[j].city<<endl;
            }
            // cout<<endl;
        }
        // for(auto t:m["lee"])cout<<"\""<<t.s<<"\",";
        
        return res;
    }

    
    struct Transaction{
        string name,city,s;
        int time,amt;
        Transaction(string& s):s(s){
            stringstream ss(s); //create string stream from the string
            string substr;
            getline(ss, substr, ','); 
            name=substr;
            getline(ss, substr, ','); 
            time=stoi(substr);
            getline(ss, substr, ','); 
            amt=stoi(substr);
            getline(ss, substr, ','); 
            city=substr;
        }
        bool operator <(const Transaction& other)const{
            return time<other.time;
        }
    };
};
