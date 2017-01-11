#include <iostream>

using namespace std;

int binpow (int a, int n){
   if (n<0) return 1/binpow(a, -n);
   if (n==0) return 1;
   if (n%2==0) return binpow(a, n/2)*binpow(a, n/2);
   return a*binpow(a, n-1);
}

int f(int a, int n){
    int x=0;
    for (int i=0; i<n; i++){
        x+=a%10;
        a-=a%10;
        a/=10;
    }
    return x;
}

void ff(int a, int n){
    int x=a;
    x*=binpow(10, n);
    int e=binpow(10, n);
    for (int i=1; i<(n+1); i++){
        e+=(a%10)*binpow(10, (n-i));
        a-=a%10;
        a/=10;
    }
    e-=binpow(10, n);
    cout << (x+e) << endl;
}

void fff(int a, int n, int r){
    int x=a;
    x*=binpow(10, (n+1));
    r*=binpow(10, n);
    x+=r;
    int e=binpow(10, n);
    for (int i=1; i<(n+1); i++){
        e+=(a%10)*binpow(10, (n-i));
        a-=a%10;
        a/=10;
    }
    e-=binpow(10, n);
    cout << (x+e) << endl;
}

void print_palindrom (int n){
    if (n%2==0){
        for (int i=binpow(10, (n/2-1)); i<binpow(10, n/2); i++){
            if ((f(i,n/2)*2)%9==0) ff(i,n/2);
        }
    }
    else{
        for (int i=binpow(10, (n/2-1)); i<binpow(10, n/2); i++){
            for (int r=0; r<10; r++) {
            if ((r+f(i,n/2)*2)%9==0) fff(i, n/2, r);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    print_palindrom(n);
    return 0;
}
