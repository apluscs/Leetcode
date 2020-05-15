class SolutionB { // provably O(NlogN) but slower than ordered mapping, would probably be faster with lazy propagation
public:
    map<int,int> intervals;
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n=positions.size(),high=0;
        unordered_map<int,int> cc=compress(positions);
        vector<int> res;
        res.reserve(n);
        int m=cc.size();    // "n" for segment tree
        STree stree(m);
        // cout<<m<<endl;
        for(auto pos: positions){
            int s=cc[pos[0]],e=cc[pos[0]+pos[1]-1];
            int curr=stree.getMax(s,e,0,m-1,1)+pos[1];
            // cout<<curr<<endl;
            stree.update(s,e,0,m-1,curr,1);
            // cout<<endl;
            high=max(high,curr);
            res.push_back(high);
        }
        return res;
    }
    
    unordered_map<int,int> compress(vector<vector<int>>& positions) {
        set<int> seen;
        for(auto pos:positions){
            seen.insert(pos[0]);
            seen.insert(pos[0]+pos[1]-1);
        }   // compress coordinates to numbers 1...m, where m = #unique start or end points
        unordered_map<int,int>res;
        int i=0;
        for(auto p:seen){
            res[p]=i++;
        }return res;
    }
    
    struct STree{
        vector<int> tree;
        STree(int n){
            int m=1<< int(ceil(log2(n)));
            tree.resize(2*m);   // 2*m-1 nodes, but it is 1-based
        }
        int getMax(int qs,int qe,int ns,int ne,int i){
            // cout<<ns<<" "<<ne<<","<<i<<" "<<endl;
            if(qs>ne||qe<ns||ns>ne)return 0;
            if(qs<=ns&&qe>=ne)return tree[i];
            
            int mid=(ns+ne)/2, a=getMax(qs,qe,ns,mid,2*i), b=getMax(qs,qe,mid+1,ne,2*i+1);
            return max(a,b);
        }
        void update(int qs,int qe,int ns,int ne,int val,int i){   // ns,ne = node's start and end;  i is index in tree; qs,qe = query's start and end
            // cout<<ns<<"_"<<ne<<","<<i<<"_"<<endl;
            if(qs>ne||qe<ns||ns>ne)return; // node disjoint with query
            tree[i]=max(tree[i],val);   // update here, since the updated range overlaps with urs
            if(ns==ne)return;   // at a leaf node
            int mid=(ns+ne)/2;
            update(qs,qe,ns,mid,val,2*i);
            update(qs,qe,mid+1,ne,val,2*i+1);
            
        }
    };         
};

class Solution {  // average NlogN, O(N^2) 
public:
    map<int,int> intervals;
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n=positions.size(),high=0;
        intervals[0]=0;
        vector<int> res;
        res.reserve(n);
        for(auto pos: positions){
            int s=pos[0],e=pos[0]+pos[1],curr=0;
            auto it=prev(intervals.upper_bound(s)); // first one <= s
            while(it!=intervals.end() && it->first<e){
                curr=max(it->second+pos[1],curr);
                // cout<<curr<<" ";
                it++;
            }
            // cout<<endl;
            high=max(high,curr);    // curr is best height for this block
            res.push_back(high);
            
            int tail=prev(intervals.upper_bound(e))->second;
            intervals[e]=tail;
            intervals[s]=curr;
            it=intervals.upper_bound(s); // first one > s
            while(it!=intervals.end() && it->first<e){
                intervals.erase(it);
                it=intervals.upper_bound(s);    // next one > s, log(n)
            }
        }
        return res;
    }
};

```
#python version, O(N^2) bc we comb through all intervals each time
class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        
        class Interval:
            def __init__(self,ht,start,end):
                self.start=start
                self.end=end
                self.ht=ht
                
        n,high=len(positions),0
        res,intervals=[],[]
        
        def getHeight(s:int ,e:int)->int:
            res=0
            for iv in intervals:
                if not(iv.end<=s or iv.start>=e):
                    res=max(res,iv.ht)
            # print(res)
            return res
        
        for pos in positions:
            curr=getHeight (pos[0],pos[0]+pos[1]) +pos[1]
            high=max(high,curr)
            res.append(high)
            intervals.append(Interval(curr, pos[0],pos[0]+pos[1]))
        return res
```
         
        
        
        
