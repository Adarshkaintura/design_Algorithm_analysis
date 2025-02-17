#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
//tc nlogn , push and pop in logn and for n operation that's why nlogn
class Solution {
public:
    int nthUglyNumber(int n) {
        // Min heap to store the next possible ugly numbers
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seen;  // To avoid duplicates
        
        minHeap.push(1);  // First ugly number is 1
        seen.insert(1);   // Mark 1 as seen
        
        long ugly = 1;
        int factors[3] = {2, 3, 5};  // The prime factors of ugly numbers

        for (int i = 1; i < n; i++) {  // We already have the first ugly number
            ugly = minHeap.top();  // Get the smallest ugly number
            minHeap.pop();

            // Generate the next possible ugly numbers and add to the heap
            for (int f : factors) {
                long nextUgly = ugly * f;
                if (!seen.count(nextUgly)) {  // If not already seen
                    seen.insert(nextUgly);    // Mark as seen
                    minHeap.push(nextUgly);   // Add to heap
                }
            }
        }

        return ugly;  // After n iterations, the nth ugly number will be on top of the heap
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "The " << n << "th ugly number is: " << sol.nthUglyNumber(n) << endl;
    return 0;
}
