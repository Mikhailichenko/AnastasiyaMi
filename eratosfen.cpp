#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n<2)
        cout << "numbers not found";
    else
        cout << "2";
    if (n>2)
      for (int i=2; i<n+1; i++){
       for (int r=2; r<i+1; r++){
        if (i%r==0) break;
        if (r==i-1)
        cout << i;
        continue;
       }
      };

    return 0;
}