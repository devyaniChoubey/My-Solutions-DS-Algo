https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
public:
    vector<int>prefixProd;
    int size = 0;

    ProductOfNumbers() {
        prefixProd.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num == 0){
            prefixProd = {1};
            size = 0;
        }else {
            prefixProd.push_back(prefixProd[size]*num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(size >= k) return prefixProd[size]/prefixProd[size-k];
        else return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */