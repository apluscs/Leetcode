class MyHashMap {
    static int[] vals;
    /** Initialize your data structure here. */
    public MyHashMap() {
        vals = new int[1000001];
    }

    /** value will always be non-negative. */
    public void put(int key, int value) {
        vals[key] = value + 1; //if key is added, min entry of vals[key] = 1
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        return vals[key] - 1; //if no mapping, 0-1= -1 :)
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        vals[key] = 0;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
