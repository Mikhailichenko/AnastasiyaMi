#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef struct node{
    int data;
    node* next;
}node;

class stack{
    node* head;

public:

    stack(int a){
        head=new node;
        head -> data=a;
        head -> next=NULL;
    }

    void push(int a){
        node* temp=new node;
        temp -> data=a;
        temp -> next=head;
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

    ~stack(){
        while(head!=NULL){
            node* temp=head;
            head=head->next;
            delete temp;
        }
    }
};

int main()
{
	map <string, int> commands;			//list of commands
	commands["stack"]=1;
	commands["end"]=2;
	commands["push"]=3;
	commands["pop"]=4;

	string s;
	stack A(0);					//creating an empty stack
							// this zero will be popped in "stack"-case of input

	do{						//command handler

		cin>>s;

        	int temp;

		switch ( commands[s] ){

			case 1:				// input "stack" - creating the first element of stack:
        						// deleting temporal zero from stack
                		cin>>temp;		// and create first element from input
		                A.pop();
                		A.push(temp);
             			break;

			case 2: 			// input - "end" - ending of inputting
				break;

            		case 3:        			// input "push" - reading element for pushing to stack from input
		                cin>>temp;
                		A.push(temp);
		                break;

            		case 4:   		     	// input "pop" - writing popped element to output
                		cout<<A.pop()<<endl;
                		break;
        	}
  	}
	while (s!="end");

	return 0;
}
