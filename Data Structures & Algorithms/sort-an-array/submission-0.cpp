class Solution {
public:
    void merge(vector<int>& ans, int left, int mid, int right)
    {
        int l1 = mid - left + 1;
        int l2 = right - mid;

        vector<int> tmp1(l1), tmp2(l2);
        for (int i = 0; i < l1; i++)
        {
            tmp1[i] = ans[left + i];
        }
        for (int j = 0; j < l2; j++)
        {
            tmp2[j] = ans[mid + 1 + j];
        }
        int i = 0, j =0;
        int k = left;
        while (i < l1 && j < l2)
        {
            if (tmp1[i] < tmp2[j])
            {
                ans[k] = tmp1[i];
                i++;
            }
            else
            {
                ans[k] = tmp2[j];
                j++;
            }
            k++;
        }

        while (i < l1)
        {
            ans[k] = tmp1[i];
            i++;
            k++;
        }

        while (j < l2)
        {
            ans[k] = tmp2[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& ans, int left, int right)
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(ans, left, mid);
        mergeSort(ans, mid + 1, right);
        merge(ans, left, mid, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        mergeSort(nums, left, right);
        return nums;
    }
};