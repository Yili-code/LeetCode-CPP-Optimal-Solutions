## classification: backtracing

## key insight
0. For each character in the string `s`, use a `for` loop to check whether the substring `s[startIndex...i]` is a palindrome:

- If `isPalindrome(substring)` returns `true`:
  - Add the substring into the current `path`
  - Continue backtracking from the next index `i + 1`

- If `isPalindrome(substring)` returns `false`:
  - Skip this substring and continue checking longer substrings by increasing `i`

1. palindrome: use two pointers to check

2. each recursive call tries to partition the string starting at startIndex

3. pushes a single character (a `char`), but path is a `vector<string>`, so this causes type mismatch.
```cpp
string sub = s.substr(startIndex, i - startIndex + 1); // get substring
path.push_back(sub);
```

4. `s.substr(startIndex, length);`
```cpp
s = abcde;
string sub = s.substr(1, 2);
sub is "bc";
```