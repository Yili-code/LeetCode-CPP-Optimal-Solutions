class Solution {
private:
  struct TrieNode {
    TrieNode *children[26];
    bool isEnd;

    TrieNode() : isEnd(false) {
      for (int i = 0; i < 26; ++i) { children[i] = nullptr; }
    }
  };

  TrieNode *root;

  void buildTrie(const string& s) {
    TrieNode *node = root;

    for (char c : s) {
      int idx = c - 'a';

      if (!node->children[idx]) node->children[idx] = new TrieNode();
      node = node->children[idx];
    }

    node->isEnd = true;
  }

  string helper(const string& word) {
    TrieNode* node = root;
    string prefix;

    for (char c : word) {
      int idx = c - 'a';  

      if (!node->children[idx]) break;
      prefix += c;
      node = node->children[idx];
      if (node->isEnd) return prefix;
    }
    return word;
  }

public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    root = new TrieNode();

    // build trie tree
    for (string s : dictionary) {
      buildTrie(s);
    }

    // process word in sentence
    stringstream ss(sentence);
    string word;
    string result;
    bool first = true;

    while (ss >> word) { 
      if (!first) result += " ";
      result += helper(word); 
      first = false;
    }

    return result;
  }
};
