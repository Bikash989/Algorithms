#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

bool sortbyratio(const pair<int,int> &a, const pair<int,int> &b){
	return ((a.first/(a.second*1.0)) > (b.first/(b.second*1.0)));  //for descending put greater than > 
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values,int n) {
  double value = 0.0;

  // write your code here, OKAY boilerplate code
  
  vector<pair <int, int> > p; // > put space 
  for(int i = 0; i<n; i++){
  		p.push_back(make_pair(values[i],weights[i]));  	
  }
  sort(p.begin(), p.end(), sortbyratio);
  int curWeight = 0;
  for(int i = 0; i < n; i++){
  	if(curWeight + p[i].second <= capacity){
  		curWeight += p[i].second;
  		value += p[i].first;
	}
	else if(curWeight != capacity){
		int remain = capacity - curWeight;
		value += p[i].first * ((double) remain / p[i].second);
		break;
	}
  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }
  double optimal_value = get_optimal_value(capacity, weights, values, n);
  cout<<fixed<<setprecision(4);  
  cout << optimal_value << endl;
  return 0;
}
