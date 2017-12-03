#include <iostream>

using namespace std;

bool try_Khun(int v, bool* used, bool** Ms, int n, int* mt){
    if(used[v]==1) return 0;
    used[v]=1;
    for(int i=0; i<n; i++){
        if (Ms[v][i]==1){
            int t=i;
            if((mt[t]==-1)||(try_Khun(mt[t], used, Ms, n, mt)==1)){
                  mt[t]=v;
                  return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    bool* used = new bool [n];
    for (int i=0; i<n; i++){
        used[i]=0;
    }
    bool** Ms = new bool* [n];
    for (int i=0; i<n; i++){
        Ms[i] = new bool [n];
    }
    for (int i=0; i<k; i++){
        int t;
        int T;
        cin >> t >> T;
        Ms[t][T]=1;
        Ms[T][t]=1;
    }
    int* mt = new int [n];
    for (int i=0; i<n; i++){
        mt[i]=-1;
    }
    cout << try_Khun(0, used, Ms, n, mt);
    return 0;
}
