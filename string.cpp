#include <iostream>

using namespace std;

typedef class sstring{
    int n;
    char* A;

public:


    sstring (int a){
        n=a;
        A=new char [n];
    }

    ~ sstring (){
        delete [] A;
    }

    char get_n(){
        return n;
    }

    char get(int i){
        return A[i];
    }


    void set(int i, char x){
        A[i]=x;
    }

    void print(){
        cout << A;
    }

    bool find(sstring s){
        if (n<s.n) return 0;
        for(int i=0; i<(n-s.get_n()+1); i++){
            for(int r=0; r<s.get_n(); r++){
                if(A[i]==s.get(r)){
                    for(int q=1; q<s.get_n(); q++){
                        if(A[i+q]!=s.get(r+q)) break;
                        if((q+1)==s.get_n()) return 1;
                    }
                }
            }
        }
        return 0;
    }

}sstring;


int main()
{
    sstring W(6);
    sstring B(4);
    sstring C(7);
    for(int i=0; i<6; i++){
            char t;
            cin >> t;
            W.set(i, t);
        }
    W.print();
    for(int i=0; i<4; i++){
            char t;
            cin >> t;
            B.set(i, t);
    }
    for(int i=0; i<7; i++){
            char t;
            cin >> t;
            C.set(i, t);
    }
    if(W.find(B)==1) cout << "123" << "  .  ";
    if(W.find(C)==0) cout << "456" << "  .  ";
    cout << W.get(1);
    return 0;
}
