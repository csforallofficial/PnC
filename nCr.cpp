//When there is no overflow, the below code will work just fine.

#include<bits/stdc++.h>
using namespace std;

int comb[100005];
void ncr(){
    int ans = 1;
    comb[0] = ans;
    for(int i = 1; i < 100005; i++){
        ans *= i;
        comb[i] = ans;
    }
}
int main(){
    ncr();
    int t;
    cin >> t;
    while(t--){
        int n,r;
        cin >> n >> r;
        cout << comb[n]/(comb[r]*comb[n-r]) << endl;
    }
    return 0;
}


//In case of overflow, use this. This is the most optimal method using MOD

#include<iostream>
using namespace std;
#define int long long

int fact[100006], powerr[100006];
int mod = (int)(1e9+7);

int power(int base, int n, int mod){
    int ans = 1;
    while(n){
        if(n%2){
            n = n-1;
            ans = (ans*base)%mod;
        }
        else{
            n = n/2;
            base = (base*base)%mod;
        }
    }
    return ans;
}

void PreComputeFact(){
    fact[0] = 1;
    int ans = 1;
    for(int i = 1; i <= 100005; i++){
        ans = (ans*i)%mod; 
        fact[i] = ans;
        powerr[i] = power(fact[i],mod-2,mod);
    }
}

int ncr(int n, int r){
    return (fact[n]*(powerr[r]*powerr[n-r])%mod)%mod;
}

void testcase(){
    PreComputeFact();
    int t;
    cin >> t;
    while(t--){
        int n, r;
        cin >> n >> r;
        cout << ncr(n-1,r-1) << endl;
    }
}

signed main(){
    testcase();
    return 0;
}
