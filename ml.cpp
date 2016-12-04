#include <iostream>

using namespace std;

bool f (int x){
     for (int i=2; i*i<(x+1);i++){
        if (x%i==0) return 0;
     }
     return 1;
}

bool ff (int x){
     if (f(x)) return 0;
     int r=0;
     for (int i=2; i*i<(x+1); i++){
        if (f(i)){
            if (x%i==0) r++;
        }
        if (r==3) return 0;
     }
     return 1;
}

int main()
{
    int n;
    cin >> n;
    int* a = new int [n];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int r=1;
    for (int i=0; i<n; i++){
        if (ff(a[i])) r*=a[i];
    }
    cout << r;
    return 0;
}
