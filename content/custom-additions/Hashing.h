/**
 * Author: me
 * Description: Peter's hashing.
 */
#pragma once

ll hsh[MAXN], pw[MAXN];
ll hshX[MAXN], pwX[MAXN];
const ll base = 131;
const ll base2 = 1337;
const ll mod = 1000000007;
 
ll sub(int l, int r){
    ll x = (hsh[r] - hsh[l-1] * pw[r-l+1] % mod + mod)%mod;
    ll y = (hshX[r] - hshX[l-1] * pwX[r-l+1] % mod + mod)%mod;
    return (x << 31) | y;
}

int main {
    hsh[0] = 0; pw[0] = 1;
    hshX[0] = 0; pwX[0] = 1;
    for (int i = 0; i < n; i++){
        hsh[i+1] = (hsh[i]*base + s[i])%mod;
        pw[i+1] = pw[i] * base % mod;
        hshX[i+1] = (hshX[i]*base2 + s[i])%mod;
        pwX[i+1] = pwX[i] * base2 % mod;
    }
}