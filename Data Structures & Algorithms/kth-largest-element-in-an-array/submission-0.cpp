class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // build max heap
        for (int i = nums.size() / 2 - 1; i >= 0; i--)
        {
            heapify(nums, i, nums.size());
        }

        int size = nums.size();
        while (k != 1) // pop to k - 1
        {
            swap(nums[0], nums[size - 1]);
            --size;
            heapify(nums, 0, size);
            k--;
        }
        return nums[0];
    }
private:
    void swap(int& a, int &b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    void heapify(vector<int>&nums, int root, int size)
    {
        int largest = root;
        
        int left = 2*largest + 1;
        int right = 2*largest + 2;

        if (left < size && nums[left] >= nums[largest])
        {
            largest = left;
        }

        if (right < size && nums[right] >= nums[largest])
        {
            largest = right;
        }

        if (largest != root)
        {
            swap(nums[largest], nums[root]);

            heapify(nums, largest, size);
        }
    }
};
