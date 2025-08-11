class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // First pass: count zeros (but avoid counting the last one if it doesn't fit)
        for (int i = 0; i + zeros < n; ++i) {
            if (arr[i] == 0) {
                // Special case: zero at the last position to fill
                if (i + zeros == n - 1) {
                    arr[n - 1] = 0;
                    n--; // shrink array length by one
                    break;
                }
                zeros++;
            }
        }

        // Second pass: fill from the back
        int last = n - 1 - zeros;
        for (int i = last; i >= 0; --i) {
            if (arr[i] == 0) {
                arr[i + zeros] = 0;
                zeros--;
                arr[i + zeros] = 0;
            } else {
                arr[i + zeros] = arr[i];
            }
        }
    }
};
