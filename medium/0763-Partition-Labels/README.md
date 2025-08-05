## problem description:

Split the input string `s` into as many parts as possible such that each letter appears in at most one part, and return the sizes of these parts.

## classification: greedy

## key insight
1. Record the last occurence of each character

```cpp
int lastIndex[26] = {0};
for (int i = 0; i < s.size(); ++i) {
  lastIndex[s[i] - 'a'] = i;
}
```

-> know when a partition can safely end

2. Traverse and form partitions

```cpp
int left = -1, right = 0;
for (int i = 0; i < s.size(); ++i) {
  right = max(right, lastIndex[s[i] - 'a']);
  if (i == right) {
    result.push_back(i - left);
    left = i;
  }
}
```

`right`: marks the farthest boundary we must reach before we can split.