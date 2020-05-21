class Solution {
public:
    int minRefuelStops(int target, int curr, vector<vector<int>>& stations) {
        int n=stations.size(),stops,i;
        priority_queue<int> pq;
        for(stops=0,i=0;curr<target;++stops){
            while(i!=n&&stations[i][0]<=curr){  // expand range of what stations you can visit
                pq.push(stations[i++][1]);
            }
            if(pq.empty())return -1;    // still haven't reached target & nothing to refuel 
            curr+=pq.top();     // why we keep old stations: if we can visit stations x in s stops, then we can also visit any station before that
            pq.pop();
        }
        return stops;
    }
};

// track what stations you can visit with current tank, visit the one with the most gas

class SolutionB {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size()+1;
        vector<vector<int>>dp(n,vector<int>(n));
        // cout<<n<<endl;
        fill(dp[0].begin(),dp[0].end(),startFuel);
        if(startFuel>=target)return 0;
        for(int i=1;i!=n;++i){  // using this many stops
            for(int j=i;j!=n;++j){  // with all these possible stops
                dp[i][j]=dp[i][j-1];    // can always use one less possible stop and achieve the same result
                if(dp[i-1][j-1]>=stations[j-1][0])  // if we can get to station j-1
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+stations[j-1][1]);   // choice of stopping at station j
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
            if(dp[i].back()>=target)return i;
        }
        return -1;
    }
};
