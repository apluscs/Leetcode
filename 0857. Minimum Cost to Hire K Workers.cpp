class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int N=quality.size();
        vector<vector<double>> workers (N,vector<double>(2,0));
        for(int i=0;i!=N;i++){
            workers[i][0]=(double)wage[i]/quality[i];
            workers[i][1]=(double)quality[i];
        }
        sort(workers.begin(),workers.end(),compareWorkers);
        double res=DBL_MAX; int sumq=0;
        priority_queue<int> pq;
        for(vector<double> worker:workers){
            pq.push(worker[1]);
            sumq+=worker[1];
            if(pq.size() > K){
                sumq-=pq.top();  pq.pop();
            }
            if(pq.size()==K){
                res=min(res,worker[0]*sumq);
            }
        }
        return res;
        
    }
    
    static bool compareWorkers(vector<double> v1, vector<double> v2) { 
        return v1[0] < v2[0];
    } 
};
