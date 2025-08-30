class WordDictionary {
private:
  struct TrieNode {
    bool isEnd;
    TrieNode *alpha[26];

    TrieNode(): isEnd(false) {
      for (int i = 0; i < 26; ++i) alpha[i] = nullptr;
    }
  };

  TrieNode *root;

  bool dfs(string &word, int index, TrieNode *root) {
    if (!root) return false;
    if (index == word.size()) return root->isEnd;

    char c = word[index];
    char idx = c - 'a';
    
    if (c == '.') {
      for (int i = 0; i < 26; ++i) {
        if (root->alpha[i] && dfs(word, index + 1, root->alpha[i])) return true; 
      }
      return false;
    } else {
      return dfs(word, index + 1, root->alpha[idx]);
    }
  }

public:
  WordDictionary() {
    root = new TrieNode();
  }

  void addWord(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int index = c - 'a';
      if (!node->alpha[index]) { node->alpha[index] = new TrieNode(); }
      node = node->alpha[index];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    return dfs(word, 0, root);
  }
};
