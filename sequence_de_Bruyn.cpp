#include <iostream>

using namespace std;

int binpow (int a, int n){
   if (n<0) return 1/binpow(a, -n);
   if (n==0) return 1;
   if (n%2==0) return binpow(a, n/2)*binpow(a, n/2);
   return a*binpow(a, (n-1)/2);

}

int deg (int** M, int N, int a){
    int t=0;
    for (int i=0; i<N; i++){
        if (M[a][i]==0) t+=1;
    }
    int b=(N-t);
    return b;
}

typedef struct node{
    int data;
    node* next;
}node;


class queue{
public:
    node* head;

    queue(int a){
        head=new node;
        head->data=a;
        head->next=NULL;
    }

    void push(int a){
        node* temp=new node;
        temp->data=a;
        temp->next=head;
        head=temp;
        return;
    }

    void push_after_p(node* p, int a){
        node* temp=new node;
        temp->data=a;
        temp->next=p->next;
        p->next=temp;
        return;
    }

    int pop(){
        node* temp=head;
        if (temp->next==NULL){
                int a=temp->next->data;
                delete temp;
                return a;
        }
        while(temp->next->next!=NULL) temp=temp->next;
        int a=temp->next->data;
        delete temp->next;
        temp->next=NULL;
        return a;
    }

    ~queue(){
        while(head!=NULL){
            node* temp=head;
            head=head->next;
            delete temp;
        }
    }
};

int* E_cycle(int** M, int N, int n){
	queue A(0);
	node*p=A.head;
	while(p!=NULL){
        if(deg(M,N, p->data)==0){
            p=p->next;
            continue;
        }
	}
	int q=p->data;
	node* r=p;
	do{
        for(int i=0; i<N; i++){
            if(M[q][i]==1){
                A.push_after_p(r, i);
                r=r->next;
                M[q][i]=0;
                M[i][q]=0;
                q=i;
                break;
            }
        }
	}
	while(q!=p->data);
	int* Ec=new int [N*n];
	for(int i=0; i<(N*n); i++){
        Ec[i]=A.pop();
	}
	return Ec;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int N=binpow(n, (k-1));
    int** M= new int* [N];
    for (int i=0; i<N; i++){
       M[i] = new int[N];
    }
    for (int i=0; i<N; i++){
        for (int r=0; r<N; r++) M[i][r]=0;
    }
    for (int i=0; i<N; i++){
        int c=i-((i/(N/n)*(N/n)));
        for (int r=0; r<n; n++){
            M[i][c*n+r]=1;
            M[(c*n)+r][i]=-1;
        }
    }
    int* EC= new int [(N*n)+1];
    EC=E_cycle(M, N, n);
    int* DB=new int [N*n];
    for (int i=0; i<(N*n); i++)DB[i]=EC[i]%n;
    for (int i=0; i<(N*n); i++) cout << DB[i];
    delete [] M;
    delete [] DB;
    delete [] EC;
    return 0;
}
