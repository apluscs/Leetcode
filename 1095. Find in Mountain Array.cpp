/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mtn) {
        int n=mtn.length(),low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int a=mtn.get(mid),b=mtn.get(mid+1);
            if(a<b) low=mid+1;
            else high=mid-1;
        }
        int peak=low;
        int a=bsearch(mtn,target,0,peak);
        if(a!=-1) return a;
        return bsearch2(mtn,target,peak+1,n-1);
        
    }
    
    int bsearch(MountainArray &mtn,int target, int low,int high){   // ascending portion
        while(low<=high){
            int mid=(low+high)/2;
            int a=mtn.get(mid);
            if(a==target) return mid;
            if(a<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    
    int bsearch2(MountainArray &mtn,int target, int low,int high){
        while(low<=high){
            int mid=(low+high)/2;
            int a=mtn.get(mid);
            if(a==target) return mid;
            if(a>target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};


