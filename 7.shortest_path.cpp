#include <iostream>

using namespace std;

int min (int a, int b){
    if (a>b) return b;
    return a;
}

int shortest_path (int N, int M){
    bool** B=new bool* [N+1];
    for (int i=0; i<(N+1); i++) B[i]=new bool [M+1];
    int k;
    cin >> k;
    for (int i=0; i<k; i++){
            int x;
            int y;
            cin >> x >> y;
            B[x][M+1-y]=1;
    }
    int** A= new int* [N+1];
    for (int i=0; i<(N+1); i++) A[i]=new int [M+1];
    A[0][M]=0;
    for (int i=1; i<(N+1); i++) A[i][M]=A[i-1][M]+100;
    for (int i=(M-1); i>-1; i--) A[0][i]=A[0][i+1]+100;
    for (int i=1; i<(N+1); i++){
        for (int r=(M-1); r>-1; r--){
            if (B[i][r]==0) A[i][r]=min((A[i-1][r]+100),min((A[i-1][r+1]+141), (A[i][r+1]+100)));
            else A[i][r]=min((A[i-1][r]+100),(A[i][r+1]+100));
        }
    }
    return A [N] [0];
}

int main()
{
    int N;
    int M;
    cin >> N >> M;
    cout << shortest_path (N, M);
    return 0;
}
