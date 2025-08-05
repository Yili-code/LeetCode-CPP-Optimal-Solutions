## classification: greedy

## key insight

1. Convert `n` to a string to manipulate digits easily.

```cpp
string str = to_string(n);
```

2. Traverse from right to left, looking for the fist digit that breaks the increasing order.

3. Once found, decrement that digit and make all digit after it to `9` to maximize the result while maintaining the constraint.

```cpp 
int flag;

flag = i;

for (int i = flag; i < str.size(); ++i) {
  str[i] = '9';
}
```

## common mistake
1. Not convert `n` to string.

2. Traverse from left to right