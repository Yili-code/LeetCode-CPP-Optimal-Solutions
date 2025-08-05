## classification: greedy

## key insight

1. Always keep the interval that ends the earliest, because it leaves more space for the rest of the intervals.
-> sort the intervals in ascending order based on their end times.

2. Remove the minimum number of intervals so that the rest do not overlap.
-> Keep the maximum number of non-overlapping intervals.
-> Leave more space as you can.
-> sort the intervals in ascending order based on their end times.