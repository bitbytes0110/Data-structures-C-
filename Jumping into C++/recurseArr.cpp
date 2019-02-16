//power function using recurse
#include <iostream>

using namespace std;

void print(int* arr, int s)
{
    if(s==1)
    {
        cout<<arr[s-1]<<endl;
        return ;
    }
    else
        cout<<arr[s-1]<<endl;
        print(arr,s-1);

}
int main ()
{
    int arr [20];
    for(int i=0 ;i< 20; i++)
    {
        arr[i] = i+1;
    }
    print(arr,20);
}

