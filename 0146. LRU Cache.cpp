class LRUCache {
    public:
        unordered_map < int, int > map, order;
        queue < int > que;
        int cap;
        LRUCache(int capacity): cap(capacity) {
            map.clear();
            order.clear();
            while (!que.empty()) que.pop(); // start anew
        }

        int get(int key) {
            if (map.count(key) == 0) return -1;
            order[key]++;
            que.push(key); // newest at the back
            return map[key];
        }

        void put(int key, int value) {
            if (map.size() >= cap && map.count(key) == 0) { // key not in map already
                while (true) {
                    int k = que.front();
                    que.pop(); // oldest process's key
                    order[k]--; // one less instance of k in the queue
                    if (order[k] > 0) continue; // there exists a newer usage of this key, so this older process isn't valid anymore
                    map.erase(k); // k doesn't exist in order anymore
                    break;
                }
            }
            order[key]++;
            que.push(key);
            map[key] = value;
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
