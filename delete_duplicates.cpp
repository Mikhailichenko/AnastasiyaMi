#include <iostream>

using namespace std;

int* delete_duplicates (int & n, int*Array){
   int* B=new int[n];
   int d=0;
   for (int i=0; i<n; i++){
     bool f=1;
     for (int r=0; r<d; r++){
        if(Array[i]==B[r]) f=0;
     }
        if(f==1){
            B[d]=Array[i];
        d++;
        }
     }
   n=d;
   int* C=new int[n];
   for (int s=0; s<n; s++){
    C[s]=B[s];
   }
   delete [] Array;
   delete [] B;
   return C;
}

int main()
{
    int n;
    cin >> n;
    int* Array=new int [n];
    for (int i=0; i<n; i++){
      cin >> Array[i];
    }
    Array=delete_duplicates(n, Array);
    for (int i=0; i<n; i++){
        cout << Array[i];
    }
    delete [] Array;
    return 0;
}
