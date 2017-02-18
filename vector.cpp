#include <iostream>

using namespace std;

typedef class Vector{

//    int* Array;
    int Size;
    int cap;


public:

    int* Array;

    Vector(int new_size){
        Size=new_size;
        cap=0;
        Array=new int [Size];
    }


    ~Vector(){
        delete [] Array;
    }


    int get_size(){
        return Size;
    }


    int get_cap(){
        return cap;
    }


    void append(int new_size){
        int* t=new int[new_size];
        for(int i=0; i<cap; i++) t[i]=Array[i];
        Size=new_size;
        delete [] Array;
        Array=t;
    }


    void append(){
        int* t=new int[2*Size];
        for(int i=0; i<cap; i++) t[i]=Array[i];
        Size*=2;
        delete [] Array;
        Array=t;
    }


    const int& operator [] (int i) const{
        return Array[i];
    }


    void Push_back(int a){
        if (cap==Size) append();
        Array[cap]=a;
        cap+=1;
    }
}Vector;

int main()
{
    Vector Q(9);
    cout << Q.get_size() << Q.get_cap();
    for(int i=0; i<Q.get_size();i++){
        int a;
        cin >> a;
        Q.Push_back(a);
        cout << Q.Array[i];
    }
    Q.Push_back(3);
    cout << Q.Array[1] << "   .   " << Q.get_size() << "   .   " << Q.get_cap();
    return 0;
}
