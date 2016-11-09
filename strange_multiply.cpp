#include <iostream>

using namespace std;

int strange_multiply (int a, int b){
    if (a==0 or b==0) return a+b;
    if (b>a) return strange_multiply (b, a);
    if (b%2==0) return strange_multiply (a, b/2)+strange_multiply (a, b/2);
    return a+strange_multiply (a, (b-1)/2);
}

int main()
{
    int a;
    int b;
    cin >> a >> b;
    cout << strange_multiply (a,b);
    return 0;
}
