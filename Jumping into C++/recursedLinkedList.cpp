#include <iostream>
#include <conio.h>

using namespace std;

struct node
{
int key;
node* next;
};

int ch =0;
int key;
node* myNode  = NULL;
node* previousNode = NULL;

node* addNode(node* myNode, int key)
{
    node* newNode =new node;
    newNode->key = key;
    newNode->next= myNode;
    myNode = newNode;
    return myNode;

}

void displayNode(node* myNode)
{
    if(myNode != NULL)
    {
        cout<<myNode->key<<endl;
        displayNode(myNode->next);
    }
}

void removeNode(node* previousNode, node* myNode, int target)
{

    if(myNode->key == target)
    {
        previousNode->next = myNode->next;
        cout<<"Node to be removed found.. nextt !\n"<<endl;
        return;
    }

    previousNode = myNode;
    removeNode(previousNode, myNode->next, target);
}


int main()
{
    do
    {
    cout<<"\n\t** Menu **"<<endl;
    cout<<"\t\t1. Add element"<<endl;
    cout<<"\t\t2. Remove element"<<endl;
    cout<<"\t\t3. Display List"<<endl;
    cout<<"\t\t0. Quit"<<endl<<endl;

    ch = (int)getch()-48;
    switch(ch)
    {
        case 1:

            cout<<"Enter value to be added :"<<endl;
            cin>>key;
            myNode = addNode(myNode, key);
            cout<<"Element added to linked list !\n";
            break;
        case 2:
            cout<<"\nEnter item to be be removed :";
            cin>>key;
            removeNode(previousNode, myNode, key);
            break;
        case 3:
            cout<<"\nLinked List  :\n";
            displayNode(myNode);

            break;
    }
    }while(ch!=0);
}
