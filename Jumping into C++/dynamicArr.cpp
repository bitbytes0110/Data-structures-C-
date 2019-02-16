#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void display_array(int* p_arr, int s);

int main()
{
    srand(time(NULL));
    int s = 0;
    cout<<"Enter the number of random numbers to generate :"<<endl;
    cin>>s;
    int *p_arr = new int[s];
    for(int i =0;i<s; i++)
    {
        p_arr[i] = 1+(rand()%100);
    }
    display_array(p_arr, s);

}



void display_array(int* p_arr, int s)
{
    cout<<"The generated array :"<<endl;
    for(int i =0;i<s; i++)
    {
        cout<<p_arr[i]<<endl;
    }
}

