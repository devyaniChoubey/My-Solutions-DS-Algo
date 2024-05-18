
//Fibonacci Series
//Time Complexity O(2^n)
//Space Complexity O(n)
int fun(int n){
  if(n == 0) return 0;
  if(n == 1) return 1;

  return fun(n-1) + fun(n-2);
}


//Check if a string is palindrome
bool checkPalindrome(int i, string s){
    int n = s.length();
    if(i >= s.length()/2) return true;

    if(s[i] != s[n-i-1]) return false;

    return checkPalindrome(i+1, s);
}

//Reverse Array
void reverseArray(int i, vector<int>&a){
  int n = a.size();

  if(i >= n/2) return;
  
  swap(a[i], a[n-1-i]);
  
  reverseArray(i+1, a);
}

//N Factorial
int factorial(int n){
  if(n == 1) return 1;

  return n*factorial(n-1);
}

//Function to find sum from 1 to N
int sum(int n){
  if(n == 0) return 0;

  return n+sum(n-1);
}

//Parametrised recursion to find sum from 1 to N
void sumFunc(int n, int sum){
  if(n < 1){
    cout << sum << endl;
    return;
  }

  sumFunc(n-1, sum + n);
}




