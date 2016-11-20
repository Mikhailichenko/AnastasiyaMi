#include <iostream>

using namespace std;

int** built_ziggart(int n, int** Ziggurat){
  for (int t=1; t<(n+3)/2; t++){
        for (int i=(t-1); i<(n+1-t); i++){
          for (int r=(t-1); r<(n+1-t); r++){
           Ziggurat [r] [i]=t;
         }
     }
  }
  return Ziggurat;
}

int main()
{
 int n;
 cin >> n;
   int **Ziggurat = new int*[n];
    for (int i=0; i<n; i++){
       Ziggurat[i] = new int[n];
    }
  Ziggurat=built_ziggart(n, Ziggurat);
  for (int i=0; i<n; i++){
    for (int r=0; r<n; r++){
        cout << Ziggurat [r] [i];
    }
    cout << endl;
  }
  for (int i=0; i<n; i++){
    delete[] Ziggurat[i];
  }
  delete[] Ziggurat;
 return 0;
}
