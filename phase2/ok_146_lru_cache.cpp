/*
 * 146. LRU Cache
 * Difficulty: Medium
 * Tags: Hash Table, Linked List, Design
 *
 * Description:
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 * LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
 * int get(int key): Return the value of the key if the key exists, -1 otherwise.
 * void put(int key, int value): Update or insert the value. Evict the LRU key
 *   when the cache reaches its capacity.
 *
 * Constraints:
 * - 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls to get and put.
 */

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int,int>> lst;                  // {key, value}，頭 = 最近使用，尾 = 最久未用
    unordered_map<int, list<pair<int,int>>::iterator> mp; // key → list iterator

    // 把某個節點移到 list 頭部（標記為最近使用）
    void moveToFront(unordered_map<int, list<pair<int,int>>::iterator>::iterator it) {
        lst.splice(lst.begin(), lst, it->second);
    }

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;  // 不存在
        moveToFront(it);                // 標記為最近使用
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            // key 已存在：更新值並移到頭部
            it->second->second = value;
            moveToFront(it);
        } else {
            // key 不存在：新增節點
            if ((int)lst.size() == cap) {
                // 超過容量，淘汰尾部（最久未用）
                mp.erase(lst.back().first);
                lst.pop_back();
            }
            lst.push_front({key, value});
            mp[key] = lst.begin();
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1,1); cache.put(2,2);
    cout << cache.get(1) << "\n"; // 1
    cache.put(3,3);               // evicts key 2
    cout << cache.get(2) << "\n"; // -1
    cache.put(4,4);               // evicts key 1
    cout << cache.get(1) << "\n"; // -1
    cout << cache.get(3) << "\n"; // 3
    cout << cache.get(4) << "\n"; // 4

    return 0;
}
