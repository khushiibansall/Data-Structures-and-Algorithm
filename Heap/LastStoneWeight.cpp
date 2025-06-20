class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // MAKE max heap
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        // now pick top element and store it in x
        // pop it
        // now pick new top element
        // store it in y
        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();

            int y = maxHeap.top();
            maxHeap.pop();

            // if x == y then push nothing into the heap, let it be and continue
            // finding the next 2 top elements otherwise add x - y to the heap , if it is 0 let it be move on to next 2 top elements
            if (x != y) {
                maxHeap.push(x - y);
            }
        }

        // return the last 1 element in the heap
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
