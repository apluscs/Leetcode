class Solution {
public:
    struct compar{
        bool operator () (const vector<int>& a, const vector<int>& b) const{
            return a[1]<b[1];
        }
    };

    struct compar2{
        bool operator () (const vector<int>& a, const vector<int>& b) const{
            return a[2]>b[2];
        }
    };
    bool carPooling(vector<vector<int>>& trips, int k) {
        int n=trips.size(),curr=0;
        sort(trips.begin(),trips.end(),compar());   // by start pos
        priority_queue<vector<int>, vector<vector<int>>, compar2> pq;   // by end pos, earliest comes first
        for(int i=0;i!=n;++i){
            auto t=trips[i];
            while(!pq.empty() && pq.top()[2]<=t[1]){
                curr-=pq.top()[0];  // drop off this many people
                pq.pop();
            }
            curr+=t[0];
            if(curr>k)return false;
            pq.push(t);
        }
        return true;
    }
};
