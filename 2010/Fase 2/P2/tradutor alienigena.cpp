#include <iostream>
#define sz(x) (int) x.size()

using namespace std;

const int maxn = 1e5 + 5,maxp = 1e2 + 5,mod = 1e9 + 7;

string x,y;
int a[maxp],b[maxn],check[maxn],dp[maxn][maxp];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> y;
    
    int tam = sz(x);
    int tam2 = sz(y);

    for(int i = 0;i < tam;i++) 
        a[i] = x[i] - '0';
    
    for(int i = 0;i < tam2;i++) 
        b[i] = y[i] - '0';

    dp[0][0] = 1;

    for (int i = 0;i <= tam2;i++){
        
        if(i + tam <= tam2){
            for(int j = i;j < i + tam;j++){
                if(a[j - i] > b[j]) break;
                if(a[j - i] < b[j]) {
                    check[i] = 1;
                    break;
                }
            }
        }
        
        for(int j = 1;j <= min(tam,i);j++){
            if(!b[i - j]) continue;
            if(j == tam && check[i - j]) break;
            dp[i + 1][j + 1] = dp[i][j] % mod;
            dp[i][0] = (dp[i][0] + dp[i][j]) % mod;
        }
        
        dp[i + 1][1] = dp[i][0] % mod;
    }

    cout << dp[tam2][0];
    return 0;
}
