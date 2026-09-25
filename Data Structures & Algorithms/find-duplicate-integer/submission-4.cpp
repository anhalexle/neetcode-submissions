class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 2 phase
        // phase 1 find loop: find the intersection between two pointers
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow]; // ptr->next
            fast = nums[nums[fast]]; // ptr->next->next
        } while (nums[slow] != nums[fast]);

        // phase 2 detect entrace of cycle
        slow = nums[0]; // start of cycle
        while(slow != fast) // why not nums[slow] != nums[fast] slow = Listptr and fast = Listptr
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        // meet the start of cycle 
        return slow; //ptr
    }
};
