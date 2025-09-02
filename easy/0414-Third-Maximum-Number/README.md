## unordered_set
```cpp
#include <unordered_set>

unordered_set<int> us;

// skip duplicates
if (us.count(num)) continue;

// update the record
us.insert(num);