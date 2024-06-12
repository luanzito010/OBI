#include <iostream>
#define sz(x) (int) x.size()

using namespace std;

const int maxn = 1e5 + 5,maxd = 1e2 + 5,mod = 1e9 + 7,maxp = 2;

string a,b;
int check[maxn],dp[maxp][maxd];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;
    
    int tam = sz(a);
    int tam2 = sz(b);

    dp[0][0] = 1;

    for(int i = 0;i <= tam2;i++){
        
        for(int j = i;i + tam <= tam2 && j < i + tam;j++){
            if(a[j - i] > b[j]) break;
            if(a[j - i] < b[j]) {
                check[i] = 1;
                break;
            }
        }
        
        int at = i % maxp;
        int prox = (i + 1) % maxp;
        
        for(int j = 1;j <= min(tam,i);j++){
            if(b[i - j] == '0') continue;
            if(j == tam && check[i - j]) break;
            dp[prox][j + 1] = dp[at][j] % mod;
            dp[at][0] = (dp[at][0] + dp[at][j]) % mod;
        }
        
        dp[prox][1] = dp[at][0] % mod;
        dp[at][0] = 0;
    }

    cout << dp[(tam2 + 1) % maxp][1] << "\n";
    return 0;
}
