#include <iostream>

using namespace std;

int main()
{
    for(int q=0; q<10; q++){
       for(int w=0; w<10; w++){
         for(int e=0; e<10; e++){
            for(int p=0; p<10; p++){
            if (((q+w+e)%2)==0) for(int a=0; a<10; a++){
                    for(int s=0; s<10; s++){
                        if (((w+p+a)<22)) for(int r=0; r<10; r++){
                           if ((w+p+a+r)<22) for(int s=0; s<10; s++){
                              if ((w+p+a)<22) for(int y=0; y<10; y++){
                                 if ((w+p+a+y+r)<22) for(int i=0; i<10; i++){
                                     if ((w+p+a+y+r+i)<22) for(int y=0; y<10; y++){
                                        for(int o=0; o<10; o++){
                                            if (((e+o+y+s)%11)==0) for(int u=0; u<10; u++){
                                            for(int t=0; t<10; t++){
                                               if (((p+a+s)%3)!=0) cout << q << w << e << r << t << y << u << i << o << p << a << s << "    " << (w+r+y+i+p+s) << "     " << (e+y+o+s) << "    " << (p+a+s) << endl;
                                            }
                                        }
                                        }
                                     }
                                 }
                              }
                    }
                }
            }
         }
       }
    }
    }
    }
    return 0;
}
