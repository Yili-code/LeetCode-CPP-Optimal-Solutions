## Classification: Dynamic Programming 

## Key Insight
1. Subset Representation
   - `P` represents the subset assigned a `+` sign.  
   - `M` represents the subset assigned a `-` sign.

   ```cpp
   P - M = target
   P + M = Sum

   M = P - target
   P + (P - target) = Sum
   P = (Sum + target) / 2

   if ((Sum + target) % 2 != 0) return 0;

   // Example
   // nums = [1, 1, 1, 1, 1], Sum = 5, target = 3
   // P = 4, M = Sum - P = 1
   ```

2. pre-check: plus can be negative -> `if (sum < abs(target)) return 0`

3. DP Array Size 
   - The DP array size is `plus + 1` where `plus = (Sum + target) / 2`.

4. Backward Traversal Logic
   ```cpp
   for (int num : nums) {
       for (int i = plus; i >= num; --i) {
           dp[i] += dp[i - num];
       }
   }
   ```

