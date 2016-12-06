#include <iostream>
#include <string>

using namespace std;

void quick_sort (int l,int r, double* a){
    int i=l;
    int j=r;
    double x=a[(l+r)/2];
    while (i<=j){
        while (a[i]<x) i++;
        while (x<a[j]) j--;
        if (i<=j){
              double t=a[j];
              a[j]=a[i];
              a[i]=t;
              i++;
              j--;
        }
    }
    if (i<r) quick_sort(i, r, a);
    if (l<j) quick_sort(l, j, a);
}

void quick_sortl (int n, double* a){
     quick_sort (0, n-1, a);
     for (int i=0; i<(n)/2; i++){
        double t=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=t;
     }
}



int main()
{
    int n;
    cin >> n;
    double* a = new double[n];
    for (int i=0; i<n; i++) cin >> a[i];
    quick_sortl (n, a);
    for (int i=0; i<n; i++) cout << a [i];
    delete [] a;
    return 0;
}
