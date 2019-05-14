class MyCalendarThree {

    TreeMap < Integer, Integer > map;
    public MyCalendarThree() {
        map = new TreeMap < > ();
    }

    public int book(int start, int end) {
        int curr = 0, max = 0;
        map.put(start, map.getOrDefault(start, 0) + 1);
        map.put(end, map.getOrDefault(end, 0) - 1);
        for (int c: map.values()) { //boundary count
            curr += c;
            max = Math.max(max, curr);
        }
        return max;
    }
}
