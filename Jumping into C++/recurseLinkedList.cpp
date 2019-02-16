//The most intelligent, beautiful, astounding program you ever wrote !
//Way to goo..

//Linked list
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


string largest(llist* myList)
{
    llist* tempList = myList;
    llist* smallestItem = myList;
    llist* newList = NULL;
    llist* previousItem = myList;
    while(tempList!= NULL)
    {

        if(tempList->name >= smallestItem->name)
        {
            smallestItem = tempList;
            previousItem->next = tempList->next;
        }
        previousItem = tempList;
        tempList = tempList->next;
    }
    return smallestItem->name;
}


llist* addItem(llist* myList, string tempName)
{
    llist* newItem = new llist;
    newItem->name = tempName;
    newItem->next = myList;
    myList = newItem;
    cout<<endl<<tempName<<" added"<<endl;

    return myList;
}


llist* deleteList(llist* myList)
{
    myList = NULL;
    return myList;
}



llist* RemoveItem(llist* myList, string tempName)
{
    if(myList != NULL)
    {
        llist* tempList = myList;
        llist* previousItem = myList;
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

                if(tempList->next != NULL)
                    previousItem->next = tempList->next;
                else
                    previousItem->next = NULL;
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

int main()
{
    llist* myList = NULL;
    int choice = 0;
    string tempName;
    cout<<"This is a linked list program"<<endl;
    do
    {
        cout<<"\t\t\t\t\t** Menu **"<<endl;

        cout<<"\t\t\t\t1. Add an item to list"<<endl;
        cout<<"\t\t\t\t2. Remove and item from the list"<<endl;
        cout<<"\t\t\t\t3. Display the list"<<endl;
        cout<<"\t\t\t\t4. Delete list "<<endl;
        cout<<"\t\t\t\t5. Sort List"<<endl;
        cout<<"\t\t\t\t0. Quit"<<endl<<endl;
        choice = getch() - 48;
        switch(choice)
        {
            case 1:
                cout<<"Enter name to be added:";
                getline(cin,tempName);
                myList = addItem(myList,tempName);
                break;
            case 2:
                cout<<"Enter name to be removed:";
                getline(cin,tempName);
                myList = RemoveItem(myList,tempName);
                break;
            case 3:
                displayList(myList);
                break;

            case 4:
                myList = deleteList(myList);
                cout<<"\n\n List deleted !! ";
                break;
            case 5:
                llist* myNewList  = NULL;
                while(myList != NULL)
                {
                    tempName = largest(myList);
                    myNewList = addItem(myNewList,tempName);
                    myList = RemoveItem(myList,tempName);
                }
                cout<<"\n\nThe list is sorted !\n\n";
                myList = myNewList;
                break;

        }
    }
    while(choice != 0);

}

