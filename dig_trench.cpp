#include <iostream>

using namespace std;

int** dig_trench (int n, int** Trench){
  for (int i=0; i<n; i++){
    for (int r=0; r<n; r++){
        if (i<r) Trench [i] [r]=r-i;
        else Trench [i] [r]=i-r;
    }
  }
  return Trench;
}

int main()
{
    int n;
    cin >> n;
    int** Trench=new int*[n];
    for (int count=0; count<n; count++){
       Trench[count]=new int [n];
    }
    Trench=dig_trench(n, Trench);
    for (int i=0; i<n; i++){
        for (int r=0; r<n; r++){
            cout << Trench [r] [i];
        }
        cout << endl;
    }
    for (int i=0; i<n; i++){
       delete [] Trench [i];
    }
    delete[] Trench;
    return 0;
}
