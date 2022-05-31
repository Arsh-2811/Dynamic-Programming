#include<bits/stdc++.h>
using namespace std;

int minCoins(int coin[], int n, int amount){
    int ans = 0;
    sort(coin, coin+n);
    for(int i = n-1; i >= 0; i--){
        if(coin[i] <= amount){
            int c = floor(amount/coin[i]);
            ans += c;
            amount -= c*coin[i];
        }
        if(amount == 0){
            break;
        }
    }
    return ans;
}

int main(){

    int coin[] = {5, 10, 2, 1}, n = 4, amount = 57;
    cout << minCoins(coin, n, amount) << endl;

    return 0;
}