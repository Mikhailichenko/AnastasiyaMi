#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node* next;
}node;

class list{
    node* head;

public:

    list(int a){
        head=new node;
        head -> data=a;
        head -> next=NULL;
    }

    ~list(){
        while(head!=NULL){
            node* temp=head;
            head=head->next;
            delete temp;
    }

    void push_head(int a){
        node* temp=new node;
        temp -> data=a;
        temp -> next=head;
        head=temp;
    }

    void push_back(int a){
        node* temp=new node;
        node* t=head;
        while(t->next!=NULL) t=t->next;
        t->next=temp;
        temp -> data=a;
        temp -> next=NULL;
        head=temp;
    }

    int pop(){
        node* temp=head;
        if(temp->next==NULL){
                int a=temp->data;
                delete temp;
                return a;
        }
        head=temp->next;
        int a=temp->data;
        delete temp;
        return a;
    }

    bool push_data(int a, int data){
        node* t;
        while(t->next!=NULL) {
                if(t->data==a){
                    node* temp=new node;
                    temp->data=a;
                    temp->next=t->next;
                    t->next=temp;
                    return 1;
                }
                t=t->next;
        }

        if(t->data==a){
                node* temp=new node;
                temp->data=a;
                temp->next=t->next;
                t->next=temp;
                return 1;
        }
        return 0;
    }

    int get(int i){
        if(i<1)return 0;
        node* temp=head;
        for(int s=0;s<i; i++){
            if(temp->next==NULL){
                    if((s+1)==i)return temp->data;
                    return 0;
            }
            temp=temp->next;
        }
        return temp->data;
    }

    void set(int i, int a){
        if(i<1)return 0;
        node* temp=head;
        for(int s=1;s<i; i++){
            if(temp->next==NULL) return 0;
            temp=temp->next;
        }
        temp->data=a;
    }
};

int main()
{
    cout <<"a";
    return 0;
}
