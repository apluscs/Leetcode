class MyCalendarTwo {
    ArrayList < int[] > list;
    TreeSet < int[] > booked; //tracks double bookings

    public MyCalendarTwo() {
        list = new ArrayList < > ();
        booked = new TreeSet < > ((a, b) - > {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });
    }

    public boolean book(int start, int end) {
        int[] curr = new int[] {
            start,
            end
        };
        int[] bef = booked.floor(curr); //treeset allows for faster search than arraylist
        if (bef != null && bef[1] > curr[0]) return false;
        int[] aft = booked.higher(curr);
        if (aft != null && aft[0] < curr[1]) return false;
        for (int[] s: list) //iterate through single bookings
            if (start < s[1] && end > s[0]) //ensures overlap
                booked.add(new int[] {
                    Math.max(start, s[0]), Math.min(end, s[1])
                });
        list.add(curr);
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
