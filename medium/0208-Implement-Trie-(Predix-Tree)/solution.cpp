class Trie {
private:
  struct TrieNode {
    bool isEnd;
    TrieNode* children[26];

    TrieNode(): isEnd(false) { 
      for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
  };

  TrieNode* root;

public:
  Trie() {
    root = new TrieNode();
  }

  void insert(string word) {
    TrieNode* temp = root;
    for (char c : word) {
      int index = c - 'a';
      if (!temp->children[index]) temp->children[index] = new TrieNode();
      temp = temp->children[index];
    }
    temp->isEnd = true;
  }

  bool search(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int index = c - 'a';
      if (!node->children[index]) return false;
      node = node->children[index];
    }
    return node->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
      int index = c - 'a';
      if (!node->children[index]) return false;
      node = node->children[index];
    }
    return true;
  }
};