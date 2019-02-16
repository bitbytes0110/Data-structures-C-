
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

struct contact
{
    string name;
    float last_called;
};

void display_array(int* p_arr, int s);
contact* extend_arr(contact* p_arr, int* s);



int main()
{
    srand(time(NULL));
    int s = 5;
    int nof =0;

    contact* recentList = new contact[s];
    string tempName;
    int tempLastCalled;

    cout<<"Enter names : "<<endl;
    cin>>tempName;
    tempLastCalled = rand()%10;
    do
    {
        nof++;
        if(nof== s)
        {
            recentList= extend_arr(recentList, &s);
        }
        recentList[nof].name = tempName;
        recentList[nof].last_called = tempLastCalled;
        cin>>tempName;
        tempLastCalled = rand()%10;
    }while(tempName!="end");

    cout<<endl<<"Memory used : " <<s;
}

contact* extend_arr(contact* p_arr, int* s)
{
    *s = (*s) +10;
    contact *p_narr = new contact[*s];
    for(int i = 0 ; i<*s; i++)
    {
        p_narr[i] = p_arr[i];
    }

    delete[] p_arr;
    return p_narr;
}

void display_array(int* p_arr, int s)
{
    cout<<"The generated array :"<<endl;
    for(int i =0;i<s; i++)
    {
        cout<<p_arr[i]<<endl;
    }
}
