#include <iostream>

using namespace std;

typedef class string{
    int n;
    char* A;

public:


    string (int a){
        n=a;
        A=new char [n];
    }

    ~ string (){
        delete [] A;
    }

    int get_n(){
        return n;
    }

    int get(int i){
        return A[i];
    }


    void set(int i, char x){
        A[i]=x;
    }

    void print(){
        cout << A;
    }

    bool find(string s){
        if (n<s.n) return 0;
        for(int i=0; i<(n-s.get_n()+1); i++){
            for(int r=0; r<s.get_n(); r++){
                if(A[i]==s.A[r]){
                    for(int q=1; q<s.get_n(); q++){
                        if(A[i+q]!=s.A[r+q]) break;
                        if((q+1)==s.get_n()) return 1;
                    }
                }
            }
        }
    }

}string;


int main()
{

    return 0;
}
