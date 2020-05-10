class MyCircularDeque {
public:
    int k,front,rear;
    vector<int> deq;
    MyCircularDeque(int k) {
        this->k=k;
        deq.resize(k);
        front=k;
        rear=0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull())return false;
        if(isEmpty())front=rear;
        front=(front+k-1)%k;
        deq[front]=value;
        
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull())return false;
        if(isEmpty()) front=rear;   // updating
        deq[rear]=value;
        rear=(rear+1)%k;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())return false;
        front=(front+1)%k;
        if(front==rear)front=k;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())return false;
        rear=(rear+k-1)%k;
        if(front==rear)front=k;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty()?-1:deq[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty()?-1:deq[(rear+k-1)%k];  // one before the last
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front==k;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return front==rear;     // rear = next place to put something
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
