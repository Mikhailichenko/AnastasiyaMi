#include <iostream>

using namespace std;

typedef struct edge{
    int a;
    int b;
    int cost;
}edge;

int Min(int a, int b){
    if (a<b) return a;
    return b;
}

void solvel(int V, int E, int* d, edge*e){
        for (int j=0; j<E; j++){
            if((d[e[j].a]<1000)&&(d[e[j].a]>0)){
                d[e[j].b]=Min(d[e[j].b],(d[e[j].a]+e[j].cost));
            }
        }
    return;
}

int main()
{
    int V;
    cin >> V;
    int E;
    cin >> E;
    edge* e = new edge [E];
    for (int i=0; i<E; i++){
        cin >> e[i].a >> e[i].b >> e[i].cost;
    }
    int* d= new int [V];
    d[0]=0;
    for (int i=1; i<V; i++){
            d[i]=1000;
    }
    return 0;
}
