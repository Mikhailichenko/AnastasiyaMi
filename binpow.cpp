#include <iostream>

using namespace std;

double binpow (double a, int n){
   if (n<0) return 1/binpow(a, -n);
   if (n==0) return 1;
   if (n%2==0) return binpow(a, n/2)*binpow(a, n/2);
   return a*binpow(a, (n-1)/2);

}

int main()
{
   double a;
   int n;
   cin >> a;
   cin >> n;
   cout << binpow (a, n);
  return 0;
}
