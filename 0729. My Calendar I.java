class MyCalendar {
    public static TreeSet < int[] > set;  //maintains sortedness
    public MyCalendar() {
        set = new TreeSet < > ((a, b) - > {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });
    }

    public boolean book(int start, int end) {
        int[] curr = new int[] {
            start,
            end
        };
        int[] bef = set.floor(curr); //lower or equal to, checks if alr present
        if (bef != null && bef[1] > start) return false;
        int[] aft = set.ceiling(curr);
        if (aft != null && aft[0] < end) return false;
        set.add(curr);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
