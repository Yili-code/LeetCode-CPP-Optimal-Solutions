## classification: array

## key insight
1. First pass: count zeros (but avoid counting the last one if it doesn't fit)

```cpp
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
```

2. Second pass: fill from the back

```cpp
int last = n - 1 - zeros;
for (int i = last; i >= 0; --i) {*
  if (arr[i] == 0) {
    arr[i + zeros] = 0;
    zeros--;
    arr[i + zeros] = 0;
  } else {
    arr[i + zeros] = arr[i];
  }
}
```