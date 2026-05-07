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

class Solution {
public:
    // Design LRUCache class {

    }
};

int main() {
    Solution sol;

        // LRUCache cache(2);
    // cache.put(1,1); cache.put(2,2);
    // cout << cache.get(1) << "\n"; // 1
    // cache.put(3,3); // evicts key 2
    // cout << cache.get(2) << "\n"; // -1
    // cache.put(4,4); // evicts key 1
    // cout << cache.get(1) << "\n"; // -1
    // cout << cache.get(3) << "\n"; // 3
    // cout << cache.get(4) << "\n"; // 4
    cout << "LRUCache design problem" << "\n";

    return 0;
}
