class ProductOfNumbers {
  public:
    vector < int > nums, prods;
  ProductOfNumbers() {
    nums.clear();
    prods.clear(); // prefix product array
  }

  void add(int num) {
    nums.push_back(num);
    if (prods.empty()) prods.push_back(num);
    else prods.push_back(prods.back() * num);
    if (num == 0) prods.clear(); // everything before this is useless, since any product containing this 0 will be 0
  }

  int getProduct(int k) {
    if (k > prods.size()) return 0; // ex. k = 3, prods.size() = 2, meaning 3rd to last num was 0
    if (k == prods.size()) return prods.back(); // indexing issues
    return prods.back() / prods[prods.size() - k - 1];
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
