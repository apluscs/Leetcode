class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> nums; // will insert after all elements <= num
    multiset<int>::iterator a=nums.begin(),b=nums.begin();
    MedianFinder() {
        
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
        return (*a+*b)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
