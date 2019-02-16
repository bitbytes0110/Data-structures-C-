#include <iostream>
#include <conio.h>

using namespace std;

struct node
{
    int key;
    node* nLeft;
    node* nRight;
};

node* searchNode(node* myNode, int key)
{
    if(myNode==NULL)
        return NULL;
    else if(myNode->key==key)
        return myNode;
    else if( key < myNode->key)
        return searchNode(myNode->nLeft, key);
    else if( key > myNode->key)
        return searchNode(myNode->nRight, key);


}

void deleteTree(node* myNode)
{
    if(myNode!=NULL)
    {
        deleteTree(myNode->nLeft);
        deleteTree(myNode->nRight);
        delete myNode;
    }


}
node* insertNode(node* myNode, int key)
{
    if(myNode==NULL)
    {
        node* newNode = new node;
        newNode->key = key;
        newNode->nLeft= NULL;
        newNode->nRight= NULL;
        cout<<"\nElement inserted !\n";
        return newNode;
    }
    else if(key < myNode->key)
        myNode->nLeft = insertNode(myNode->nLeft, key );
    else if(key > myNode->key)
        myNode->nRight= insertNode(myNode->nRight, key );
    return myNode;

}
int main ()
{
    int ch, key;
    node* myNode = NULL;
    do
    {

        cout<<"\n\t\t** Menu **\n";
        cout<<"1. Insert into Binary tree\n";
        cout<<"2. Search for values \n";
        cout<<"3. Delete tree\n";
        cout<<"0. Quit\n\n";
        ch = getch() - 48;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter the element to insert :";
                cin>>key;
                myNode = insertNode(myNode, key);
                break;
            case 2:
                cout<<"\nEnter the element to search:";
                cin>>key;
                if(searchNode(myNode, key))
                    cout<<"\nVoila .. Element found";
                else
                    cout<<"\n404 Element not found !!";
                break;
            case 3:
                deleteTree(myNode);
                cout<<"\nTree deleted !";
                break;
        }
    }while(ch!=0);
}
