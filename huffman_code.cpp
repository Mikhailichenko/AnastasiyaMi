#include <iostream>
#include <vector>

using namespace std;

void quick_sort (int l,int r, int* a, char* b){
    int i=l;
    int j=r;
    int x=a[(l+r)/2];
    while (i<=j){
        while (a[i]<x) i++;
        while (x<a[j]) j--;
        if (i<=j){
              int t=a[j];
              char T=b[j];
              a[j]=a[i];
              b[j]=b[i];
              a[i]=t;
              b[i]=T;
              i++;
              j--;
        }
    }
    if (i<r) quick_sort(i, r, a, b);
    if (l<j) quick_sort(l, j, a, b);
}

int main()
{
    int n;
    cin >> n;
    char* Arr = new char [n];
    char* Temp = new char [n];
    int* T = new int [n];
    int t=1;
    for (int i=0; i<n; i++){
        cin >> Arr [i];
        if (i==0){
                T[0]=1;
                Temp[0]=Arr[0];
        }
        for (int r=0; r<t; r++){
            if (A[i]==Temp[r]){
                T[r]+=1;
                break;
            }
            if ((r+1)==t){
                Temp[r+1]=A[i];
                T[r+1]=1;
                t+=1;
            }
        }
    }
    char* B = new char [t];
    int* A = new int [t];
    for (int i=0; i<t; i++){
        B[i]=Temp[i];
        A[i]=T[i];
    }
    delete [] Temp;
    delete [] T;
    quick_sort (0, t, A, B);
    bool** Q = new bool* [n];
    for (int i=0; i<t; i++){
            Q[n]=new bool [n-1];
    }
    for (int i=0; i<n; i++){
            Q[i][i]=1;
    }
    for (int i=0; i<n; i++){
        for (int r=0; r<i; r++) Q[i][r]=0;
    }
    return 0;
}
