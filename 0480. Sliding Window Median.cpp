class Solution {
public:
    struct MedianFinder { // perfect, already written from #295
        /** initialize your data structure here. */
        multiset<int> nums; // will insert after all elements <= num
        multiset<int>::iterator a=nums.begin(),b=nums.begin();
        MedianFinder() {

        }

        void deleteNum(int num){
            auto x=nums.lower_bound(num);
            int n=nums.size();
            if(n%2){    // a,b point to the same num
                if(x==a){   // go both ways
                    a--;
                    b++;
                }else if(num>*a){
                    a--;
                }else{
                    b++;
                }
            }else{  // a,b point to diff nums
                if(num<=*a)a=b;
                else b=a;
            }
            nums.erase(x);
        }

        void addNum(int num) {
            nums.insert(num);
            int n=nums.size();
            if(n==1){
                a=b=nums.begin();
            } else if(n%2){    // was even before, now is odd
                if(num>=*b)a=b; // we know num < b now
                else if(num>=*a){   // in between a,b
                    a++;    b--;
                }else b=a;  // left of a
            } else {    // was odd before, now is even
                if(num>=*a)b++;
                else a--;
            }
        }

        double findMedian() {
            // cout<<*a<<","<<*b<<endl;
            return (long(*a)+*b)/2.0;
        }
    };

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double> res;
        MedianFinder mf;
        res.reserve(n-k+1);
        for(int i=0,j=0;i!=n;++i){
            mf.addNum(nums[i]);
            if(i-j==k)mf.deleteNum(nums[j++]);
            if(i-j+1==k)res.push_back(mf.findMedian());
        }
        return res;
    }
    
    

};
