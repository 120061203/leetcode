/*
 * 703. Kth Largest Element in a Stream
 * Difficulty: Easy
 * Tags: Tree, Design, Binary Search Tree, Heap
 *
 * Description:
 * Design a class to find the kth largest element in a stream.
 *
 * Constraints:
 * - 1 <= k <= 10^4
 * - 0 <= nums.length <= 10^4
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {

    }
    int add(int val) {
        return 0;
    }
};

int main() {
    vector<int> init = {4, 5, 8, 2};
    KthLargest kl(3, init);
    cout << kl.add(3)  << "\n"; // 4
    cout << kl.add(5)  << "\n"; // 5
    cout << kl.add(10) << "\n"; // 5
    cout << kl.add(9)  << "\n"; // 8
    cout << kl.add(4)  << "\n"; // 8

    return 0;
}
