#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef struct node{
    int data;
    node* next;
}node;

class queue{
    node* head;

public:

    queue(int a){
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


int main()
{
	map <string, int> commands;			//list of commands
	commands["queue"]=1;
	commands["end"]=2;
	commands["push"]=3;
	commands["pop"]=4;

	string s;
	queue A(0);					//creating an empty queue
							// this zero will be popped in "queue"-case of input

	do{						//command handler

		cin>>s;

        	int temp;

		switch ( commands[s] ){

			case 1:				// input "queue" - creating the first element of queue:
        						// deleting temporal zero from queue
                		cin>>temp;		// and create first element from input
		                A.pop();
                		A.push(temp);
             			break;

			case 2: 			// input - "end" - ending of inputting
				break;

            		case 3:        			// input "push" - reading element for pushing to queue from input
		                cin>>temp;
                		A.push(temp);
		                break;

            		case 4:   		     	// input "pop" - writing popped from queue element to output
                		cout<<A.pop()<<endl;
                		break;
        	}
  	}
	while (s!="end");

	return 0;
}
