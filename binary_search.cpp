#include <iostream>
#include <vector>

using std::vector;

int binary_search(const vector<long long> &A, int low, int high, int key) {
  if (high < low){
  	return -1;
  }
  int mid = (int)((low + high) / 2);
  if (key == A[mid]){
  	return mid;
  }
  else if(key<A[mid]){
  	return binary_search(A,low,mid-1,key);
  }     
  else{
  	return binary_search(A,mid+1,high,key);
  }  
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<long long> b(m);
  for (size_t i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (size_t i = 0; i < m; ++i) {
    std::cout << binary_search(a,0,n-1,b[i]) << ' ';
  }
}
