class Solution {
public:
    int climbStairs(int n) {
        // if (n <= 2) return n;
        // int arr[n + 1] = {0};
        // arr[n] = 1;
        // arr[n - 1] = 1;
        // for (int i = n - 2; i >= 0; i--)
        // {
        //     arr[i] = arr[i + 1] + arr[i + 2];
        // }
        // return arr[0];
        int one = 1, two = 1;
        for (int i = 0; i < n -1; i++)
        {
            int temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};
