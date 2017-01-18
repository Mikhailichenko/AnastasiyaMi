#include <iostream>
#include <string>

using namespace std;

void quick_sort (int l,int r, int* T, int* E, int* S){
    int i=l;
    int j=r;
    double x=T[(l+r)/2];
    while (i<=j){
        while (T[i]>x) i++;
        while (x>T[j]) j--;
        if (i<=j){
              int t=S[j];
              int m=T[j];
              S[j]=S[i];
              S[i]=t;
              T[j]=T[i];
              T[i]=m;
              int r=E[j];
              E[j]=E[i];
              E[i]=r;
              i++;
              j--;
        }
    }
    if (i<r) quick_sort(i, r, T, E, S);
    if (l<j) quick_sort(l, j, T, E, S);
}

int shedule(int n){
    int* S=new int[n];
    int* E=new int[n];
    int* T=new int[n];
    int maximum=0;
    for (int i=0; i<n; i++){
         cin >> S[i];
         cin >> E[i];
         if(maximum<E[i])maximum=E[i];
         T[i]=E[i]-S[i];
    }
    quick_sort (0, n, T, E, S);
    bool* table=new bool[maximum];
    for (int i=0; i<maximum; i++)table[i]=0;
    int c=0;
    for (int i=(n-1); -1<i; i--){
        for (int j=(S[i]-1); j<E[i]; j++){
            if(table[j+1]==1) break;
            if((j+1)==E[i]){
                c+=1;
                for (int h=(S[i]-1); h<E[i]; h++) table[h]=1;
            }
        }
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << shedule(n);
    return 0;
}
