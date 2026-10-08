class MedianFinder {
public:
    priority_queue<int> smallHeap; // maxHeap
    priority_queue<int, vector<int>, greater<int>> largeHeap; // minHeap
    // why ? smallHeap(1,2) -> max:2; largeHeap(3,4) -> min: 3 -> median: 2.5 -> good
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);

        // make sure all el in small Heap is smaller than all el in largeHeap
        if (smallHeap.size() != 0 && largeHeap.size() != 0 && smallHeap.top() > largeHeap.top())
        {
            int largeEl = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(largeEl);
        }

        // uneven length
        if (smallHeap.size() > largeHeap.size() + 1)
        {
            int balEl = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(balEl);
        }

        if (largeHeap.size() > smallHeap.size() + 1)
        {
            int balEl = largeHeap.top();
            largeHeap.pop();
            smallHeap.push(balEl);
        }
    }
    
    double findMedian() {
        // even mới chia 2
        if (smallHeap.size() == largeHeap.size())
        {
            return (double)(smallHeap.top() + largeHeap.top()) / 2;
        }
        // odd thì return thằng đầu của mỗi Heap, max-> maxHeap, small với smallHeap
        if (smallHeap.size() > largeHeap.size())
        {
            return (double)smallHeap.top();
        }
     
        return (double)largeHeap.top();
    }
};
