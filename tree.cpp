#include <iostream>
#include <queue>

using namespace std;


typedef struct Node{
    int data;
    Node* left=NULL;
    Node* right=NULL;
}Node;



class BinTree{
    Node* root;

public:

    Node* get_root(){
        return root;
    }

    BinTree(int a){
        Node* temp=new Node;
        temp->data=a;
        root=temp;
    }

    void deleteTree(Node* n){
        if(n==NULL) return;
        deleteTree(n->left);
        deleteTree(n->right);
        delete n;
    }

    ~BinTree(){
        deleteTree(root);
    }

    bool DFS(int a, Node* n){
        if (n==NULL) return 0;
        if (n->data==a) return 1;
        if (DFS(a, n->left)==1)return 1;
        if (DFS(a, n->right)==1) return 1;
        return 0;
    }

    bool BFS(int a, Node* n){
        queue <Node*> A;
        A.push(n);
        while(!A.empty()){
            Node* temp=A.front();
            A.pop();
            if (temp->data==a) return 1;
            if (temp->left!=NULL) A.push(temp->left);
            if (temp->right!=NULL) A.push(temp->right);
        }
        return 0;
    }

    void Insert(int a){
        queue <Node*> A;
        A.push(root);
        Node* t;
        while(!A.empty()){
            Node* temp=A.front();
            A.pop();
            if (temp->left!=NULL) A.push(temp->left);
            if (temp->right!=NULL) A.push(temp->right);
            if ((temp->right==NULL)||(temp->left==NULL)){
                t=temp;
                break;
            }
        }
        if(t->left==NULL){
            Node* temp=new Node;
            temp->data=a;
            t->left=temp;
            return;
        }
        if(t->right==NULL){
            Node* temp=new Node;
            temp->data=a;
            t->right=temp;
        }
    }
};


int main()
{
    BinTree D(1);
    D.Insert(2);
    D.Insert(3);
    D.Insert(4);
    D.Insert(5);
    D.Insert(6);
    if(D.BFS(3, D.get_root())==1) cout << "  r  ";
    if(D.DFS(4, D.get_root())==1) cout << "  j  ";
    if(D.DFS(9, D.get_root())==0) cout << "  k  ";
    if(D.BFS(7, D.get_root())==0) cout << "  n  ";
    return 0;
}
