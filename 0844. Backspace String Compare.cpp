class Solution {
    public:
        int jump = 0;
    bool backspaceCompare(string S, string T) {
        int sp = S.length() - 1, tp = T.length() - 1;
        while (true) {
            jump = 1; //to move onto next char after all the deletions
            char snx = getNext(S, sp);
            // cout<<"snx: "<<snx<<", "<<jump<<endl;
            sp -= jump;

            jump = 1;
            char tnx = getNext(T, tp);
            // cout<<"tnx: "<<tnx<<", "<<jump<<endl;
            tp -= jump;

            if (snx != tnx) return false;
            if (snx == '.') break; //snx = tnx since we made it this far, and both reached the ends
        }
        return true;
    }

    char getNext(string str, int ind) {
        if (ind <= -1) return '.';
        int dels = 0; //# of chars to delete
        if (str[ind] == '#') {
            ind--;
            dels++;
            jump++;
        } //to get dels above 0
        while (ind != -1 && dels != 0) { //until all these deletions have met their char to delete
            if (str[ind] == '#') dels++;
            else dels--;
            ind--;
            jump++;
        }
        if (ind == -1) return '.';
        if (str[ind] == '#') return getNext(str, ind); //another set of deletions to do
        else return str[ind];
    }
};
