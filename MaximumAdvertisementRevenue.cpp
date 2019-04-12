#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long max_profit(vector<long long>& a, vector<long long>& b, int& n){
	long long sum = 0;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(unsigned int i=0;i<n;i++){
		sum += a[i] * b[i];
	}
	return sum;	
}
int main(){
	int n;
	cin>>n;
	vector<long long> a(n);
	vector<long long> b(n);
	for(unsigned int i=0;i<n;i++)
		cin>>a[i]>>b[i];
    cout<<max_profit(a,b,n);	
}
