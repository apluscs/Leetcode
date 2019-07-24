class Solution {  //NOT DONE
    HashSet[] adj;
    int[] count,res;
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        adj=new HashSet[N];
        count=new int[N];   res=new int[N];
        for(int i=0;i!=N;i++) adj[i]=new HashSet<Integer>();
        for(int[] e:edges){
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }
        countUp(0,-1);
        return res;
    }
    
    public void countUp(int curr,int par){
        count[curr]=1;  //count yourself
        for(int nei:adj[curr]){
            if(nei==par) continue;
            countUp(nei,curr);  
            count[curr]+=count[nei];    //add however many are below you
            res[curr]+=res[nei];    
        }
        res[curr]+=count[curr]-1; //one for each node except you
    }
}
