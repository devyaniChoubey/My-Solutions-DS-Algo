https://www.interviewbit.com/problems/colorful-number/

int Solution::colorful(int A) {
    string s = to_string(A);
    
    unordered_set<int>products;
    
    int n = s.length();
    
    for(int i=0;i < n;i++){
        int product = 1;
        for(int j=i;j < n;j++){
            product *= (s[j] - '0');
            
            if(products.find(product) != products.end()){
                return 0;
            }
            
            products.insert(product);
        }
    }
    
    return 1;
}
