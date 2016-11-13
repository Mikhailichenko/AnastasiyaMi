#include <iostream>

using namespace std;

double binpow (double a, int n){
   if (n<0) return 1/binpow(a, -n);
   if (n==0) return 1;
   if (n%2==0) return binpow(a, n/2)*binpow(a, n/2);
   return a*binpow(a, (n-1)/2);

}

int proper_fraction (int n){
   if (n==1) return 1;
   int t=2;
   for (; t*t<(n+1); t++){
    int p=0;
    while(n%t==0){
        n/=t;
        p++;
    }
    if (p>0) return binpow(t,p-1)*proper_fraction(n*t);
   }
   return n-1;
}

int main()
{
    int n;
    cin >> n;
    n=2*proper_fraction(n)+1;
    cout << n;
    return 0;
}
