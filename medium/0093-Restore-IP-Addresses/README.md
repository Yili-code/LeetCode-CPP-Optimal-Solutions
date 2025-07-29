## classification: backtracing

## key insight
1. `path.erase(4);` : delete path from `index[4]` to end (`index[path.size() - 1]`)

2. Implement backtracing:
```cpp
int path.length();
backtracing(...);
path.erase(originalLength);
```