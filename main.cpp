#include <iostream>

using namespace std;

int main()
{
    int c, d;
    cout << "Right two integers" << endl;
    cin >> c;
    cin >> d;
    int a=c;
    int b=d;
    while (a<b or a>b) {
        if (a>b) {
            a=a-b;
            }
        else {
            b=b-a;
        };
    };
    int nok=d*c/a;
    cout << "The least common multiple is ";
    cout << nok;
    return 0;
}
