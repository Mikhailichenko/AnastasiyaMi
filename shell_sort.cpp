#include <iostream>

using namespace std;


void Shell_sort(int* A, int n, int b){
    for (int i=0; i<b; i++){
    for (int r=i; (r+((n+1)/2))<b; r+=((n+1)/2)){
        if(A[r]>A[(r+((n+1)/2))]){
              int t=A[r+((n+1)/2)];
              A[r+((n+1)/2)]=A[r];
              A[r]=t;
        }
    }
    }
    if (n!=1) Shell_sort(A, n/2, b);
    return;
}


int main()
{
    int n;
    cin >> n;
    int* A = new int [n];
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    Shell_sort(A, n, n);
    for (int i=0; i<n; i++){
        cout << A[i] << "    ,,,    ";
    }
    delete [] A;
    return 0;
}
