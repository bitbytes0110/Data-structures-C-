// Dynamically adding memory into programs !!
// Really beautiful programming logic.. please check out !


#include <iostream>

using namespace std;

void display_array(int* p_arr, int s);
int* extend_arr(int* p_arr, int* s);


int main()
{
    int val, s = 10;
    int nof =0;
    int* p_arr = new int[s];
    cout<<"Enter values ( 0 to exit ): ";
    cin>>val;
    do
    {
        nof++;
        if(nof== s)
        {
               p_arr = extend_arr(p_arr, &s);
        }
        p_arr[nof] = val;
        cin>>val;
    }while(val>0);

    cout<<"Memory used : " <<s;
}

int* extend_arr(int* p_arr, int* s)
{
    *s = (*s) +10;
    int *p_narr = new int[*s];
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



