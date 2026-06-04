/*
 * 295. Find Median from Data Stream
 * Difficulty: Hard
 * Tags: Two Pointers, Design, Sorting, Heap
 *
 * Description:
 * Find the median of a data stream using two heaps.
 *
 * Constraints:
 * - At most 5*10^4 calls to addNum and findMedian
 */

#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    void addNum(int num) {

    }
    double findMedian() {
        return 0.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1); mf.addNum(2);
    cout << mf.findMedian() << "\n"; // 1.5
    mf.addNum(3);
    cout << mf.findMedian() << "\n"; // 2.0

    return 0;
}
