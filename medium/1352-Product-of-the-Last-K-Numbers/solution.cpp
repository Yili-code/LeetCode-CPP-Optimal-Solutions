class ProductOfNumbers {
public:
  vector<int> v = {1};
  ProductOfNumbers() {}
  
  void add(int num) {
    if (num == 0) {
      v = {1};
    } else {
      v.push_back(v.back() * num);
    }
  }

  int getProduct(int k) {
    if (k >= v.size()) return 0;
    return v.back() / v[v.size() - k - 1];
  }
};