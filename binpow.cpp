#include <iostream>

using namespace std;

int main()
{
       int a;
    int n;
    cin >> a;
    cin >> n;
    int binpow (int x, int y){
    if (x==0)
        cout << "1";
    if  (x%2==1)
        cout << binpow (x-1, y)*y;
    int s=binpow (x/2,y);
    cout << s*s;
    }
    binpow (n,a);
    return 0;
}
