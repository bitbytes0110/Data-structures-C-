//Another splendid program!
//power function using recurse
#include <iostream>

using namespace std;

int findInArray(int* arr, int s,int e, int f)
{
    if(s+1==e)
        return -1;
    if(f == arr[s] || f == arr[e] || f == arr[s+((e-s)/2)]  )
    {
        return 1;
    }
    else if(f > arr[s+((e-s)/2)] )
    {
        s = s+ ((e-s)/2);
        findInArray(arr,s,e,f);
    }
    else if(f < arr[s+((e-s)/2)] )
    {
        e = s + ((e-s)/2);
        findInArray(arr,s,e,f);
    }


}
int main ()
{
    int arr [20];
    for(int i=0 ;i< 20; i++)
    {
        arr[i] = (i+1)*10;
    }

    if( findInArray(arr,0, 9, 100) == -1 )
        cout<<"Sorry da.. Element not found !"<<endl;
    else
        cout<<"Voila !! Element found !"<<endl;

}
