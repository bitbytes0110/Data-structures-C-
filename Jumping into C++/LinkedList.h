#include <iostream>
#include <string>
#include <conio.h>


using namespace std;


struct llist
{
    //short int rank;
    string name;
    llist* next;
};

llist* addItem(llist* myList)
{
    llist* newItem = new llist;
    string tempName;
    cout<<"Enter name to be added:";
    getline(cin,tempName);
    newItem->name = tempName;
    newItem->next = myList;
    myList = newItem;
    cout<<endl<<tempName<<" added"<<endl;
    return myList;
}


llist* RemoveItem(llist* myList)
{
    if(myList != NULL)
    {
        llist* tempList = myList;
        llist* previousItem = myList;
        string tempName;
        cout<<"Enter name to be removed:";
        getline(cin,tempName);
        if(myList->name == tempName)
        {
            myList = myList->next;
            cout<<endl<<tempName<<" removed"<<endl;
            return myList;
        }
        else
        while(tempList != NULL)
        {
            if(tempList->name == tempName)
            {

                previousItem->next = tempList->next;
                cout<<endl<<tempName<<" removed"<<endl;
                return myList;
            }
            previousItem = tempList;
            tempList = tempList->next;
        }
        cout<<endl<<tempName<<" not found !"<<endl;
        return myList;
    }
    else
    {
        cout<<"List empty !\n Nothing to remove !"<<endl;
        return myList;
    }
}

void displayList(llist* myList)
{
    if( myList ==NULL )
    {
        cout<<"The list is empty !"<<endl;
        return;
    }
    cout<<"The List :\n";
    llist* tempList = myList;
    int index = 1;
    do
    {
        cout<<index<<". "<<tempList->name<<endl;
        index++;
        tempList = tempList->next;
    }while(tempList != NULL);
}

