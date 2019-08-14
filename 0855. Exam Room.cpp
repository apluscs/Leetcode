class ExamRoom {
    public:
        set < int > kids;
    int N;
    ExamRoom(int N) {
        kids.clear();
        // kids.insert(N);
        this - > N = N; //this is a pointer, need to dereference
    }

    int seat() {
        int dist = 0, pos = 0;
        if (kids.size() == 0) {
            kids.insert(0);
            return 0;
        }
        int first = * kids.begin();
        if (first > dist) dist = first; //pos is still 0
        for (set < int > ::iterator it = kids.begin(); next(it, 1) != kids.end(); it++) {
            int nx = * next(it, 1), curr = * it, p = (curr + nx) / 2, d = p - curr;
            if (d > dist) { //d is always distance from left neighbor (always the smaller dist)
                dist = d;
                pos = p;
            }
            // cout<<*it<<", ";
            // cout<<endl;
        }
        // cout<<endl;

        int last = * prev(kids.end());
        if (N - 1 - last > dist) pos = N - 1;
        kids.insert(pos);
        return pos;
    }

    void leave(int p) {
        kids.erase(p);
    }
};

/** 
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
