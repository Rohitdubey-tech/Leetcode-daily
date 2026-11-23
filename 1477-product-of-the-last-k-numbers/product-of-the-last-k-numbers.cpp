class ProductOfNumbers {
    vector<int> productsOfNumber;
    int productTillNow;
public:
    ProductOfNumbers() {
        productTillNow = 1;
    }
    
    void add(int num) {
        if(num == 0) {
            productsOfNumber.clear();
            productTillNow = 1;
            return;
        }
        
        productTillNow *= num;
        productsOfNumber.push_back(productTillNow);
    }
    
    int getProduct(int k) {
        int productsOfNumberSize = productsOfNumber.size();
        if(productsOfNumberSize < k) return 0;
        if(productsOfNumberSize == k) return productTillNow;
        return productTillNow / productsOfNumber[productsOfNumberSize - 1 - k];
    }
}; 