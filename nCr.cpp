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
