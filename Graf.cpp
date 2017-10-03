#include <iostream>

using namespace std;

void adjacency_matrix (int b, int n, int** a){
    bool** A = new bool* [n];
    for (int i=0; i<n; i++) A[i] = new bool[n];
    for (int i=0; i<n; i++){
         for (int r=0; r<n; r++){
            A[i][r]=0;
         }
    }

    for (int i=0; i<n; i++){
        for (int r=0; r<n; i++){
            cout << A[r][i];
            if((r+1)==n) cout << "   " << endl;
        }
    }
    for (int i=0; i<b; i++){
        A[(a[i][0]-1)][(a[i][1]-1)]=1;
        A[(a[i][1]-1)][(a[i][0]-1)]=1;
    }

    for (int i=0; i<n; i++){
        for (int r=0; r<n; i++){
            cout << A[i][r];
            if((r+1)==n) cout << "   " << endl;
        }
    }
    return;
}



void incidence_matrix (int b, int n, int** a){
    bool** A = new bool*[b];
    for (int i=0; i<b; i++) A[i] = new bool[n];
    for (int i=0; i<b; i++){
        for (int r=0; r<n; r++) A[i][r]=0;
    }
    for (int i=0; i<b; i++){
        A[i][((a[b][0])-1)]=1;
        A[i][((a[b][1])-1)]=1;
    }
    for (int i=0; i<b; i++){
        for (int r=0; r<n; i++){
            cout << A[i][r];
            if((r+1)==n) cout << "   " << endl;
        }
    }
    return;
}

int main()
{
    int b;
    cin >> b;
    int n;
    cin >> n;
    int** a = new int*[b];
    for (int i=0; i<b; i++) a[i] = new int[2];
    for (int i=0; i<b; i++){
            cin >> a[i][0];
            cin >> a[i][1];
    }
    adjacency_matrix(b, n, a);
    incidence_matrix(b, n, a);
    return 0;
}
