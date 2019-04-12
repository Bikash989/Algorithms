#include<iostream>
#include<vector>
using namespace std;

int fibo(long long m){
    size_t n=3000;
    vector<long long> f(n);
    f[0]=0;
    f[1]=1;
    for(size_t i=2;i<=n;i++){
        f[i]=(f[i-1] + f[i-2]) % m;
    }
    int count=1;
    for(size_t i=2;i<=n;i++){
    count++;
       if(f[i]==0 && f[i+1]==1){
        break;
       }
    }
    return count;
}
long long get_n_fib(int n,int m){
    long long a=0,b=1,c=1;
    if(n<=1){
        return n;
    }
    for(int i=1;i<n;i++){
        c=(a+b) % m;
        a=b;
        b=c;
    }
    return c;
}
int main(){
    long long n;
    int m;
    cin>>n>>m;
    int count = fibo(m);
    int rem = n % count;
    cout<<get_n_fib(rem,m) % m;
    }
