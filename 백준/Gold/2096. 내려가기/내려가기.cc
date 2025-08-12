#include <iostream>
#include <algorithm>
using namespace std;

int n,a,b,c;

int main(){
    cin >> n;
    cin >> a >> b >> c;
    int max0 = a, max1=b, max2=c;
    int min0 = a, min1=b, min2=c;
    while(--n){
        cin >> a >> b >> c;
        int nmax0 = a + max(max0,max1);
        int nmax1 = b + max({max0,max1,max2});
        int nmax2 = c + max(max1,max2);

        int nmin0 = a + min(min0,min1);
        int nmin1 = b + min({min0,min1,min2});
        int nmin2 = c + min(min1,min2);
    
        max0 = nmax0, max1 = nmax1, max2 = nmax2;
        min0 = nmin0, min1 = nmin1, min2 = nmin2;
    }
    cout << max({max0,max1,max2}) << " " << min({min0,min1,min2});
}