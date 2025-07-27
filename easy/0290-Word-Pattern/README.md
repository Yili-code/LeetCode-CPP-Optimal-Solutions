## key insight
1. `if (!um[ch]) {...}` does not work
  - `um[ch]` will insert a default value even if the key doesn't exist
  - correct way: `if (um.find(ch) == um.end()) {...}`

2. Split string s into words.
  - remember to skip spaces between words
  - `if s[i] is space (s[i] == ' ') or i is the last number (i == s.size()), then add temp(string) into words(vector<string>).
else add s[i] into temp(string).
`

3. use reverse_um to implement bidirectional mapping

4. `um.count()` is a C++ STL unordered_map method that checks whether a key exists in the map.

5. other way to split string s into words

    ````cpp
    vector<string> words;
    stringstream ss(s);
    string word;

    while (ss >> word) {
      words.push_back(word);
    }

  - `stringstream ss(s);` treats the string s like a stream (like reading from a file).
  - `ss >> word` automatically extracts words separated by spaces (ignore multiple spaces automatically).